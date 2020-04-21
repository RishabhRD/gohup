#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void handleSignals();
void execProgram(char** argv);
void usage();
void parseArguments(int argc,char** argv);

#define VERSION 0.1

#define EXIT_PROG 126
#define EXIT_HUP 127

int main(int argc,char** argv){
	parseArguments(argc,argv);
	handleSignals();
	execProgram(argv);
}

void handleSignals(){
	signal(SIGHUP,SIG_IGN);
	signal(SIGINT,SIG_IGN);
}
void execProgram(char** argv){
	int pid = fork();
	if(pid==-1){
		perror("GOHUP");
		_exit(EXIT_HUP);
	}else if(pid == 0){
		int devNull = open("/dev/null",STDOUT_FILENO);
		if(devNull == -1 ){
			perror("GOHUP");
			_exit(EXIT_HUP);
		}
		if(dup2(devNull,STDOUT_FILENO) == -1){
			perror("GOHUP");
			_exit(EXIT_HUP);
		}
		if(devNull > STDERR_FILENO)
			close(devNull);
		if(dup2(STDOUT_FILENO,STDERR_FILENO) == -1){
			perror("GOHUP");
			_exit(EXIT_HUP);
		}
		if(execvp(argv[1],&argv[1]) == -1){
			int exit_status = (errno == ENOENT) ? EXIT_HUP : EXIT_PROG;
			_exit(exit_status);
		}
	}else{
		printf("[%d]\n",pid);
		_exit(0);
	}
}
void usage(){
	printf("gohup: missing operand\n");
	printf("Try gohup --help for more information\n");
}
void parseArguments(int argc,char** argv){
	if(argc < 2){
		usage();
		_exit(EXIT_HUP);
	}
	if(strcmp(argv[1],"--help")==0){
		printf("Usage: nohup COMMAND [ARG]...\n");
		printf("   or: nohup OPTION\n");
		printf("Run COMMAND, ignoring hangup signals.\n\n");
		printf("\t--help       display this help and exit\n");
		printf("\t--version    output version information and exit\n\n");
		_exit(0);
	}
	if(strcmp(argv[1],"--version")==0){
		printf("gohup %.2f\n\n",VERSION);
		printf("License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\n");
		printf("This is free software: you are free to change and redistribute it.\n");
		printf("There is NO WARRANTY, to the extent permitted by law.\n\n");
		printf("Written by Rishabh Dwivedi.\n");
		_exit(0);
	}
	if(strlen(argv[1])>=2 && argv[1][0]=='-' && argv[1][1]=='-'){
		printf("gohup: unrecognized option \'%s\'\n",argv[1]);
		printf("Try \'nohup --help\' for more information.\n");
		_exit(EXIT_HUP);
	}
}

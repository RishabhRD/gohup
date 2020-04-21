CC=gcc
all: gohup.c
	$(CC) -o gohup gohup.c
copy:
	cp gohup /usr/bin/gohup
	cp gohup.1 /usr/local/man/man1/gohup.1
install: all copy
clean:
	if [ -f gohup ] ; \
	then \
	rm gohup ; \
	fi;
	if [ -f /usr/bin/gohup ] ; \
	then \
	rm /usr/bin/gohup ; \
	fi;

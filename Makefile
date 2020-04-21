CC=gcc
all: gohup.c
	$(CC) -o gohup gohup.c
copy:
	cp gohup /usr/bin/gohup
install: all copy
clean:
	rm *.o gohup
	rm /usr/bin/gohup

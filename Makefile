CC=gcc
all: gohup.c
	$(CC) -o gohup gohup.c
copy:
	cp gohup /usr/bin/gohup
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

CC=gcc
all: gohup.c
	$(CC) -o gohup gohup.c
copy:
	cp gohup /usr/bin/gohup
install: all copy
	mkdir -p /usr/local/man
	cp gohup.1 /usr/local/man/man1/gohup.1
	chmod 644 /usr/local/man/man1/gohup.1
clean:
	if [ -f gohup ] ; \
	then \
	rm gohup ; \
	fi;
	if [ -f /usr/bin/gohup ] ; \
	then \
	rm /usr/bin/gohup ; \
	fi;

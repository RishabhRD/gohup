include config.mk

CC=gcc
all: gohup.c
	$(CC) -o gohup gohup.c
install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f gohup $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/gohup
	mkdir -p $(DESTDIR)$(PREFIX)/man1
	sed "s/VERSION/$(VERSION)/g" < gohup.1 > $(DESTDIR)$(MANPREFIX)/man1/gohup.1
	chmod 644 $(DESTDIR)$(MANPREFIX)/man1/gohup.1
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/gohup\
		$(DESTDIR)$(MANPREFIX)/man1/gohup
clean:
	if [ -f gohup ] ; \
	then \
	rm gohup ; \
	fi;
	if [ -f /usr/bin/gohup ] ; \
	then \
	rm /usr/bin/gohup ; \
	fi;

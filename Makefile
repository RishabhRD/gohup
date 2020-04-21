all:
	gcc gohup.c -o gohup
install:
	gcc gohup.c -o gohup
	cp gohup /usr/bin/
clean:
	rm gohup
	rm /usr/bin/gohup

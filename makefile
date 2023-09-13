all:	oss worker

oss:	oss.c
	gcc -o oss oss.c

worker:	worker.c
	gcc -o worker worker.c

clean:
	rm -f oss worker


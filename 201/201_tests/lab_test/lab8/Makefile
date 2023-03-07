qsort:qsort.o quicksort.o
	gcc -Wall -std=c99 quicksort.o qsort.o -o qsort
qsort.o:qsort.c
	gcc -Wall -std=c99 -c qsort.c
quicksort.o:quicksort.c quicksort.h
	gcc -Wall -std=c99 -c quicksort.c

clean:
	rm -rf *.o qsort core

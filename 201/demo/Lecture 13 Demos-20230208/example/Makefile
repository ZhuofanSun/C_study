test: example.o test.o
	gcc -Wall -std=c99 -o test example.o test.o

test.o: test.c example.h
	gcc -Wall -std=c99 -c test.c

example.o: example.c example.h
	gcc -Wall -std=c99 -c example.c

clean: 
	rm -f test *.o


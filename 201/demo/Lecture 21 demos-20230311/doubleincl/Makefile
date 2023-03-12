prog: prog.o calc.o
	gcc -Wall -std=c99 -o prog prog.o calc.o

prog.o: coordinates.h calc.h prog.c
	gcc -Wall -std=c99 -c prog.c

calc.o: calc.h calc.c coordinates.h
	gcc -Wall -std=c99 -c calc.c

clean:
	rm -f *.o
	rm -f prog

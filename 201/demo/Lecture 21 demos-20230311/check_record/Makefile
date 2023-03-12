check_record: check_record.o driving_record.o legal_record.o
	gcc -Wall -std=c99 -o check_record check_record.o driving_record.o legal_record.o

check_record.o: check_record.c age.h driving_record.h legal_record.h
	gcc -Wall -std=c99 -c check_record.c

driving_record.o: age.h driving_record.h driving_record.c
	gcc -Wall -std=c99 -c driving_record.c

legal_record.o: age.h legal_record.h legal_record.c
	gcc -Wall -std=c99 -c legal_record.c

clean:
	rm -rf *.o
	rm -rf check_record

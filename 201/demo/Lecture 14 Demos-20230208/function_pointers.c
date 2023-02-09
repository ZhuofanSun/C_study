#include <stdio.h>

void decompose(double x, long *i, double *f);

int main(void){
	double x = 10.34;
	long int_part;
	double frac_part;
	decompose(x, &int_part, &frac_part);
	//int_prt and frac_prt now have new values

	return 0;
}

void decompose(double x, long *i, double *f) {
	*i = (long) x;
	*f = x - *i;
}

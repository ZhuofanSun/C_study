#include <stdio.h>

#define N 5

int main(void) {
	int a[N] = {0};
	int i;

	for (i = 0; i < N; i++)
		a[i] = 5;

	for (i = 0; i < N; i++)
		a[i] = 100;

	return 0;
}

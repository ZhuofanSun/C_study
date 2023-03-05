#include <stdio.h>

int array_max(int a[], int n);

int main(void) {
	int a[5] = {4, -1, 8, 11, 5};
	int max;

	max = array_max(a, 5);

	printf("Max element: %d\n", max);

	return 0;
}

int array_max(int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}

	return max;
}

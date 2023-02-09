#include <stdio.h>

int main(){

	int rows, columns;

	printf("Enter num of rows: ");
	scanf("%d", &rows);

	printf("Enter num of columns: ");
	scanf("%d", &columns);

	int ages[rows][columns];

	for (int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			ages[i][j] = i + j;

	for (int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++)
			printf("%d\t", ages[i][j]);

		printf("\n");
	}

	return 0;
}
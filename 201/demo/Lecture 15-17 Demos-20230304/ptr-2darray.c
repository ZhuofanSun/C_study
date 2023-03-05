#include <stdio.h>

#define NUM_ROWS 4
#define NUM_COLS 5

void print2Darray(int array[][NUM_COLS]){
	for(int i = 0 ; i < NUM_ROWS; i++){
		for (int j = 0; j < NUM_COLS; j++)
			printf("%d\t", array[i][j]);

		printf("\n");
	}

}


int main(){

	int array[NUM_ROWS][NUM_COLS] = {{0}};

	printf("Initial array:\n");
	print2Darray(array);

	//set all elements in row 1 to 10
	for(int *p = array[1]; p < array[2]; p++)
		*p = 10;

	printf("Array after setting all elements in row 1 to 10:\n");
	print2Darray(array);

	//set all elements in row 0 to 4
	for(int *p = array[0]; p < array[0] + NUM_COLS; p++)
		*p = 4;

	printf("Array after setting all elements in row 0 to 4:\n");
	print2Darray(array);

	//set all elements in row 2 to 20
	for(int *p = *(array + 2); p < *(array + 3); p++)
		*p = 20;

	printf("Array after setting all elements in row 2 to 20:\n");
	print2Darray(array);

	//set all elements in column 1 to 8
	for (int (*p)[NUM_COLS] = array; p < array + NUM_ROWS; p++)
		(*p)[1] = 8;

	printf("Array after setting all elements in column 1 to 8:\n");
	print2Darray(array);

	//set all elements in column 2 to 2
	for (int (*p)[NUM_COLS] = array; p < array + NUM_ROWS; p++)
		*(*p + 2) = 2;

	printf("Array after setting all elements in column 2 to 2:\n");
	print2Darray(array);

	//set all elements in column 3 to 0
	for (int *p = *array + 3; p < *array + NUM_COLS*NUM_ROWS; p += NUM_COLS)
		*p = 0;

	printf("Array after setting all elements in column 3 to 0:\n");
	print2Darray(array);

	return 0;
}

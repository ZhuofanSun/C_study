#include <stdio.h>

#define LEN 10

int sum_two_dimensional_array(int a[][LEN], int n){
    int i, j, k, sum = 0, total_num = n*LEN;  // no. of number, outer pointer, inner pointer
    for (i = 0; i < total_num; ++i) {
        j = i / LEN;  // [0, inf] add by one every LEN
        k = i % LEN;  // [0, LEN-1]
        sum += *(*(a + j) + k);  // 2 pointers int 2 dimensions
    }
    return sum;
}

int main(){
	//int numbers[2][LEN] = {{1,2,3,4,5,6,7,8,9,10},
	//			{2,3,4,5,6,7,8,9,10,11}};

	//printf("The sum of all elements of the array is: %d\n", sum_two_dimensional_array(numbers, 2));
    int a = 0, b = 1;
    a = &b;

	return 0;
}
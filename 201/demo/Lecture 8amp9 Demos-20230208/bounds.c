/* Array subscript out of range example */

#include <stdio.h>

#define N 10

int main(void){

    int a[N], i;

    for(i = 1; i <= 2*N; i++){
        a[i] = 0;
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}

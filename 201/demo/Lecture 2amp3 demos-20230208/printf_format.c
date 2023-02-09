/* demo conversion specifier checks */

#include <stdio.h>

int main(void){
    int i = 30, j = 90;

    printf("Value of i and j are: %d, %d\n", i);
    printf("Value of i is:%d\n", i, j);

    return 0;
}

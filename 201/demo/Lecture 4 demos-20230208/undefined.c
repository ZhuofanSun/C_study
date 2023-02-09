/* Some behavior might be undefined (Slide 16) */

#include <stdio.h>

int main(void){

    int i = 5, j = 4, k;
    k = (j = i++) + (i = 1);

    printf("Value of k is %d\n", k);

    return 0;
}

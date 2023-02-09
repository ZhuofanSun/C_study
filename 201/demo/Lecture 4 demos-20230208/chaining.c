/* Demonstrates chaining of assignments */

#include <stdio.h>

int main (void){
    int i;
    float f;

    i = 72.99f;

    printf("Value of i is:%d\n", i);

    f = 136;

    printf("Value of f is:%f\n", f);

    f = i = 33.3f;

    printf("Value of i after chaining is %d and f is %f\n", i, f);

    return 0;
}

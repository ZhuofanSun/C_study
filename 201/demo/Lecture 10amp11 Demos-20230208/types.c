#include <stdio.h>

#define BOOL int
typedef int Bool;

int main(void){

    BOOL flag = 0;
    Bool flag2 = 1;

    printf("value of flag defined through #define is %d and value of flag2 defined through a typedef is: %d \n", flag, flag2);

    printf("Size of an int is: %zu, size of a float is: %zu, size of a double is: %zu\n", sizeof(int), sizeof(float), sizeof(double));

    printf("Size of 100 is: %zu, size of 100.578f is: %zu, size of 100.578 is: %zu\n",  sizeof(100), sizeof(100.578f), sizeof(100.57));

    return 0;
}

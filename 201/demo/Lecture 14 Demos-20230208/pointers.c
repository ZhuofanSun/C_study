#include <stdio.h>

int main(void) {
    int a = 5;
    printf("a = %d\n", a);

    int *ptr = &a;

    printf("ptr = %x\n", ptr);

    *ptr = 100;
    printf("After assignment...\n");

    printf("a = %d\n", a);

    printf("ptr = %x\n", ptr);

    printf("*ptr = %d\n", *ptr);

    printf("&a = %x\n", &a);

    printf("&ptr = %x\n", &ptr);

    return 0;
}
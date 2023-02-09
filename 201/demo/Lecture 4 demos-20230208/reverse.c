#include <stdio.h>

int main (void){
    
    int input;
    int first, second;

    printf("Enter two-digit number:");
    scanf("%d", &input);

    first = input / 10;
    second = input % 10;

    printf("Your number is:%d%d\n", second, first);

    return 0;
}


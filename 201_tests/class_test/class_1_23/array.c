#include <stdio.h>

#define SIZE 10

int main (void){
    
    int a[SIZE];

    printf("Values in unitialized array:\n");
    printf("==================\n");

    for(int i=0; i < SIZE; i++)
        printf("a[%d]=%d\n", i, a[i]);

    int b[SIZE] = {[1]=1, [3]=3, [5]=5, [7]=7, [9]=9};

    printf("Values after using designated initializers:\n");
    printf("==================\n");

    for(int i=0; i < SIZE; i++)
        printf("b[%d]=%d\n", i, b[i]);

    printf("Enter 10 numbers:");

    for(int i = 0; i < SIZE; i++)
        scanf("%d", &a[i]);

    printf("You entered:");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;


}


#include <stdio.h>

int main(void){

    int maxNum, index = 3;

    printf("Enter max number:");
    scanf("%d", &maxNum);

    do{
        printf("%d\t%d\n", index, index*index);
        index = index + 1;
    }while (index <= maxNum);

    return 0;
}

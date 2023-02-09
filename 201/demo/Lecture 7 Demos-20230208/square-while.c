#include <stdio.h>

int main(void){

    int maxNum, index = 3;

    printf("Enter max number:");
    scanf("%d", &maxNum);

    printf("%d\t%d\n", index, index*index);
    index = index + 1;

    while(index <= maxNum){
        printf("%d\t%d\n", index, index*index);
        index = index + 1;
    }

    return 0;
}

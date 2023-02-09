#include <stdio.h>

int main(void){

    int maxNum;

    printf("Enter max number:");
    scanf("%d", &maxNum);

    //note that this assumes that the maxNum is always
    //greater than or equal to 3. If we want to ensure that we print
    //3 9 regardless of the maxNumber, then we need an extra
    //print before the for loop or we need to warn the user
    //about their incorrect output
    for (int index = 3; index <= maxNum; index++)
        printf("%d\t%d\n", index, index*index);

    return 0;
}

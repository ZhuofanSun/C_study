#include <stdio.h>

int main(void){
    int numerator, denominator;

    printf("Enter fraction:");
    scanf("%d/%d", &numerator, &denominator);

    printf("Fraction is: %d/%d\n", numerator, denominator);

    return 0;

}

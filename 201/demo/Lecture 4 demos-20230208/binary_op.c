/* Demonstrate how different variable types can affect operator outcome */

#include <stdio.h>

int main(void){

    int x = 10, y = 8;
    float i = 10.0f, j = 8.0f;

    printf("Recall that we have int x=10, y=8; and float i = 10.0f, j=8.0f\n");

    printf("Dividing two integers x/y and format as float:%f\n", x / y);
    printf("Dividing two integers x/y and format as int:%d\n", x / y);

    printf("Dividing two floats i/j and format as float:%f\n", i / j);
    printf("Dividing two floats i/j and format as int:%d\n", i / j);

    printf("Dividing int by float x/j and format as float:%f\n", x / j);
    printf("Dividing int by float x/j and format as int:%d\n", x / j);
    printf("Dividing float by int i/y and format as float:%f\n", i / y);
    printf("Dividing int by float i/y and format as int:%d\n", i / y);

    return 0;
}

#include <stdio.h>

int main() {

    int twenty = 0, ten = 0, five = 0, one = 0;  // set up variables to record the number of bills
    int num;  // set up a variable to record the input dollar amount

    printf("Enter a num amount: ");  // ask to enter
    scanf("%d", &num);  // record the integer

    twenty += num / 20;  // the division returns an integer
    num %= 20;  // the remainder after use 20 dollars to pay
    ten += num / 10;
    num %= 10;
    five += num / 5;
    num %= 5;
    one += num / 1;  // will remain zero

    printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d\n", twenty, ten, five, one);  // print the result

}

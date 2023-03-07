#include <stdio.h>

int gcd(int m, int n){
    if (n == 0){  // base case
        return m;
    }
    int remainder = m % n;  // get remainder
    m = n;  // m <- n
    n = remainder;  // n <- remainder
    return gcd(m, n);
}

int main(){

    printf("Enter two integers: ");
    int m, n;
    if (scanf("%d", &m) != 1 || scanf("%d", &n) != 1) {
        fprintf(stderr, "Two integers.");
        return 1;
    }
    printf("Greatest common divisor: %d\n", gcd(m, n));
    return 0;
}
/* Demo complex expression evaluation with precedence */

#include <stdio.h>

int main (void) {
    float b = 5, c = 2, d = 4, e = 10, f = 2;
    float a;

    a = b += c++ -d + --e / -f;

    printf("value of a is %f\n", a);

    return 0;
}

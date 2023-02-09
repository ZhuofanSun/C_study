/* demo different streams */

#include <stdio.h>

int main (void){

    int x = 10;

    printf("Printing through printf. x is %d\n", x);
    fprintf(stdout, "Printing through fprintf to stdout. x is %d\n", x);
    fprintf(stderr, "Printing through fprintf to stderr. x is %d\n", x);

    return 0;
}

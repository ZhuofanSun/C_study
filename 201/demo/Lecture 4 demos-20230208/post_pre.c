/* Demo side effects of ++i vs i++ */

#include <stdio.h>

int main (void){

    int i = 1;
    int j = 2;
    int k, m;

    printf("i is %d\n", i);
    printf("j is %d\n\n", j);

    k = ++i + j++;

    printf("i is %d\n", i);
    printf("j is %d\n", j);

    m = j++ - 1;
    printf("k = %d, m=%d\n\n", k, m);

    return 0;
}

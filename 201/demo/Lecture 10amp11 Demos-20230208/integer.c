#include <stdio.h>

int main (void){

    int i;
    unsigned int j;
    long long k;
    unsigned long long p;

    i = 500;
    j = 015u;
    k = 0x3Ffl;
    p = 0xffff12345UL;
    
    // i = 0xffff12345UL;

    printf("i = %d, j = %u, k = %lld, p = %llu\n", i, j, k, p);

    return 0;
}

#include <stdio.h>

#ifndef MAX_LEN
#error MAX_LEN is not defined
#endif

int main(int argc, char *argv[]){

    for (int i = 0; i < MAX_LEN; i++) {
        printf("%d\n", i);
    }

    return 0;
}

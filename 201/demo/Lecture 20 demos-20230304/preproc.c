#include <stdio.h>

int main(int argc, char *argv[]){

    #ifdef DEBUG
        printf("This is an information message that argument is=%s\n", argv[1]);
    #endif

    printf("Hello world!\n");

    return 0;
}

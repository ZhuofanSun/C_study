#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

    char **p = argv;

    printf("The arguments of this program are:\n");
    for(; p < &argv[argc]; p++)
        printf("%s\n", *p);

    printf("3rd=%s\n", *(argv + 2));
    printf("4th letter of 3rd argument=%c\n", argv[2][3]);

    for (int i = 0; i < strlen( *(argv + 2)); i++)
        printf("The %dth letter in the 3rd argument of this program is %c\n", i+1, (*(argv + 2))[i]);


    return 0;
}

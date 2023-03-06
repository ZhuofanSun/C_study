#include <stdio.h>
#ifdef ENGLISH
    #define PRINT_MSG printf("Insert Desk 1");
#elif defined FRENCH
    #define PRINT_MSG printf("Inserez Le Disque 1");
#elif defined SPANISH
    #define PRINT_MSG printf("Inserte El Disco 1");
#else
    #define PRINT_MSG return 0;
#endif

int main(){
    PRINT_MSG
    return 0;
}
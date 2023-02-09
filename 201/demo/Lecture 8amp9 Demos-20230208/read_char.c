/* Demonstrate different ways of reading characters */

#include <stdio.h>

int main (void) {

    char c;

    printf("Enter char (scanf with no space in format specifier):");
    scanf("%c", &c);
    printf("The char read is |%c|\n", c);

    printf("Enter char (reading with getchar):");
    c = getchar();
    printf("The char read is |%c|\n", c);

    printf("Enter char (scanf with space in format specifier):");
    scanf(" %c", &c);
    printf("The char read is |%c|\n", c);
    
    return 0;
}

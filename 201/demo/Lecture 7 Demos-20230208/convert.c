/* Convert string to int */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
    
    int number;

    if (argc != 2){
        printf("Usage: convert <number>\n");
        exit(EXIT_FAILURE);
    }

    printf("Trying to compare a string to an int: %d\n", argv[1] == 40);

    number = atoi(argv[1]);

    printf("You have entered the number %d\n", number);
    printf("To prove it is an int, let's add 1 to it: %d\n", number + 1);

    if (number == 40){
        printf("You guessed the lucky number 40!\n");
    }
    return 0;
}

/* Program searches for a line that begins with an integer and returns that integer. Program checks for errors before and during reading the file */

#include <stdio.h>
#include <stdlib.h>

int main (void){

    FILE *fp = fopen("test_read_file.txt", "r");
    int n;

    if (fp == NULL){ /* can't open file */
        fprintf(stderr, "ERROR: input.txt does not exist.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%d", &n) != 1){
        if (ferror(fp)){
            /* read error*/
            fclose(fp);
            fprintf(stderr, "A read error has occurred. Program exited\n");
            exit(EXIT_FAILURE);
        }

        if (feof(fp)){
            /* end of file reached before integer is found */
            fclose(fp);
            printf("The input file does not contain lines that begin with an integer\n");
            return 0;
        }

        fscanf(fp, "%*[^\n]"); /* skips rest of line */
    }

    fclose(fp);
    printf("Found a line that begins with %d\n", n);
    return 0;
    
}

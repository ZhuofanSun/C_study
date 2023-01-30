/* demo different streams */

#include <stdio.h>
#include <stdlib.h>
int main (void){

    FILE *map_f = fopen("err.txt", "r");

    int curr_lines = 1;
    char curr_pt, curr_ct;

    while(curr_lines <=4 && fscanf(map_f,"%c,%c\n", &curr_pt, &curr_ct) == 2){

        printf("%c, %c\n", curr_pt, curr_ct);
        curr_lines ++;
    }

    if (fscanf(map_f, "%c,%c", &curr_pt, &curr_ct) != EOF || curr_lines != 5){

        fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", "err.txt");
        exit(4);

    }
}

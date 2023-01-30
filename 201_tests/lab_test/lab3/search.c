#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {

    if (argc != 3){

        fprintf(stdout, "Usage: search <input_file> <threshold>\n");
        exit(EXIT_FAILURE);

    }

    int threshold = atoi(argv[2]);
    FILE * input_file = fopen(argv[1], "r");
    if (input_file == NULL) {

        fprintf(stderr, "Error: cannot find %s\n", argv[1]);
        exit(EXIT_FAILURE);

    }


    int num_of_letters[26];
    for (int i = 0; i < 26; ++i) {
        num_of_letters[i] = 0;
    }

    char chr;
    while (fscanf(input_file, "%c", &chr) != EOF){

        if (chr != '\n'){

            num_of_letters[chr - 'a'] += 1;

        }

    }

    _Bool flag = 1;
    for (int i = 0; i < 26; ++i) {

        if (num_of_letters[i] > threshold) {
            printf("%c appears %d times\n", (i + 'a'), num_of_letters[i]);
            flag = 0;
        }
    }

    if (flag) printf("There are no letters that exceed this threshold.\n");

    return 0;

}

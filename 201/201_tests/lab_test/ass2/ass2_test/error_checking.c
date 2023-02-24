#include "error_checking.h"
#define MAX_N 100

void encountered_error(){
    fprintf(stderr, "Encountered error \n");
    exit(7);
}

void check_usage(int argc, char * argv[], char * params[]){

    if (argc != 7 && argc != 9) {  // only accept 7 or 9 arguments
        fprintf(stderr, "Usage: ./wordSearch2D -p <puzzle_file> -l <word_length> -w <wordlist_file> [-o <solution_file>]");
        exit(6);
    }
    char * puzzle_file, * word_length, * wordlist_file, * solution_file = NULL;

    _Bool used[4] = {1, 1, 1, 1};  // used to check usage of arguments, true means not used
    // index0 is for "-p", index1 is for "-l", index2 is for "-w", index3 is for "-o"

    for (int i = 1; i < argc; i+=2) {  // flags only occurs at odd index positions
        // followed by file name or mode num.

        // strcmp function return differences between of ASCII of chars of two strings
        if ( strcmp(argv[i], "-p") == 0 ) {
            if (used[0]) {  // not used gives 1
                used[0] = 0;
                puzzle_file = argv[i + 1];
            }
        }
        else if ( strcmp(argv[i], "-l") == 0 ){
            if(used[1]){
                used[1] = 0;
                word_length = argv[i + 1];
            }
        }
        else if ( strcmp(argv[i], "-w") == 0 ) {
            if(used[2]){
                used[2] = 0;
                wordlist_file = argv[i + 1];
            }
        }
        else if ( strcmp(argv[i], "-o") == 0 ) {
            if(used[3]){
                used[3] = 0;
                solution_file = argv[i + 1];
                }
            }

    }

    if (used[0] == 1 || used[1] == 1 || used[2] == 1){  // repeated usage or wrong flag will cause empty
        fprintf(stderr, "Usage: ./wordSearch2D -p <puzzle_file> -l <word_length> -w <wordlist_file> [-o <solution_file>]");
        exit(6);
    }


    params[0] = puzzle_file;
    params[1] = word_length;
    params[2] = wordlist_file;
    params[3] = solution_file;
}


char** check_puzzle(char *file_name, int *n) {
    FILE *puzzle_file = fopen(file_name, "r");  // try to open the mapping file
    if (puzzle_file == NULL) {  // fail to find the file
        fprintf(stderr, "Error: Puzzle file %s does not exist\n", file_name);
        exit(4);
    }


    int row = 0, col = 0;
    char **matrix;  // a string pointer

    char row_str[MAX_N+2];  // full case: 100 char, '\n', '\0', last char must be NULL
    while (fgets(row_str, MAX_N+2, puzzle_file) != NULL) {  // fgets return each line.
        if (row_str[0] == '\n'){
            break;
        }
        if (col != 0 && row == col)
            encountered_error();
        // use the first line to make string pointer and check size.

        int len = (int)strlen(row_str);  // strlen returns long
        if (row_str[len - 1] == '\n') {  // remove 'enter'
            row_str[len - 1] = '\0';
            len--;  // this should be the matrix size
        }

        if (col == 0) {  // true in the 1st iteration, check col == row later
            col = len;  // 1st iteration, assume row == col to make string pointer

            // allocate a space for the `char*` pointer, elements should be the string in each row
            do {matrix = (char**) malloc(sizeof(char*) * col);} while (matrix == NULL);

            for (int i = 0; i < col; i++) {
                // allocate a space for the string in each row
                matrix[i] = (char*) malloc(sizeof(char) * col);
            }
        }
        else if (len != col)  // error if while loop reaches col = row+1
            encountered_error();

        for (int i = 0; i < len; i++) {

            if (row_str[i] < 32 || row_str[i] > 126)  // check each char in the string ASCII[32, 126]
                encountered_error();

            matrix[row][i] = row_str[i];
        }
        row++;
    }

    if (row == col){ printf("wtf");
                     *n = row;}

    else
        encountered_error();

    fclose(puzzle_file);
    return matrix;
}

int check_word_len(const char * len_str, int max_num){
    int len = 0;
    while (len_str[len] != '\0'){
        if (len_str[len] < '0' || len_str[len] > '9')
            encountered_error();
        len ++;
    }
    int word_len =  atoi(len_str);
    if (word_len < 1 || word_len > max_num)
        encountered_error();

    return word_len;

}

char** check_wordlist(char * file_name, int word_len, int * word_num){
    FILE *word_file = fopen(file_name, "r");  // try to open the mapping file
    char **words = NULL;  // a string pointer

    if (word_file == NULL) {  // fail to find the file
        fprintf(stderr, "Error: Wordlist file %s does not exist\n", file_name);
        exit(5);
    }

    char row_str[word_len+2];
    int row = 0;
    char ** new_words;
    while(fgets(row_str, word_len + 2, word_file) != NULL){  // 1 for \n 1 for \0
        if (row_str[0] == '\n')
            break;
        int len = (int)strlen(row_str);


        if (row_str[len-1] == '\n') {  // remove 'enter'
            row_str[len-1] = '\0';
            len --;
        }

        if (len != word_len)  // minus the 'enter'
            encountered_error();
        if (row == 0)
            do { words = (char **) malloc(sizeof(char *) * 1); } while (words == NULL);
        else{
            do {new_words = realloc(words, sizeof(char *) * (row+1));} while (new_words == NULL);
            words = new_words;
        }
        do { words[row] = (char *) malloc(sizeof(char) * word_len); } while (words[row] == NULL);

        for (int i = 0; i < word_len; ++i) {
            if ((int)row_str[i] < 32 || (int) row_str[i] > 126)
                encountered_error();
            words[row][i] = row_str[i];
        }
        row ++;
    }
    fclose(word_file);
    *word_num = row;
    return words;
}

int error_main(){

    // Usage: ./wordSearch2D -p <puzzle_file> -l <word_length> -w <wordlist_file> [-o <solution_file>]
    // "wordSearch2D", "-p", "aaa", "-l", "bbb", "-w", "ccc", "-o", "ddd"
    int argc = 9;
    char * argv[] = {"wordSearch2D", "-p", "../../tests/sample_tests/student_1_table.txt",
                     "-l", "4", "-w", "../../tests/sample_tests/student_1_wordlist.txt", "-o", "ddd"};
    char *pf_wl_wf_sf[4];
    check_usage(argc, argv, pf_wl_wf_sf);
    for (int i = 0; i < 4; ++i) {
        if (pf_wl_wf_sf[i] == NULL)
            printf("\ntest null\n");
        printf("%s\n", pf_wl_wf_sf[i]);
    }

    int matrix_size = 0;
    char **matrix = check_puzzle(pf_wl_wf_sf[0], &matrix_size);
    int word_len = check_word_len(pf_wl_wf_sf[1], matrix_size);
    int word_num;
    char **words = check_wordlist(pf_wl_wf_sf[2], word_len, &word_num);
    printf("matrix_size:  %d\n", matrix_size);

    printf("\nmatrix: \n");
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < word_num; ++j) {
            printf("%c  ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nword_num: %d\n", word_num);
    printf("words: \n");
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < word_len; ++j) {
            printf("%c  ",words[i][j]);
        }
        printf("\n");
    }
    printf("word_len: %d\n", word_len);



}
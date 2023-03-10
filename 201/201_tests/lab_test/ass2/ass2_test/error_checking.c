// -----------------------------------------------
// Student name:        Zhuofan Sun
// Student ID:          1740983
// CCID:                zhuofan3
// Lecture section:     B1
// instructor's name:   Henry Tang
// Lab section:         H01
// -----------------------------------------------

#include "error_checking.h"
#define MAX_N 100  // max matrix size, word len

void encountered_error(){
    /* print encountered error message and exit(7) */
    fprintf(stderr, "Encountered error \n");
    exit(7);
}

void check_usage(int argc, char * argv[], char * pf_wl_wf_sf[]){
    /*
     * check program usage, get the four arguments after the flags
     * parm: num of arguments, arguments string array, required arguments string array
     * */

    if (argc != 7 && argc != 9) {  // only accept 7 or 9 arguments  -- return code: 6
        fprintf(stderr, "Usage: ./wordSearch2D -p <puzzle_file> -l <word_length> -w <wordlist_file> [-o <solution_file>]");
        exit(6);
    }

    char * puzzle_file, * word_length, * wordlist_file, * solution_file = NULL;

    _Bool used[4] = {1, 1, 1, 1};  // used to check usage of arguments, true means not used
    // index0 is for "-p", index1 is for "-l", index2 is for "-w", index3 is for "-o"

    for (int i = 1; i < argc; i+=2) {  // flags only occurs at odd index positions
        // followed by file name or mode num.

        if ( strcmp(argv[i], "-p") == 0 ) {
            if (used[0]) {  // not used gives 1
                used[0] = 0;  // set it to used
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

    if (used[0] == 1 || used[1] == 1 || used[2] == 1){  // '-o' is optional, so check first 3
        fprintf(stderr, "Usage: ./wordSearch2D -p <puzzle_file> -l <word_length> -w <wordlist_file> [-o <solution_file>]");
        exit(6);
    }

    pf_wl_wf_sf[0] = puzzle_file;
    pf_wl_wf_sf[1] = word_length;
    pf_wl_wf_sf[2] = wordlist_file;
    pf_wl_wf_sf[3] = solution_file;  // may be NULL
}


char** check_puzzle(char *file_name, int *n) {
    /*
     * check puzzle file form '-p' flag, get matrix, get matrix side length
     * parm: string of file name, side length array
     * return: string array stores the matrix data
     * */
    FILE *puzzle_file = fopen(file_name, "r");  // try to open the mapping file
    if (puzzle_file == NULL) {  // fail to find the puzzle file -- return code 4
        fprintf(stderr, "Error: Puzzle file %s does not exist\n", file_name);
        exit(4);
    }

    int row = 0, col = 0;  // row is index, col is no. of columns
    char **matrix;

    char row_str[MAX_N+2];  // full case: 100 char, '\n', '\0', last char must be NULL
    while (fgets(row_str, MAX_N+2, puzzle_file) != NULL) {  // loop end at EOF
        if (row_str[0] == '\n')
            break;
        if (col != 0 && row == col)  // row is index, col is no. of columns
            encountered_error();

        int len = (int)strlen(row_str);
        if (row_str[len - 1] == '\n') {  // remove 'enter'
            row_str[len - 1] = '\0';
            len--;
        }

        if (col == 0) {  // the 1st iteration
            col = len;  // size of matrix
            // build the col*col matrix
            do {matrix = (char**) malloc(sizeof(char*) * col);} while (matrix == NULL);
            for (int i = 0; i < col; i++) {
                // allocate a space for the string in each row
                matrix[i] = (char*) malloc(sizeof(char) * col);
            }
        }
        else if (len != col)  // compare string size with the first row, check string size
            encountered_error();

        for (int i = 0; i < len; i++) {  // check ascii of each char and add strings
            if (row_str[i] < 32 || row_str[i] > 126)
                encountered_error();
            matrix[row][i] = row_str[i];
        }
        row++;
    }
    if(row == col)  // row++ at the end of loop
        *n = row;
    else
        encountered_error();

    fclose(puzzle_file);
    return matrix;
}

int check_word_len(const char * len_str, int max_num){
    /*
     * check word length from '-l' flag, convert the length to int and return
     * parm: the string after '-l' flag, matrix size -- the maximum word length
     * return: int type word length
     * */

    int len = 0;
    while (len_str[len] != '\0'){  // check for number, no negative sign, no decimal point
        if (len_str[len] < '0' || len_str[len] > '9')
            encountered_error();
        len ++;
    }
    int word_len =  atoi(len_str);  // convert into integer
    if (word_len > max_num)  // check range
        encountered_error();

    return word_len;

}

char** check_wordlist(char * file_name, int word_len, int * word_num){
    /*
     * check wordlist file, get the total number of words, check the word length got from '-l' flag
     * parm: the file name string, the length of a word in each line, the words number pointer
     * return the word string array
     */

    FILE *word_file = fopen(file_name, "r");  // try to open the mapping file
    char **words = NULL;  // the string pointer

    if (word_file == NULL) {  // fail to find the wordlist file --return code 5
        fprintf(stderr, "Error: Wordlist file %s does not exist\n", file_name);
        exit(5);
    }

    char row_str[word_len+2];  // store the string in each line
    int row = 0;  // row index
    char ** new_words = NULL;  // a copy of 'words'  -- to extend words array

    while(fgets(row_str, word_len + 2, word_file) != NULL){  // 1 for \n and 1 for \0
        if (row_str[0] == '\n')  // end
            break;

        int len = (int)strlen(row_str);  // the string len at 'row'

        if (row_str[len-1] == '\n') {  // remove '\n'
            row_str[len-1] = '\0';
            len --;
        }

        if (len != word_len)  // check string length with '-l' number
            encountered_error();

        // allocate one more row space for 'words' -- the word list
        if (row == 0)
            do { words = (char **) malloc(sizeof(char *) * 1); } while (words == NULL);
        else{
            do {new_words = realloc(words, sizeof(char *) * (row+1));} while (new_words == NULL);
            words = new_words;
        }
        // allocate the space for string in each row in 'words'
        do { words[row] = (char *) malloc(sizeof(char) * (word_len+1)); } while (words[row] == NULL);

        int i = 0;
        for (; i < word_len; ++i) {  // check ascii, and add strings
            if ((int)row_str[i] < 32 || (int) row_str[i] > 126)
                encountered_error();
            words[row][i] = row_str[i];
            words[row][i+1] = '\0';
        }
        row ++;
    }
    fclose(word_file);
    *word_num = row;
    return words;
}

void check_sol (const char *filename) {
    /* clean or make the given file or 'output.txt' */
    const char *file_name = ((filename != NULL) ? filename : "output.txt");  // no '-o' flag
    FILE *sol_file = fopen(file_name, "w");  // open with "w" will clear the file

    if (sol_file == NULL)
        encountered_error();
    else
        fclose(sol_file);

}




int error_main(){
    /* test cases */

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


    return 0;
}

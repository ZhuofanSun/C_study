#include "error_checking.h"
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
                if (i + 1 < argc) {
                    solution_file = argv[i + 1];
                } else {
                    fprintf(stderr, "Usage: ./wordSearch2D -p <puzzle_file> -l <word_length> -w <wordlist_file> [-o <solution_file>]");
                    exit(6);
                }
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

int main(){
    // Usage: ./wordSearch2D -p <puzzle_file> -l <word_length> -w <wordlist_file> [-o <solution_file>]
    // "wordSearch2D", "-p", "aaa", "-l", "bbb", "-w", "ccc", "-o", "ddd"
    int argc = 9;
    char * argv[] = {"wordSearch2D", "-p", "aaa", "-l", "bbb", "-w", "ccc", "-o", "ddd"};
    char *pf_wl_wf_sf[4];
    check_usage(argc, argv, pf_wl_wf_sf);
    for (int i = 0; i < 4; ++i) {
        if (pf_wl_wf_sf[i] == NULL)
            printf("\ntest null\n");
        printf("%s\n", pf_wl_wf_sf[i]);
    }



}
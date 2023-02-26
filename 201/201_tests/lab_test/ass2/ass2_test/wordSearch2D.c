// -----------------------------------------------
// Student name:        Zhuofan Sun
// Student ID:          1740983
// CCID:                zhuofan3
// Lecture section:     B1
// instructor's name:   Henry Tang
// Lab section:         H01
// -----------------------------------------------

#include "puzzle2D.h"
#include "error_checking.h"

void output(const char * sf_name, int x, int y, const int direction, const int distance, const char*word){
    /*
     * Used after all check function and find. Out put the position massage
     * of a single `word` into sf_name file or 'output.txt'
     * parm: the output file name, x, y, direction code, distance from (x, y), word string
     * */
    FILE* solution_file;
    if (sf_name == NULL){  // with no '-o' flag
        solution_file = fopen("output.txt", "a");
    }
    else{
        solution_file = fopen(sf_name, "a");
    }

    if (distance == -1){  // not found
        fprintf(solution_file, "%s;(0,0);0\n", word);
        fclose(solution_file);
        return;
    }

    switch (direction) {  // found
        case 1:
            x += distance;
            fprintf(solution_file, "%s;(%d,%d);%d\n", word, y, x, direction);
            break;

        case 2:
            x -= distance;
            fprintf(solution_file, "%s;(%d,%d);%d\n", word, y, x, direction);
            break;

        case 3:
            y += distance;
            fprintf(solution_file, "%s;(%d,%d);%d\n", word, y, x, direction);
            break;

        case 4:
            y -= distance;
            fprintf(solution_file, "%s;(%d,%d);%d\n", word, y, x, direction);
            break;

        case 5:
            x += distance;
            y += distance;
            fprintf(solution_file, "%s;(%d,%d);%d\n", word, y, x, direction);
            break;

        case 6:
            x -= distance;
            y -= distance;
            fprintf(solution_file, "%s;(%d,%d);%d\n", word, y, x, direction);
            break;

        case 7:
            x += distance;
            y -= distance;
            fprintf(solution_file, "%s;(%d,%d);%d\n", word, y, x, direction);
            break;

        case 8:
            x -= distance;
            y += direction;
            fprintf(solution_file, "%s;(%d,%d);%d\n", word, y, x, direction);
            break;

        default:  // not used
            fprintf(stderr, "ERROR: direction = %d\n", direction);
            fclose(solution_file);
            exit(200);
    }

    fclose(solution_file);
}



int main(int argc, char* argv[]){
    // test cases
    // time ./wordSearch2D -p ../tests/sample_tests/student_1_table.txt -l 4 -w ../tests/sample_tests/student_1_wordlist.txt
    // time ./wordSearch2D -p ../tests/sample_tests/student_2_table.txt -l 6 -w ../tests/sample_tests/student_2_wordlist.txt
    // time ./wordSearch2D -w ../tests/sample_tests/student_2_wordlist.txt -p ../tests/sample_tests/student_2_table.txt -l 6 -o mysolution.com.png
    //int argc = 7;
    // char * argv[] = {"wordSearch2D", "-p", "../../tests/sample_tests/student_1_table.txt", "-l", "4", "-w", "../../tests/sample_tests/student_1_wordlist.txt"};
    // char * argv[] = {"wordSearch2D", "-p", "../../tests/sample_tests/student_2_table.txt", "-l", "6", "-w", "../../tests/sample_tests/student_2_wordlist.txt"};
    char *pf_wl_wf_sf[4], **matrix;
    int matrix_size = 0, word_len, word_num;

    // check and get all necessary data
    check_usage(argc, argv, pf_wl_wf_sf);
    matrix = check_puzzle(pf_wl_wf_sf[0], &matrix_size);
    word_len = check_word_len(pf_wl_wf_sf[1], matrix_size);
    char ** words = check_wordlist(pf_wl_wf_sf[2], word_len, &word_num);
    check_sol(pf_wl_wf_sf[3]);

    // find all words in wordlist and print into output file by a loop
    int x, y, distance;
    for (int i = 0; i < word_num; ++i) {
        x = 0, y = 0;
        int direction = 1;
        distance = find(matrix, &x, &y, words[i], &direction, matrix_size);
        output(pf_wl_wf_sf[3], x, y, direction, distance, words[i]);
    }
    return 0;
}

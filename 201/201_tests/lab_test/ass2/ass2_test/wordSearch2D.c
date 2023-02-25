#include "puzzle2D.h"
#include "error_checking.h"

void output(const char * sf_name, int x, int y, const int direction, const int distance, const char*word){
    FILE* solution_file;
    if (sf_name == NULL){
        solution_file = fopen("output.txt", "a");
    }
    else{
        solution_file = fopen(sf_name, "a");
    }
    if (distance == -1){
        printf("write into_file %s:  %s;(0,0);0\\n\n", sf_name, word);
        fprintf(solution_file, "%s;(0,0);0\n", word);
        fclose(solution_file);
        return;
    }
    switch (direction) {
        case 1:
            x += distance;
            printf("write into_file %s: %s;(%d,%d);%d\n", sf_name, word, y, x, direction);
            fprintf(solution_file, "%s;(%d,%d);%d\n", word, y, x, direction);
            break;

        case 2:
            x -= distance;
            printf("write into_file %s: %s;(%d,%d);%d\n", sf_name, word, y, x, direction);
            fprintf(solution_file, "%s;(%d,%d);%d\n", word, y, x, direction);
            break;

        case 3:
            y += distance;
            printf("write into_file %s: %s;(%d,%d);%d\n", sf_name, word, y, x, direction);
            fprintf(solution_file, "%s;(%d,%d);%d\n", word, y, x, direction);
            break;

        case 4:
            y -= distance;
            printf("write into_file %s: %s;(%d,%d);%d\n", sf_name, word, y, x, direction);
            fprintf(solution_file, "%s;(%d,%d);%d\n", word, y, x, direction);
            break;

        case 5:
            x += distance;
            y += distance;
            printf("write into_file %s: %s;(%d,%d);%d\n", sf_name, word, y, x, direction);
            fprintf(solution_file, "%s;(%d,%d);%d\n", word, y, x, direction);
            break;

        case 6:
            x -= distance;
            y -= distance;
            printf("write into_file %s: %s;(%d,%d);%d\n", sf_name, word, y, x, direction);
            fprintf(solution_file, "%s;(%d,%d);%d\n", word, y, x, direction);
            break;

        case 7:
            x += distance;
            y -= distance;
            printf("write into_file %s: %s;(%d,%d);%d\n", sf_name, word, y, x, direction);
            fprintf(solution_file, "%s;(%d,%d);%d\n", word, y, x, direction);
            break;

        case 8:
            x -= distance;
            y += direction;
            printf("write into_file %s: %s;(%d,%d);%d\n", sf_name, word, y, x, direction);
            fprintf(solution_file, "%s;(%d,%d);%d\n", word, y, x, direction);
            break;

        default:
            fprintf(stderr, "ERROR: direction = %d\n", direction);
            fclose(solution_file);
            exit(200);
    }

    fclose(solution_file);
}



int main(){
    // ./wordSearch2D -p ./tests/local/puzzle.txt -l 2 -w ./tests/local/wordlist.txt -o ./tests/local/output.txt
    // time ./wordSearch2D -p ../tests/sample_tests/student_1_table.txt -l 4 -w ../tests/sample_tests/student_1_wordlist.txt
    // time ./wordSearch2D -p ../tests/sample_tests/student_2_table.txt -l 6 -w ../tests/sample_tests/student_2_wordlist.txt
    // time ./wordSearch2D -w ../tests/sample_tests/student_2_wordlist.txt -p ../tests/sample_tests/student_2_table.txt -l 6 -o mysolution.com.png
    int argc = 7;
    char * argv[] = {"wordSearch2D", "-p", "../../tests/sample_tests/student_1_table.txt", "-l", "4", "-w", "../../tests/sample_tests/student_1_wordlist.txt"};
    // char * argv[] = {"wordSearch2D", "-p", "../../tests/sample_tests/student_2_table.txt", "-l", "6", "-w", "../../tests/sample_tests/student_2_wordlist.txt"};
    char *pf_wl_wf_sf[4], **matrix;
    int matrix_size = 0, word_len, word_num;

    check_usage(argc, argv, pf_wl_wf_sf);
    matrix = check_puzzle(pf_wl_wf_sf[0], &matrix_size);
    word_len = check_word_len(pf_wl_wf_sf[1], matrix_size);
    char ** words = check_wordlist(pf_wl_wf_sf[2], word_len, &word_num);
    check_sol(pf_wl_wf_sf[3]);

    int x, y, distance;
    for (int i = 0; i < word_num; ++i) {
        x = 0, y = 0;
        int direction = 1;
        printf("find-dir-str(): short_str: %s\n\n", words[i]);
        distance = find(matrix, &x, &y, words[i], &direction, matrix_size);
        printf("2distance: %d\n", distance);
        output(pf_wl_wf_sf[3], x, y, direction, distance, words[i]);
    }
    return 0;
}
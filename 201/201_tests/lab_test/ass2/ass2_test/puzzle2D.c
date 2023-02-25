#include "puzzle2D.h"
#include "error_checking.h"
#define MAX_WORD_LENGTH 101
#define D 256
#define P 7079



int calculate_hash(const char * string, const int len){
    int hash = 0;
    for (int index =  0; index < len; ++index) {
        hash = (D * hash + string[index]) % P;
    }

    if (hash < 0)
        return P+hash;

    return hash;

}

_Bool compare_str(const char *short_str, const char *long_str, int short_len, int curr_str_index){
    for (int i = 0; i < short_len; ++i) {
        if (short_str[i] != long_str[curr_str_index + i]){
            return 0;
        }
    }

    return 1;
}



int find_str(char *long_str, char *short_str){
    int long_len = (int)strlen(long_str), short_len = (int)strlen(short_str);
    if (long_len < short_len)
        return -1;

    // calculate h
    int h = 1;
    for (int i = 0; i < short_len-1; ++i) {
        h *= D;
    }
    h %= P;
    // end of calculate h


    int short_hash = calculate_hash(short_str, short_len);
    char substr[short_len+1];
    strncpy(substr, long_str, short_len);
    substr[short_len] = '\0';
    // printf("substr: %s  \n", substr);

    int long_hash = calculate_hash(substr, short_len);

    int substr_num = long_len - short_len + 1;  //长字符串中最多有这么多可能的短字符串
    int sub_letter_index;
    int add_letter_index;


    if (long_hash == short_hash) {
        if (compare_str(short_str, long_str, short_len, 0))
            return 0;
    }

    for (int curr_str_index = 1; curr_str_index < substr_num; ++curr_str_index) {

        sub_letter_index = curr_str_index - 1;
        add_letter_index = sub_letter_index + short_len;
        long_hash = (D * (long_hash - long_str[sub_letter_index] * h) + long_str[add_letter_index]) % P;

        if (long_hash < 0)
            long_hash = P + long_hash;  // 他妈的明明是加上去非得说减去
        if (long_hash == short_hash) {
            if (compare_str(short_str, long_str, short_len, curr_str_index))
                return curr_str_index;
        }

    }
    return -1;

}

int find_dir_string(char **matrix, int x, int y, int direction, char *short_str) {

    int col = (int)strlen(matrix[0]);
    int row = col;
    int i, j, index = 0;
    char long_str[row+1];
    switch (direction) {
        case 1:  // right
            for (i = x; i < col; i++) {
                long_str[index++] = matrix[y][i];
            }
            break;
        case 2:  // left
            for (i = x; i >= 0; i--) {
                long_str[index++] = matrix[y][i];
            }
            break;
        case 3:  // down
            for (i = y; i < row; i++) {
                long_str[index++] = matrix[i][x];
            }
            break;
        case 4:  // up
            for (i = y; i >= 0; i--) {
                long_str[index++] = matrix[i][x];
            }
            break;
        case 5:  // bottom right
            for (i = x, j = y; i < col && j < row; i++, j++) {
                long_str[index++] = matrix[j][i];
            }
            break;
        case 6:  // top left
            for (i = x, j = y; i >= 0 && j >= 0; i--, j--) {
                long_str[index++] = matrix[j][i];
            }
            break;
        case 7:  // up right
            for (i = y, j = x; i >= 0 && j < row; i--, j++) {
                long_str[index++] = matrix[i][j];
            }
            break;
        case 8:  // bottom left
            for (i = y, j = x; i < col && j >= 0; i++, j--) {
                long_str[index++] = matrix[i][j];
            }
            break;
        default:
            return -1;
    }
    long_str[index] = '\0';
    printf("find-dir-str(): long_str: %s\n", long_str);

    return find_str(long_str, short_str);
}

int find(char** matrix, int* x, int* y, char* short_str, int * direction, int matrix_size){  // 多次调用find_dir_strin，像下面main一样
    int result;
    printf("\n");
    printf("direction: %d\n", *direction);
    for (; *x < matrix_size; ++(*x)) {  // 00 - n0
        printf("\n");
        *direction = 1;
        for (; *direction < 9; ++ *direction) {
            if ((result = find_dir_string(matrix, *x, *y, *direction, short_str)) != -1)
                break;
        }
        if (result != -1) break;
    }
    if (result != -1)
        return result;
    printf("\n");
    (*x) --;
    for (; *y < matrix_size; ++ *y) {  // n0 - nn
        printf("\n");
        *direction = 1;
        for (; *direction < 9; ++ *direction) {
            if ((result = find_dir_string(matrix, *x, *y, *direction, short_str)) != -1){
                break;
            }

        }
        if (result != -1) break;
    }

    if (result != -1)
        return result;
    (*y) --;
    printf("\n");
    for (; *x >= 0; -- *x) {  // nn - 0n
        printf("\n");
        *direction = 1;
        for (; *direction < 9; ++ *direction) {
            if ((result = find_dir_string(matrix, *x, *y, *direction, short_str)) != -1)
                break;

        }
        if (result != -1) break;
    }

    if (result != -1)
        return result;
    (*x) ++;
    for (; *y >= 0; -- *y) {  // 0n -- 00
        printf("\n");
        *direction = 1;
        for (; *direction < 9; ++ *direction) {
            if ((result = find_dir_string(matrix, *x, *y, *direction, short_str)) != -1)
                break;
        }
        if (result != -1) break;
    }
    return result;
    (*y) ++;
}



int puzzle_main(){
    error_main();

    int argc = 9;
    char * argv[] = {"wordSearch2D", "-p", "../../tests/sample_tests/student_1_table.txt",
                     "-l", "4", "-w", "../../tests/sample_tests/student_1_wordlist.txt", "-o", "ddd"};
    char *pf_wl_wf_sf[4];
    check_usage(argc, argv, pf_wl_wf_sf);
    int matrix_size = 0;
    char **matrix = check_puzzle(pf_wl_wf_sf[0], &matrix_size);
    int word_len = check_word_len(pf_wl_wf_sf[1], matrix_size);
    int word_num;
    char ** words = check_wordlist(pf_wl_wf_sf[2], word_len, &word_num);
    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < matrix_size; ++j) {
            printf("%c  ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nwords: \n");
    for (int i = 0; i < word_num; ++i) {
        for (int j = 0; j < word_len; ++j) {
            printf("%c  ",words[i][j]);
        }
        printf("\n");
    }
    printf("word_len: %d\n", word_len);
     int x = 0, y = 0, direction = 1, result;
     char *short_str = "abc";

     result = find(matrix, &x, &y, short_str, &direction, matrix_size);
    printf("\n\nresult: %d", result);

    return 0;

}
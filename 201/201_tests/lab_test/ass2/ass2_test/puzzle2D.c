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
#define MAX_WORD_LENGTH 101
#define D 256
#define P 7079

int calculate_hash(const char * string, const int len){
    /*
     * calculate hash: hash = (D * <previous_hash> + <current letter>) % P;
     * return int type hash value
     * */
    int hash = 0;
    for (int index =  0; index < len; ++index) {
        hash = (D * hash + string[index]) % P;
    }

    if (hash < 0)
        return P+hash;

    return hash;

}

_Bool compare_str(const char *short_str, const char *long_str, int short_len, int curr_str_index){
    /* same string return true, otherwise false*/
    for (int i = 0; i < short_len; ++i) {
        if (short_str[i] != long_str[curr_str_index + i]){
            return 0;
        }
    }

    return 1;
}



int find_str(char *long_str, char *short_str){
    /*
     * Rabin-Karp algorithm to find in short_str is in long_str, return index, or -1 if not exists
     * */
    int long_len = (int)strlen(long_str), short_len = (int)strlen(short_str);
    if (long_len < short_len)
        return -1;

    // calculate h
    int h = 1;
    for (int i = 0; i < short_len-1; ++i) {
        h *= D;
    }
    h %= P;

    // calculate hash of short string and hash of first n chars in long string
    int short_hash = calculate_hash(short_str, short_len);
    char substr[short_len+1];
    strncpy(substr, long_str, short_len);
    substr[short_len] = '\0';
    // printf("substr: %s  \n", substr);

    int long_hash = calculate_hash(substr, short_len);

    int substr_num = long_len - short_len + 1;  // the maximum number of substring
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
            long_hash = P + long_hash;  // negative hash value
        if (long_hash == short_hash) {
            if (compare_str(short_str, long_str, short_len, curr_str_index))
                return curr_str_index;
        }

    }
    return -1;

}

int find_dir_string(char **matrix, int x, int y, int direction, char *short_str) {
    /*
     * return if the given short string exists in the direction from (x, y) to the edge of matrix
     * parm: matrix array, x, y, [1,8]direction, the string we are looking for
     * return: distance from x,y if exist, otherwise -1
     * */
    int col = (int)strlen(matrix[0]);
    int row = col;
    int i, j, index = 0;
    char long_str[row+1];
    //get long string from x,y to edge of matrix in the given direction
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

    return find_str(long_str, short_str);
}

int find(char** matrix, int* x, int* y, char* short_str, int * direction, int matrix_size){
    /*
     * use find_dir_string start form (0,0) along the four edge, and find in 8 directions each time
     * use find_dir_string for (4n-4) times
     * parm: matrix array, x, y, string we are looking for, direction pointer, edge length
     * return: distance from current point and direction
     * */
    int result;
    for (; *x < matrix_size; ++(*x)) {  // 00 - n0
        *direction = 1;  // start from 1 each time
        for (; *direction < 9; ++ *direction) {  // for all direction
            if ((result = find_dir_string(matrix, *x, *y, *direction, short_str)) != -1)  // exist -> break
                break;
        }
        if (result != -1) break;  // outer loop exist -> break
    }
    if (result != -1)  // function exist -> break
        return result;
    (*x) --;

    for (; *y < matrix_size; ++ *y) {  // n0 - nn
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

    for (; *x >= 0; -- *x) {  // nn - 0n
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
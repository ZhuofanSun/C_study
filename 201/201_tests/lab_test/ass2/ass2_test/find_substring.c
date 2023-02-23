// Rabin-Karp algorithm 拉宾卡普算法
// 从一个长的字符串中匹配短的字符串

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    if (long_len < short_len){
        fprintf(stderr, "长的在前\n");
        exit(EXIT_FAILURE);
    }

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
    // printf("substr_num: %d\n", substr_num);

    if (long_hash == short_hash) {
        if (compare_str(short_str, long_str, short_len, 0))
            return 0;
    }

    for (int curr_str_index = 1; curr_str_index < substr_num; ++curr_str_index) {
        // printf("\n");
        sub_letter_index = curr_str_index - 1;
        add_letter_index = sub_letter_index + short_len;
        // printf("curr_str_index: %d  char: %c\n", curr_str_index, long_str[curr_str_index]);
        // printf("sub_letter_index: %d  char: %c\n", sub_letter_index, long_str[sub_letter_index]);
        // printf("add_letter_index: %d  char:%c\n", add_letter_index, long_str[add_letter_index]);
        // printf("long_hash: %d\n", long_hash);
        // printf("short_hash: %d\n", short_hash);
        long_hash = (D * (long_hash - long_str[sub_letter_index] * h) + long_str[add_letter_index]) % P;
        // printf("long_hash_after: %d\n", long_hash);
        // printf("short_hash_after: %d\n", short_hash);
        if (long_hash < 0)
            long_hash = P + long_hash;  // 他妈的明明是加上去非得说减去
        if (long_hash == short_hash) {
            if (compare_str(short_str, long_str, short_len, curr_str_index))
                return curr_str_index;
        }

    }
    return -1;

}




int main() {
    //哈希函数，用来映射任意大小的数据到固定大小的数据上

    char long_str[MAX_WORD_LENGTH];
    char short_str[MAX_WORD_LENGTH];
    printf("input long string: ");
    int index = 0;
    char c;
    while((c = (char)fgetc(stdin)) != '\n')
        long_str[index++] = c;
    long_str [index] = '\0';

    printf("input short string: ");
    index = 0;
    while((c = (char)fgetc(stdin)) != '\n')
        short_str[index++] = c;
    short_str[index] = '\0';

    int result = find_str(long_str, short_str);
    printf("result: %d\n", result);
    if (result == -1)
        printf("\n没找到捏\n");
    else
        printf("\n在index %d 位找到了，好耶\n", result);


}
#include <stdio.h>
#include <string.h>
/**
int main() {
    char str[20];
    char str2[20] = "abcdefghi";
    scanf("%s", str);
    int len = strlen(str), len2 = strlen(str2);
    _Bool flag = 0;
    for (int i = 0; i < len; ++i) {
        flag = 0;
        for (int j = 0; j < len2; ++j) {
            if (str2[j] == str[i]) {
                flag = 1;
                break;
            }
        }
        if (!flag){
            break;
        }


    }

    printf(!flag ? "not in":"in");
}

**/
int main() {
    char str1[64], str2[64];
    gets(str1);
    gets(str2);
    unsigned long len1 = strlen(str1), len2 = strlen(str2);

    _Bool flag = 0;
    for (int i = 0; i < len1; ++i) {
        flag = 0;
        for (int j = 0; j < len2; ++j) {

            if (str1[i + j] != str2[j]) {

                flag = 1;
                break;
            }
        }
        if (!flag) break;
    }

    puts(flag ? "不包含" : "包含");

}
#include <stdio.h>
# include <string.h>

//“回文串”是一个正读和反读都一样的字符串，请你实现一个C语言程序，判断用户输入的字符串（仅出现英文字符）是否为“回文”串。
//ABCBA 就是一个回文串，因为正读反读都是一样的
//ABCA 就不是一个回文串，因为反着读不一样

int main() {
    char str[20];
    scanf("%s", str);
    int index = strlen(str) - 1;
    _Bool flag = 1;
    for (int i = 0; i <= index - i; ++i) {
        if (str[i] != str[index - i]){

            flag = 0;
            break;
        }
    }

    printf(!flag ? "不是回文串":"是回文串");

}

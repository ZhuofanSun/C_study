#include "stack.h"
#define MAX_INPUT_LENGTH 100

void get_input(char * input_str);  // ask for input
void check_brackets(char * input_str);  // check bracket pairs and print result

void get_input(char * input_str){

    printf("Enter parentheses and/or braces: ");
    // record the input string, will end with '\n' followed by many '\0'
    char chr;
    int len = 0;
    while ((chr = (char)getchar()) != '\n'){
        input_str = (char*)realloc(input_str, (len + 1) * sizeof(char));  // 每输入一个字符，就动态扩容1个字节
        input_str[len++] = chr;
    }
    input_str = (char*)realloc(input_str, (len + 1) * sizeof(char));  // 为字符串末尾添加一个空字符
    input_str[len] = '\0';  // 字符串最后必须以'\0'结尾
}

void check_brackets(char * input_str){

    int index = 0;  // index for string array
    while (input_str[index] != '\0'){  // loop end when meet enter

        if (input_str[index] == '(' || input_str[index] == '[' || input_str[index] == '{')

            push(input_str[index]);

        else if (input_str[index] == ')' || input_str[index] == ']' || input_str[index] == '}') {

            if (input_str[index] != get_top_paired()) {  // top one must match with )/]/}

                printf("Parentheses are not nested properly.\n");
                exit(EXIT_FAILURE);
            }

            else pop();  // inner brackets match, so delete
        }

        index ++;
    }

    if (!is_empty()){  // check if any ( / [ / { remains

        printf("Parentheses are not nested properly.\n");
        exit(EXIT_FAILURE);
    }

    printf("Parentheses are nested properly.\n");

}


int main() {

    char * input_str = (char*)malloc(sizeof(char));  // 初始分配1个字节的内存
    get_input(input_str);
    check_brackets(input_str);

}

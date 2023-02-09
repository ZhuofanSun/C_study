#include "stack.h"
#define MAX_INPUT_LENGTH 100

void get_input(char * input_str);  // ask for input
void check_brackets(char * input_str);  // check bracket pairs and print result

void get_input(char * input_str){

    printf("Enter parentheses and/or braces: ");
    // record the input string, will end with '\n' followed by many '\0'
    fgets(input_str, MAX_INPUT_LENGTH, stdin);
}

void check_brackets(char * input_str){

    int index = 0;  // index for string array
    while (input_str[index] != '\n'){  // loop end when meet enter

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

    char input_str[MAX_INPUT_LENGTH];
    get_input(input_str);
    check_brackets(input_str);

}

/*
#include "stack.h"

char * get_input(char * input_str);  // ask for input
void check_brackets(char * input_str);  // check bracket pairs and print result

char * get_input(char * input_str){

    printf("Enter parentheses and/or braces: ");
    // record the input string, will end with '\n' followed by many '\0'
    char chr;
    int len = 0;
    while ((chr = (char)getchar()) != '\n'){

        //Each time a character is entered, the capacity is dynamically expanded by 1 byte for the next input char
         //realloc will reallocate a new space for the pointer and copy all previous elements into the new one
        input_str = (char*)realloc(input_str, (len + 1) * sizeof(char));
        input_str[len++] = chr;
    }

    input_str = (char*)realloc(input_str, (len + 2) * sizeof(char));
    input_str[len] = '\n';  // The string end with '\0'
    input_str[len+1] = '\0';

    return input_str;


}

void check_brackets(char * input_str){

    int index = 0;  // index for string array
    while (input_str[index] != '\0'){  // loop end when meeting the end of string

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

    char * input_str = (char*)malloc(sizeof(char));  // initially allocate 1 byte of memory
    char * str = get_input(input_str);
    check_brackets(str);

}
*/
#include "stack.h"

int main(){
    /*input the things*/
    char input[100]; // inialize an array that is large enough to store all the input
    printf("Enter parentheses and/or braces: ");
    scanf("%s",input);


    /*put the brackets to the new array*/
    int input_index = 0;
    int brankets_index = 0;
    char brankets[100]; //a new array that only store the brackets


    while(input[input_index]!= '\0'){
        printf("%c   \n", input[input_index]);
        if (input[input_index] == '(' || input[input_index] == '[' || input[input_index] == '{'||
            input[input_index] == ')' || input[input_index] == ']' || input[input_index] == '}'){
            brankets[brankets_index] = input[input_index];
            brankets_index++;
            printf("%c  \n", brankets[input_index]);
        }
        input_index ++;
    }

    /*pair and check the brackets*/
    /*only push the left branket into the stack*/
    /*if the right branket paired the left branket, pop the left branket in the stack*/
    int i=0;
    while (brankets[i] != '\0'){
        printf("%c    ", brankets[i]);
        if(brankets[i] == '(' || brankets[i] == '[' || brankets[i] == '{') {
            push(input[i]);
            print_all();
        }
        else if (brankets[i] == ')' || brankets[i] == ']' || brankets[i] == '}'){
            printf("-----%d------", brankets[i]);

            if (brankets[i]!= pair()) {
                printf("Parentheses are not nested properly.\n");
                exit(EXIT_FAILURE);
            }
        }
        i ++;
    }

    print_all();
    if(!check_empty()){
        printf("Parentheses are not nested properly.\n");
        exit(EXIT_FAILURE);
    }
    printf("Parentheses are nested properly.\n");
}

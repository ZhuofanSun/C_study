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
        if (input[input_index] == '(' || input[input_index] == '[' || input[input_index] == '{'|| 
            input[input_index] == ')' || input[input_index] == ']' || input[input_index] == '}'){
            brankets[brankets_index] = input[input_index];
            brankets_index++;
        }
        input_index ++;
    }

    /*pair and check the brackets*/
    /*only push the left branket into the stack*/
    /*if the right branket paired the left branket, pop the left branket in the stack*/
    int i=0;
    while (brankets[i] != '\0'){
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

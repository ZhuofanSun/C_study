/**
 * This is not a complete program
 * Taken from Ch 10, p220
 **/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

/* external variables */
char contents[STACK_SIZE];
int top = 0;

void make_empty(void){
    top = 0;
}

bool is_empty(void){
    return top == 0;
}

bool is_full(void){
    return top == STACK_SIZE;
}

void push(char i){

    if (is_full()) {

        // stack_overflow(); //not implemented yet
        fprintf(stderr, "Stack overflow ");
        exit(EXIT_FAILURE);

    }
    else
        contents[top++] = i;
}

int pop(void){
    
    if (is_empty()){

        // stack_underflow();//not implemented yet
        fprintf(stderr, "Stack overflow ");
        exit(EXIT_FAILURE);

    }
    else
        return contents[--top];
}

void print_all(void){

    printf("bottom -->  ");
    for (int i = 0; i < top; ++i)
        printf("%c  ",  contents[i]);
    printf("<-- top");

}

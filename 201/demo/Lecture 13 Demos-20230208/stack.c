/**
 * This is not a complete program
 * Taken from Ch 10, p220
 **/

#include <stdbool.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
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

void push(int i){

    if (is_full())
        stack_overflow(); //not implemented yet
    else
        contents[top++] = i;
}

int pop(void){
    
    if (is_empty())
        stack_underflow();//not implemented yet
    else
        return contents[--top];
}

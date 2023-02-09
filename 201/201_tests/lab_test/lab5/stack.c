/**
 * This is not a complete program
 * Taken from Ch 10, p220
 **/

#include "stack.h"

#define STACK_SIZE 10

/* external variables */
char contents[STACK_SIZE];  // stack capacity 10
int top = 0;  // always pointing at the next index

void make_empty(void){  // not used
    top = 0;
}

bool is_empty(void){  // check empty
    return top == 0;
}

bool is_full(void){
    return top == STACK_SIZE;  // check full
}

void push(char i){

    if (is_full()) {

        // stack_overflow(); //not implemented yet
        fprintf(stderr, "Stack overflow ");
        exit(EXIT_FAILURE);

    }
    else
        contents[top++] = i;  // [top] = i then ++
}

int pop(void){

    if (is_empty()){

        // stack_underflow();//not implemented yet
        fprintf(stderr, "Stack underflow \n");
        exit(EXIT_FAILURE);

    }
    else
        return contents[--top];
}

char get_top(void){  // return top element
    if (!is_empty())
        return contents[top-1];  // top points at the next place
    else
        return 'N';  // return any char other than brackets
}

char get_top_paired(void){  // return the char paired with top one
    char top_bracket = get_top();
    switch (top_bracket) {
        case '(':
            return ')';
        case '[':
            return ']';
        case '{':
            return '}';
        default:
            return 'N';
    }

}

void print_all(void){  // print the whole stack  // not used

    printf("bottom -->  ");
    for (int i = 0; i < top; ++i)
        printf("%c  ",  contents[i]);
    printf("<-- top\n");

}

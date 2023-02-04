/**
 * This is not a complete program
 * Taken from Ch 10, p220
 **/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

int stack_underflow();
int stack_overflow();

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
        return stack_underflow();  // not implemented yet
    else
        return contents[--top];
}


int stack_overflow(){

    int new_contents_size;
    new_contents_size = STACK_SIZE * 2;
    int * new_contents;
    new_contents = malloc(sizeof (int) * new_contents_size);
    contents = new_contents;


}


int stack_underflow(){

    printf("Nothing in the stack, pas.");
    return 0;



}

int main(){




    return 1;
}



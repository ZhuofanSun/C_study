#include "stack.h"

#define CAP 10 //the stack has a maximum size/capacity of 10 items.
char Stack[CAP];
int last = 0; // a pointer of index which is pointing at the next index

void overflow(void){
    fprintf(stderr,"Stack overflow\n");
    exit(EXIT_FAILURE);
}

void underflow(void){
    fprintf(stderr,"Stack underflow\n");
    exit(EXIT_FAILURE);
}

void empty(void){ // clean the stack and makes it empty
    last = 0;
}

_Bool check_empty(void){
    return last == 0;
}

_Bool check_full(void){
    return last == CAP;
}

void push(char ch){
    if (check_full())
        overflow();
    else
        Stack[last++] = ch;
}

char pop(void){
    if(check_empty()){
        overflow();
        return 'E';
    }
    else
        return Stack[--last];
}

char pair(void){ // get paired the brackets with the last element.
    char branket = pop();
    if (branket == '(') return ')';
    else if (branket == '{') return '}';
    else if (branket == '[') return ']';
    else return 'E';
}


void print_all(void){  // print the whole stack    not used

    printf("bottom -->  ");
    for (int i = 0; i < last; ++i)
        printf("%c  ",  Stack[i]);
    printf("<-- top\n");
}
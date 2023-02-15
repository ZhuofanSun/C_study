#include "stack.h"
int STACK_SIZE = 0;
typedef char ELEMENT_TYPE;

/* external variables */
ELEMENT_TYPE * contents;
int top = 0;  // always pointing at the next index

void make_empty(void){  // not used
    top = 0;
}

bool is_empty(void){  // check empty
    return top == 0;
}

bool is_full(void){
    return top >= STACK_SIZE;  // check full
}


void stack_overflow(ELEMENT_TYPE i){
    STACK_SIZE += 10;
    ELEMENT_TYPE * new_contents;
    do {
        new_contents = realloc(contents, STACK_SIZE * sizeof(ELEMENT_TYPE));
    } while(new_contents == NULL);

    contents = new_contents;
    contents [top++] = i;

}
void push(ELEMENT_TYPE i){

    if (is_full()) {

        stack_overflow(i);

        // fprintf(stderr, "Stack overflow ");
        // exit(EXIT_FAILURE);

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

ELEMENT_TYPE get_top(void){  // return top element
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

void print_all(void){  // print the whole stack    not used

    printf("bottom -->  ");
    for (int i = 0; i < top; ++i)
        printf("%c  ",  contents[i]);
    printf("<-- top\n");
}

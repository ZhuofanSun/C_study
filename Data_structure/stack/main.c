#include <stdio.h>
#include <stdlib.h>

typedef int E;
 struct Stack{

     E * array;
     int capacity;
     int top; //用top表示栈顶元素的下标（指针），默认是 -1

 };

typedef struct Stack * Arraystack;

_Bool init_stack(Arraystack stack){

    stack->array = malloc(sizeof(struct Stack) * 10); // capacity是10
    if (stack->array == NULL) return 0;
    stack->capacity = 10;
    stack->top = -1;
    return 1;
}




int push(Arraystack stack, E element){

    if(stack->top + 1 == stack->capacity){ //扩容

        int new_capacity = stack->capacity * 2;
        E * new_array = realloc(stack->array, sizeof (E) * new_capacity);
        stack->array = new_array;
        stack->capacity = new_capacity;

    }

    if (stack->top + 2 <= stack->capacity){

        stack->array[stack->top + 1] = element;
        stack->top ++;
        return 0;
    }
    return -1;
}

_Bool is_empty(Arraystack stack) {
    return stack->top == -1;
}

int pop(Arraystack stack){

    if (is_empty(stack)) return -1;
    stack->top --;
    return stack->array[stack->top + 1];


}

int get_size(Arraystack stack){
    return stack->top + 1;
}


void printStack(Arraystack stack){
    printf("| ");
    for (int i = 0; i < stack->top + 1; ++i) {
        printf("%d, ", stack->array[i]);
    }
    printf("\n");
}

int main(){
    struct Stack stack;
    init_stack(&stack);
    for (int i = 0; i < 20; ++i) {
        push(&stack, i*100);
    }
    printStack(&stack);

    while(!is_empty(&stack)){
        pop(&stack);
        printStack(&stack);
    }
}

#include <stdio.h>

int addone(int x);
int addtwo(int x);

int main(void){

    int x = 5;

    printf("================\n");
    printf("Return value of first call of addone(x)=%d\n", addone(x));
    printf("================\n");
    
    printf("Value of x after call to addone=%d\n", x);
    

    printf("================\n");
    printf("Return value of first call of addtwo(x)=%d\n", addtwo(x));
    printf("================\n");
    
    printf("Value of x after call to addtwo=%d\n", x);

    printf("*************************\n");
    printf("Return value of second call of addone(x)=%d\n", addone(x));
    printf("================\n");
    
    printf("Return value of second call of addtwo(x)=%d\n", addtwo(x));

    return 0;
}

int addone(int x){
    int counter = 0;

    printf("In call %d of addone\n",counter);
    counter = counter + 1;

    return x + 1;
}

int addtwo(int x){
    static int counter = 0;

    printf("In call %d of addtwo\n", counter);
    counter = counter + 1;


    return x + 2;
}



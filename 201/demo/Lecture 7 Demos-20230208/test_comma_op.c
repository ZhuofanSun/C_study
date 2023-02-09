#include <stdio.h>

int main(){

    for (int i = 0, j = 0; i <2, j <6; i++, j+=2)
        printf("%d;%d\n", i, j);

    int i = 0, j = 0;
    while (i < 2, j < 6)
    {
        printf("%d;%d\n", i, j);
        i++, j+=2;
    }

}

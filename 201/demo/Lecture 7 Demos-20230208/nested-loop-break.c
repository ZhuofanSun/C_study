//shows the effect of a break statement inside a nested loop
#include <stdio.h>

int main(){
    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <=3; j++){
            if (i != 2)
                printf("%d,%d\n", i, j);
            else
                break;
        }
        printf("End of outer loop\n");
    }
}

/* Shows the effects of short circuit evaluation */

#include <stdio.h>

int main(){
    int i = 7, j = 8, k = 9;
    printf("%d ", (i=j) || (j=k));
    printf("%d %d %d\n", i, j, k);

    return 0;
}

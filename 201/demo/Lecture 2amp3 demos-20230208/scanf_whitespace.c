/* Demonstrate how scanf handles whitespace */

#include <stdio.h>

int main (void) {
    int i, j;
    float x,y;

    printf("Enter values for i,j,x,y:");
    scanf("%d%d%f%f", &i, &j, &x,&y);
    
    printf("The values you entered are i=%d, j=%d, x=%f, y=%f\n", i, j, x, y);

    return 0;
}

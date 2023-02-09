#include <stdio.h>


int main(void) {

    int i;
    float x, y;

    i = 40;
    x = 839.21;
    y = 80.0f;

    printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
    printf("|%10.3f|%10.3e|%-10.4g|\n", x, x, x);
    
    printf("|%10.3f|%10.3e|%-10.2g|\n", y, y, y);
    
    return 0;
}

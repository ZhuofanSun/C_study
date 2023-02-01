#include <stdio.h>

void mulitplyByIndex(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] *= i;
    }
}

int main () {
    int myArray[10] = {1,1,1,1,1,1,1,1,1,1};
    mulitplyByIndex(myArray, 10);
    for (int i = 0; i < 10; i++)
        printf("%d ", myArray[i]);

    printf("\n");
    return 0;
}

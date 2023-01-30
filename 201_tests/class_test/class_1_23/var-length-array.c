#include <stdio.h>

int main(void) {
    int i, n;

    printf("Enter the length of array: ");
    scanf("%d", &n);

    int a[n]; /* declare a length-n array a */

    for (i = 0; i < n; i++) {
        printf("a[%d] has an initial value %d\n", i, a[i]);
    }

    return 0;
}

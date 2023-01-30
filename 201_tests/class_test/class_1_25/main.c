#include <stdio.h>
#include <stdlib.h>

int main() {

    _Bool arr [2][3] = {0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);

        }
    }
    char name[20] = "this is a test";
    printf("%s\n", name);
    printf("%c\n", name[14]);
    printf("%c", '\0');
}

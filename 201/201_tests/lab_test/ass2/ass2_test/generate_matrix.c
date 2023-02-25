#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 7
#define M 7
#define MIN 32
#define MAX 126

int main() {
    char matrix[N][M];
    int i, j;
    srand(time(NULL));

    // Generate the matrix
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            matrix[i][j] = (char) (rand() % 26 + 65);
        }
    }

    // Print the matrix
    printf("The 7x7 matrix is:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }

    // Pick 6 random 5-char strings from the matrix
    char strings[6][6];
    int k, l, x, y, p;
    for (p = 0; p < 6; p++) {
        x = rand() % N;
        y = rand() % M;
        for (k = 0, l = y; k < 5 && l < M; k++, l++) {
            strings[p][k] = matrix[x][l];
        }
    }

    // Print the picked strings
    printf("\nThe 6 random 5-char strings are:\n");
    for (p = 0; p < 6; p++) {
        for (k = 0; k < 5; k++) {
            printf("%c", strings[p][k]);
        }
        printf("\n");
    }

    return 0;
}

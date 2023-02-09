#include <stdio.h>

#define ROWS 2
#define COLUMNS 3

int main(void){

    float reviews[ROWS][COLUMNS];

    printf("Enter the table of papers and reviewers:");
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLUMNS; j++)
            scanf("%f", &reviews[i][j]);

    for(int i = 0; i < ROWS; i++){
        float sum = 0;

        for (int j = 0; j < COLUMNS; j++){
            sum += reviews[i][j];
        }

        printf("Average review for paper %d is %f\n", i, sum/COLUMNS);
    }

    return 0;
}

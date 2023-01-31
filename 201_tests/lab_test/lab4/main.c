#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_walk (int n, int m, char walk[n][m]);
_Bool random_walk (int n, int m, int * curr_row, int * curr_col, char  walk[n][m]);
void print_array(int n, int m, char walk[n][m]);

_Bool random_walk (int n, int m, int * curr_row, int * curr_col, char  walk[n][m]){
    int num_dir = 0, dir_arr[4];  // maximum 4 directions, array used to random choose later
    // 0 is left, 1 is up, 2 is right, 3 is down
    if (*curr_col > 0 && walk[*curr_row][*curr_col-1] == '.'){  // left
        dir_arr[num_dir] = 0;
        num_dir ++;
    }

    if (*curr_row > 0 && walk[*curr_row-1][*curr_col] == '.'){  // up
        dir_arr[num_dir] = 1;
        num_dir ++;
    }
    if (*curr_col < m-1 && walk[*curr_row][*curr_col+1] == '.'){  //  right
        dir_arr[num_dir] = 2;
        num_dir ++;
    }
    if (*curr_row < n-1 && walk[*curr_row+1][*curr_col] == '.'){  // down
        dir_arr[num_dir] = 3;
        num_dir ++;
    }
    if (num_dir == 0) return 0;  // no direction added to array means no position to go

    // randomly choose the possible direction
    int direction = dir_arr[rand() % num_dir];  // index is from 0 to num_dir-1

    switch (direction) {
        case 0:  // left
            walk[*curr_row][*curr_col-1] = walk[*curr_row][*curr_col] + 1;
            (*curr_col) --;
            return 1;
        case 1:  // up
            walk[*curr_row-1][*curr_col] = walk[*curr_row][*curr_col] + 1;
            (*curr_row) --;
            return 1;
        case 2:  // right
            walk[*curr_row][*curr_col+1] = walk[*curr_row][*curr_col] + 1;
            (*curr_col) ++;
            return 1;
        case 3:  // down
            walk[*curr_row+1][*curr_col] = walk[*curr_row][*curr_col] + 1;
            (*curr_row) ++;
            return 1;
        default:  // direction should be [0,3]
            fprintf(stdout, "Error!");

    }
    return 0;
}

void generate_random_walk (int n, int m, char walk[n][m]){
    char letter;
    getchar();  // remove enter from previous, or the next scanf will get an enter char
    printf("Walked until letter: ");
    scanf("%c", &letter);
    printf("\n");

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) walk[i][j] = '.';  // all elements in the 2-d array is initially '.'
    }
    char curr_letter = 'A';
    int  curr_row = 0,  curr_col = 0;
    walk[curr_row][curr_col] = curr_letter;  // start from left top corner, start from 'A'
    while(curr_letter != letter){  // loop end when reach target letter or blocked

        if(random_walk(n, m, &curr_row, &curr_col, walk)){  // return true if walk successfully
            curr_letter = walk[curr_row][curr_col];
        }
        else{
            print_array(n, m, walk);
            printf("Blocked at %c, didn't reach %c\n", curr_letter, letter);  // indicate last letter.
            exit(EXIT_FAILURE);
        }

    }

}

void print_array (int n, int m, char walk[n][m]){

    for (int i = 0; i < n; ++i) {  // for each row
        for (int j = 0; j < m; ++j) printf("%c ", walk[i][j]);  // each column
        printf("\n");

    }

}

int main() {
    
    // initialize the random number generator, seeding by current time,
    // so numbers will be different each time rand() is called
    srand(time(NULL));

    // ask to enter size of the matrix
    int row, column;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &column);

    char walk[row][column];  // initialize this 2-d array
    generate_random_walk(row, column, walk);  // everything to walk on this array
    print_array(row, column, walk);  // print out this array
    

}

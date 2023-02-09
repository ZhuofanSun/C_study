
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    int days_in_month, weekday; 

    if(argc != 3){
        printf("Usage: ./calendar <days in month> <starting day>\n");
        exit(EXIT_FAILURE);
    }

    days_in_month = atoi(argv[1]);
    weekday = atoi(argv[2]);

    for(int i = 1; i < weekday; i++){
        printf("\t");
    }

    for(int i = 1; i <= days_in_month; i++){
        if(weekday == 7){
            weekday = 1;
            printf("\n"); 
        }

        printf("%d\t", i);
        weekday++;
    }
    
    printf("\n");
    
    return 0;
}

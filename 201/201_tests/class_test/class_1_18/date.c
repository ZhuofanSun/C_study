#include <stdio.h>

int main (void) {

    int month, day, year;

    printf("Enter date (mm/dd/yy):");
    scanf("%d/%d/%d", &month, &day, &year);

    switch(day){
    
        case 11:
        case 12:
        case 13:
            printf("Dated this %dth day of ", day);
            break;
        default:
            {
                int rem = day % 10;
                switch(rem){
                    case 1:
                        printf("Dated this %dst day of ", day);
                        break;
                    case 2:
                        printf("Dated this %dnd day of ", day);
                        break;
                    case 3:
                        printf("Dated this %drd day of ", day);
                        break;
                    default:
                        printf("Dated this %dth day of ", day);
                 }
            }      
    }

    switch (month){
        case 1: printf("January, "); break;
        case 2: printf("February, "); break;
        case 3: printf("March, "); break;
        case 4: printf("April, "); break;
        case 5: printf("May, "); break;
        case 6: printf("June, "); break;
        case 7: printf("July, "); break;
        case 8: printf("August, "); break;
        case 9: printf("September, "); break;
        case 10: printf("October, "); break;
        case 11: printf("November, "); break;
        case 12: printf("December, "); break;
    }

    printf("20%.2d\n", year);
    
    return 0;

}


#include <stdio.h>

int main1(){

    int mm, dd, yyyy;
    printf("Enter the date in form mm/dd/yyyy\n");
    scanf("%d/%d/%d", &mm, &dd, &yyyy);

    printf("Today is %d - ", yyyy);
    switch (mm) {
        case 1:
            printf("Jan - ");
            break;
        case 2:
            printf("Feb - ");
            break;
        case 3:
            printf("Mar - ");
            break;

        case 4:
            printf("Apr - ");
            break;

        case 5:
            printf("May - ");
            break;
        case 6:
            printf("Jun - ");
            break;
        case 7:
            printf("Jul - ");
            break;
        case 8:
            printf("Aug - ");
            break;
        case 9:
            printf("Sep - ");
            break;
        case 10:
            printf("Oct");
            break;

        case 11:
            printf("Nov - ");
            break;
        case 12:
            printf("Dec - ");
            break;

    }

    switch (dd) {
    case 1: case 11: case 21: case 31:
            printf("%dst", dd);
            break;

    case 2:case 12: case 22:
        printf("%dnd", dd);
        break;

    case 3: case 13: case 23:
        printf("%drd", dd);
        break;

    default:
        printf("%dth", dd);

    }
    printf("\n\n");
    int i = 5, j = 10, k = 1;
    printf("%d", i < j == j < k);

}



int num_of_digits(int num){

    if (num <= 9 && num >= 0) return 1;
    return 1 + num_of_digits(num / 10);

}


int main(){
    printf("Enter a number: ");
    int num;
    scanf("%d", &num);
    int digits = num_of_digits(num);
    printf("The number %d has %d digits", num, digits);



}
#include <stdio.h>

int main(){
    int input_number;
    int digits_seen[10] = {0};

    printf("Enter a number: ");
    scanf("%d", &input_number);

    int n = input_number;
    int digit;

    while ( n > 0 ){
        digit = n % 10;
        digits_seen[digit] += 1;

        n /= 10; 
    }

    int hasRepeated = 0;

    for(int i = 0; i < 10; i++)
        if (digits_seen[i] > 1){
            printf("%d is repeated %d times\n", i, digits_seen[i]);
            hasRepeated = 1;
        }


    if (!hasRepeated)
        printf("No repeated digit\n");
    return 0;

}

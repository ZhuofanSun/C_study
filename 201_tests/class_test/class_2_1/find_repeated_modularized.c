#include <stdio.h>

void find_repeated(int number, int digits_seen[], int size){
    int digit;

    while ( number > 0 ){
        digit = number % 10;
        if (digit < size)
            digits_seen[digit] += 1;

        number /= 10; 
    }
}

int main(){
    int input_number;
    int digits_seen[10] = {0};

    printf("Enter a number: ");
    scanf("%d", &input_number);

    find_repeated(input_number, digits_seen, 10); 
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

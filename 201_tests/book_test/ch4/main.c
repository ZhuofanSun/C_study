#include <stdio.h>

void reverse_num(int num){

    if (0 <= num && num <= 9) {
        printf("%d", num);
        return;
    }
    printf("%d", num % 10);
    reverse_num(num / 10);

}

void  reverse_num_array(int num, int *arr){

    int index = 0;
    while(num > 10){

        arr[index] = num % 10;
        num /= 10;
        index ++;

    }
    arr[index] = num;

}


int main() {

    printf("Enter a three_digit number: ");
    int num;
    scanf("%d", &num);
    int save = num;
    int rev_num = 0;
    rev_num += (num % 10) * 100;
    num /= 10;
    rev_num += (num % 10) * 10;
    rev_num += num / 10;
    printf("The reversal is: %d\n" , rev_num);
    printf("Another method: ");
    reverse_num(save);
    printf("\n");

    int arr[20];
    reverse_num_array(save,arr);
    printf("Another method: ");
    for (int i = 0; i < 3; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");
    
    char str_arr[20];


}

#include <stdio.h>

int gcd(int a, int b){
    int remain;

    while (remain != 0){
        remain = a % b;
        a = b;
        b = remain;

    }
    return a;



}





int main() {
    /*
    _Bool flag = 1;
    float max = 0;
    float num;

    while (flag){

        printf("Enter a number: ");
        scanf("%f", &num);

        if (num <= 0) {flag = 0; break;}

        else if(num > max) max = num;

    }

    printf("The largest number entered wae %f", max);


    return 0;

     */

    printf("%d 和 %d 的最大公因数是：%d", 10, 3, gcd(10, 4));

}

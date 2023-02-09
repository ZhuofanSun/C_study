#include <stdio.h>

int main(void){

    int value;
    float commission = 0;

    printf("Enter value of trade:");
    scanf("%d", &value);

    if(value < 2500){
        commission = 30 + 0.017f*value;

        if(commission < 39)
            commission = 39;
    }else if (value < 6250){
        commission = 56 + 0.0066f*value;
    }else if(value < 20000){
        commission = 76 + 0.0034f*value;
    }else if (value < 50000){
        commission = 100 + 0.0022f*value;
    }else if (value < 500000){
        commission = 155 + 0.0011f*value;
    }else{
        commission = 255 + 0.0009f*value;
    }

    printf("Value of commission is %.1f\n", commission);

    return 0;
}

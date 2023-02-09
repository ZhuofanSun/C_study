/* demonstrate the difference between break and continue */

#include<stdio.h>

#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f / 9.0f)

int main(void) {

    float fahrenheit, celsius;

    while (1) {
        printf("Enter Fahrenheit temperature (non-number to quit): ");
        if(scanf("%f", &fahrenheit) == 1){
            celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;
            printf("Celsius equivalent: %.1f\n", celsius);
        }else
            break;
        
    }

    return 0;
}

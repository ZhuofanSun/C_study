/* Converts a Fahrenheit temperature to Celsius */

#include <stdio.h>

#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f / 9.0f)

int main(void) {

    float fahrenheit, celsius;

    /*for (;;) {
        printf("Enter Fahrenheit temperature (non-number to quit): ");
        if (scanf("%f", &fahrenheit) == 1) {
            celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;
            printf("Celsius equivalent: %.1f\n", celsius);
        } else
            break;
        }
        */
    char  str[200];
    char *str_return = fgets(str, 100, stdin);
    printf("%s", str_return);
    printf("\n%s", str);
    return 0;
}
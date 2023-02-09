/* Computes the dimensional weight of 12'' * 10'' * 8'' box */
#include <stdio.h>
#include <math.h>

#define INCHES_PER_POUND 166.0f

int main(void){
    int length, width, height;
    float volume, weight;

    printf("Enter length of the box: ");
    scanf("%d", &length);

    printf("Enter width of the box: ");
    scanf("%d", &width);

    printf("Enter height of the box: ");
    scanf("%d", &height);

    volume = length * width * height;
    weight = ceil(volume / INCHES_PER_POUND);

    printf("Dimensions of the box are: %dx%dx%d\n", length, width, height);
    printf("Volume (cubic inches): %.2f\n", volume);
    printf("Dimensional weight (pounds): %.2f\n", weight);

    return 0;
}

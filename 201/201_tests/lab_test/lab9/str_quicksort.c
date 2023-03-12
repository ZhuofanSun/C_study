#include "str_quicksort.h"

void quicksort(char* a[], char **low, char **high){

    char **middle;

    if (low >= high)
        return;

    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

char **split(char * a[], char **low, char **high){

    char *part_element = *low;

    for(;;){  // Infinite loop

        while (low < high && part_element <= *high)  // stop when element < part_element
            high --;

        if(low >= high)
            break;

        *low = *high;  // put the element to the left
        low ++;

        while (low < high && *low <= part_element)  // stop when element > part_element
            low++;

        if (low >= high)
            break;

        *high = *low;  // put the element to the right
        high --;
    }

    *high = part_element;  // put part_element

    return high;
}

_Bool lte(char * a, char * b){
    int



}



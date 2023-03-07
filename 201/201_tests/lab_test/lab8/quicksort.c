#include "quicksort.h"


void quicksort(int a[], int *low, int *high){

    int *middle;

    if (low >= high)
        return;

    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

int *split(int a[], int *low, int *high){

    int part_element = *low;

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

#include "str_quicksort.h"

_Bool lte(const char * a, const char * b){
    int index = 0;
    while (a[index] != '\0' && b[index] != '\0'){
        if (a[index] == b[index]){
            index ++;
        }
        else if ('A' <= a[index] && a[index]<= 'Z'){
            if ('A' <= b[index] && b[index]<= 'Z'){
                if (a[index] - 'A' + 'a' < b[index]- 'A' + 'a'){
                    return 1;
                }
                else if (a[index] - 'A' + 'a' == b[index]- 'A' + 'a'){
                    index ++;
                }
                else{
                    return 0;
                }
            }
            else{
                if (a[index] - 'A' + 'a' < b[index]){
                    return 1;
                }
                else if (a[index] - 'A' + 'a' == b[index]){
                    index ++;
                }
                else{
                    return 0;
                }
            }

        }
        else if ('A' <= b[index] && b[index]<= 'Z'){
            if (a[index] < b[index] - 'A' + 'a'){
                return 1;
            }
            else if (a[index] == b[index] - 'A' + 'a'){
                index ++;
            }
            else{
                return 0;
            }
        }
        else if (a[index] < b[index]){
            return 1;
        }
        else if (a[index] > b[index]){
            return 0;
        }
        else
            break;
    }

    if (a[index] == '\0'){  // a==b
        return 1;
    }
    else {
        return 0;
    }

}

char **split(char * a[], char **low, char **high){

    char *part_element = *low;

    for(;;){  // Infinite loop

        while (low < high && lte(part_element, *high))  // stop when element < part_element
            high --;

        if(low >= high)
            break;

        *low = *high;  // put the element to the left
        low ++;

        while (low < high && lte(*low, part_element))  // stop when element > part_element
            low++;

        if (low >= high)
            break;

        *high = *low;  // put the element to the right
        high --;
    }

    *high = part_element;  // put part_element

    return high;
}

void quicksort(char* a[], char **low, char **high){

    char **middle;

    if (low >= high)
        return;

    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

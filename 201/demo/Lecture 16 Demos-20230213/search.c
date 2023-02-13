#include <stdio.h>
#include <limits.h>

void find_largest(int array[], int size){

    int start = 0, end = size - 1;
    int largest = INT_MIN;

    while(end > start){
        if(array[end] > largest)
            largest = array[end];
        
        if(array[start] > largest)
            largest = array[start];
            
        end +=1;
        start += 1;
    }

    printf("largest=%d\n", largest);
}


int main(){
    int array[] = {1,10,4,40,2,3,9,2,9,10};

    find_largest(array, 10); 

}

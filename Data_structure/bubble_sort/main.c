#include <stdio.h>
//冒泡排序

void bubble_sort(int arr[], int len){

    for (int i = 0; i < len - 1; ++i) {
        _Bool flag = 1;
        for (int j = 0; j < len - i - 1; ++j) {
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 0;
            }
        }
        if(flag) return;//没发生排序说明已经是从小到大了=
    }
}


int main(){
    int arr[10] = {1, 5,0,2,6,9,8,3,4,7};
    for (int i = 0; i < 10; ++i) {

        printf("%d  ", arr[i]);


    }
    bubble_sort(arr, 10);
    printf("\n");
    for (int i = 0; i < 10; ++i) {

        printf("%d  ", arr[i]);


    }

}


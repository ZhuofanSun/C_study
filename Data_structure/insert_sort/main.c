#include <stdio.h>
//插入排序
//https://visualgo.net/zh/sorting
void insert_sort(int arr[], int len){

    for (int i = 1; i < len; ++i) {

        int j = i - 1;
        while(j >= 0 ){//循环结束找到的是arr[i]改放到的位置

            if(arr[j] > arr[j+1]) {

                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                j--;

            }
            else break;
        }
    }
}


int main(){
    int arr[10] = {5,0,1,8,2,7, 3,9,4,6};
    int len = 10;
    for (int i = 0; i < len; ++i) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    insert_sort(arr, len);
    for (int i = 0; i < len; ++i) {
        printf("%d  ", arr[i]);
    }

}
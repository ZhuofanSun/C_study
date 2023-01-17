#include <stdio.h>
//https://visualgo.net/zh/sorting

int find_mini_index(const int arr[], int start, int end){

    if(end == start) return start;
    int mini_index = start;

    for (int i = start+1; i <= end; ++i) {

        if(arr[mini_index] > arr[i]) mini_index = i;

    }
    return mini_index;

}

void exchange(int arr[], int a, int b){

    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;

}

void selection_sort(int arr[], int len){

    for (int i = 0; i < len-1; ++i) {

        int mini_index = find_mini_index(arr, i, len-1);
        exchange(arr, i,mini_index);

    }

}

void print_arr(int arr[], int len){

    for (int i = 0; i < len; ++i) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[10] = {5,0,1,8,2,7, 3,9,4,6};

    int len = 10;

    print_arr(arr, len);
    selection_sort(arr, len);
    print_arr(arr, len);

}
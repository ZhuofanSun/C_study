#include <stdio.h>
//快速排序
void quick_sort(int arr[], int left, int right){
    if (left >= right) return;

    int low = left;
    int high = right;
    int base = arr[low];

    while (low < high){
        while (low < high && arr [high] >= base) high -= 1;
        arr[low] = arr[high];

        while(low < high && arr[low] < base) low += 1;
        arr[high] = arr[low];
    }

    arr[low] = base;
    quick_sort(arr, left, low - 1);
    quick_sort(arr, low + 1, right);
}


int main() {
    int arr[] = {4, 3, 8, 2, 1, 7, 5, 6, 9, 0};
    quick_sort(arr, 0, 9);  //10个数字下标就是0-9
    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
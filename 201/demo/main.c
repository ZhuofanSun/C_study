#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//【辗转相除法-原理-哔哩哔哩】 https://b23.tv/cSy0HYX

int greatest_common_divisor(int num, int denom){
    /*  这个方法也太蠢了
    int smaller_num = num;
    if (smaller_num > denom)

        smaller_num = denom;
    for (int i = smaller_num; i > 0; --i) {
        if (num % i == 0 && denom % i == 0){
            return i;
        }
    }
    return 1;
     */

    // 辗转相除法
    // 原理： GCD(a, b) == GCD(b, a%b)
    if (num % denom == 0)
        return denom;
    else
        return greatest_common_divisor(denom, num%denom);

}


void arr_exchange(int arr[], int i, int j){
    if (i != j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int partition(int arr[], int p, int r){

    int pivot = arr[r];
    int i = p - 1;
    int count_equal = 0;
    for (int j = p; j < r; ++j) {
        if (arr[j] < pivot){  // 小于pivot正常推进
            arr_exchange(arr, ++i, j);  // exchange index i with index j
        }
        else if (arr[j] == pivot){
            count_equal ++;
        }
    }
    if (count_equal == r - p){
        return (r + p) / 2;
    }
    arr_exchange(arr, ++i, r);
    return i;
}



void quicksort(int arr[], int p, int r){
    if (p < r) {

        int q = partition(arr, p, r);
        quicksort(arr, p, q-1);
        quicksort(arr, q+1, r);
    }

}

int get_size(const int arr[], int capacity){
    int size = 0;
    for (; size < capacity; size++) {
        if (arr[size]==0){
            break;
        }
    }
    return size;
}

int main(int argc, char **argv) {
/*
    int num1, denom1, num2, denom2, result_num, result_denom;

    printf("Enter first fraction: ");
    scanf("%d/%d", &num1, &denom1);

    printf("Enter second fraction: ");
    scanf("%d/%d", &num2, &denom2);

    result_num = num1 * denom2 + num2 * denom1;  // 交叉相乘求和，是未化简分子
    result_denom = denom1 * denom2;  // 分母相乘， 是未化简分母
    ////////////////////////试图加入化简//////////////////////////////////

    int gcd = greatest_common_divisor(result_num, result_denom);
    result_num /= gcd;
    result_denom /= gcd;

    if (result_num % result_denom == 0)
        printf("The sum is %d\n", result_num / result_denom);
    else
        printf("The sum is %d/%d\n", result_num, result_denom);
    printf("最大公约数是：%d", gcd);
    ////////////////////////试图加入化简//////////////////////////////////
    printf("\n%u", -1);
    return 0;
}
*/

    int arr[20] = {9,4,6,1,3,2,8, 5, 7};
    int capacity = sizeof (arr) / sizeof (arr[0]);
    int size = get_size(arr, capacity);

    quicksort(arr, 0, size - 1);

    for (int i = 0; i < size; ++i) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
#include <stdio.h>
//二分检索是基于顺序数组的查找
//https://visualgo.net/zh/sorting

  //扣扣哇  遍历  desu非常的垃圾，时间复杂度是O(n)
int search(int * nums, int numsSize, int target){
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == target){
            return i;
        }

    }
    return (int) -1;
}

//  扣扣哇  二分检索  desu，非常的牛逼，时间复杂度是O(log n)
int binary_search(int * nums, int target, int left, int right){
    if (right < 0 || left < 0) return (int) -1;
    if (right == left) {
        if (nums[right] == target) return right;
        else {return (int)-1;}
    }
    int mid = (right + left) / 2;
    if (nums[mid] == target) return mid;
    else if (target < nums[mid]) return binary_search(nums, target, left, mid - 1);
    else if (target > nums[mid]) return binary_search(nums, target, mid + 1, right);
    }



int main() {
    int arr[] = {1, 3, 4, 6, 7,8, 10, 11, 13, 15}, target = 2;
    printf("search 是：%d\n", search(arr, 10, target));
    printf("binary_search 是：%d\n", binary_search(arr, target, 0, 9));
}


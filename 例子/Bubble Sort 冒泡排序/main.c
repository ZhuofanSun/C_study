#include <stdio.h>
int main() {
    int arr[10] = {3, 5, 7, 2, 9, 0, 6, 1, 8, 4};  //乱序的
    //请编写代码对以上数组进行排序
    for (int i = 0; i < 9; i++){  // 一共10个数比较9次就够
        _Bool flag = 0;
        for (int j = 1; j < 10 - i; ++j) {  // 每一轮结束第10-i个一定比前面所有的都大
            if (arr[j] < arr[j - 1]){

                int temp = arr[j-1];
                arr[j -1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }

        }
        if  (!flag) break;
    }

    for (int z = 0; z < 10; ++z){

        printf("  %d", arr[z]);
    }
}


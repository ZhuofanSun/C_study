#include <stdio.h>

int main() {
    int i = 1;
    int j = 1;
    int fst = i + j;
    int snd = fst + j;
    printf("%d  %d  %d  %d  ", i,j,fst,snd);
    while (fst < 200){
        fst += snd;
        snd += fst;
        printf("%d  %d  ", fst, snd);


    }
    printf("\n\n/////////////////////////////数组F////////////////////////////////////\n\n");


    int ii = 7;  // 想要输出斐波那契数列的第几位
    int arr[ii];
    arr[0] = 1;
    arr[1] = 1;
    for (int k = 3; k <= ii; ++k) {
        arr[k-1] = arr[k-2] + arr[k-3];  // 类似于递归
    }
    printf("斐波那契数列第%d位是：  %d",ii, arr[ii-1]);




}

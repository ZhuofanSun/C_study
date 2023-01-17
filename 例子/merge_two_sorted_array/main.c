/**
 * 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
示例 1：
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
 */


#include <stdio.h>





int main() {
    int m = 3, n = 3;
    int p1[] = {1, 2, 3, 0, 0, 0}, p2[] = {2, 5, 6};
    int (* nums1)= p1, (* nums2) = p2;
    int i = m-1, j = n-1 ;
    for (int k = m+n-1; k >= 0 ; --k) {
        if (i >= 0 && j >= 0 && *(nums1 + i) > *(nums2 + j)){
            *(nums1 + k) = *(nums1 + i);
            i -=1;
        }
        else if (i >= 0 && j >= 0 && *(nums1 + i) <= *(nums2 + j)){
            *(nums1 + k) = *(nums2 + j);
            j -= 1;
        }
        else if(j < 0 && i >= 0){
            *(nums1 + k) = *(nums1 + i);
            i -= 1;
        }
        else{
            *(nums1 + k) = *(nums2 + j);
            j -= 1;
        }
    }
    for (int k = 0; k <= 5; ++k) {
        printf("%d  ", nums1[k]);
    }

}

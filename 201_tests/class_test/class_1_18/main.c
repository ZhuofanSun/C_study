#include <stdio.h>

int main() {
    _Bool flag = 1;  // 1 是true  0 是false

    if (flag) {
        printf("hello ");
        flag = 0;
    }

    if (!flag) printf("world\n");

    int i = 10;
    int j = 2;
    if ((i == 10) || (j < 5)){  // 在or中如果前一个表达式是True，后一个就不判断了

        printf("True\n");

    }

    if ((i != 10) && (j < 5)) printf("False\n");  // 在and中如果前一个表达式是False，后一个就不判断了

    int p = -1;
    int q = 2;
    if ((p < 0) && ( ++q > 2)){
        p ++;
        printf("%d  %d\n", p, q);

    }
    printf("\n");
    printf("/////////////////////////////////////逻辑与的优先级///////////////////////////////////////////////////\n\n");

    int ii  = 7, jj = 8, kk = 9;
    printf("%d  ", (ii=jj) || (jj=kk));  // 赋值操作返回1， 逻辑或中(||)前面是true后面不执行，jj=kk不执行  1
    printf("jj == %d  jj == %d  kk == %d\n", ii, jj, kk);  // 8  8  9

    ii > jj ? ii-- : jj++;
    /*
     * if (i > j)
     *      i --;
     *  else
     *      j++;
     */
    printf("i == %d  jj == %d\n", ii, jj);

    int test_integer = 0;


}

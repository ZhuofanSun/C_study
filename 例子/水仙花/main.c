#include <stdio.h>

/**
 *“水仙花数（Narcissistic number）也被称为超完全数字不变数（pluperfect digital invariant, PPDI）、
 * 、自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），
 * 水仙花数是指**一个 3 位数，它的每个位上的数字的 3次幂之和等于它本身。**例如：1^3 + 5^3+ 3^3 = 15
 *
 */
int main(){
    for (int i = 100; i < 1000; ++i) {
        int a = i % 10, b = i / 10 % 10, c = i / 100 % 10;
        if (a * a * a + b * b * b + c * c * c == i){
            printf("\n%d",i);
    }
    }


    /**
    int i = 100;
    while (i < 1000){
        int j = i;
        int trd = j % 10;
        j /= 10;
        int snd = j % 10;
        j /= 10;
        int fst = j % 10;
        int t = 1;
        int s = 1;
        int f = 1;
        for (int k = 0; k < 3; ++k) {
            t *= trd;
            s *= snd;
            f *= fst;
        }
        int k = t + s + f;
        if (k == i){
            printf("\n%d", i);
        }
        i ++;

    }

**/

}
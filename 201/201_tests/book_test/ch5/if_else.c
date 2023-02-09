#include <stdio.h>
# define True 1
# define False 0

int main() {
    int a;
    scanf("%d", &a);

    // a == 10 ? a ++ :  a --;  // 如果a等于10，a++，否则a--

    if (a == 10) a ++;  // 和上面效果相同
    else a -- ;

    printf("%d", a);
    return 0;


}

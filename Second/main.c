#include <stdio.h>
#include "if使用.c"
#include "for使用.c"
#include "stringg.c"
int main() {

    int i = 0;
    if (i == 0){
        printf("%d", i);
    }
    else{
        printf("LBWNB");
    }

    char c = 'B';
    switch (c) {  //这里目标就是变量c
        case 'A':    //分别指定ABC三个匹配值，并且执行不同的代码
            printf(""
                   "\n去尖子班！准备冲刺985大学！");
            break;   //执行完之后一定记得break，否则会继续向下执行下一个case中的代码
        case 'B':
            printf("\n去平行班！准备冲刺一本！");
            break;
        case 'C':
            printf("\n去职高深造。");
            break;
    }
    printf("\n\n////////////////////////////////////////////for 的使用/////////////////////////////////////\n");
    for (int ii = 0; ii < 4; ++ii) {
        printf("\n卢本伟牛逼");
    }
    printf("\n\n提前中断for --> break");
    for (int j = 0; j < 7; ++j) {
        if (j == 3){
            printf("\ncontinue");
        }
        if (j == 3) continue; // 会跳过这个循环后面的内容
        if (j == 5) {
            printf("\nbreak");
        };
        if (j == 5) break;// 提前终止
        printf("\n%d",j);
    }
    printf("\n\n算3的3次方\n");
    int u = 3, res = 1;
    for (int j = 0; j < 3; ++j) {
        res *= u;
    }
    printf("%d", res);
    printf("\n\n////////////////////////////////////////////while 的使用/////////////////////////////////////\n");

    int z = 0;
    while (z < 11){
        if (z == 10) break;  // 同样可以提前终止和加速
        //if (z == 8) continue;  // 加速会导致z永远不加1，无限循环
        printf("%d ",z);
        z ++;
    }
    printf("\n");
    int f = 0;
    do{
        printf("%d ", f);
        f ++;
    } while (f < 11);
    printf("\n\n////////////////////////////////////////////数组 的使用/////////////////////////////////////\n");

    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (i = 0; i <= 11; i ++){
        if (arr[i] < 30){
            printf("\n %d 月有 %d 天",i+1,arr[i]);
        }

    }
    printf("\n\n////////////////////////////////////////////多维数组 的使用/////////////////////////////////////\n");

    int arrr[2][2] = {{1,2},{3,4}};
    printf("%d",arrr[0][1]);


    printf("\n\n////////////////////////////////////////////字符串/////////////////////////////////////\n");

    char str[] = {
            'H','e','l','l','o','\0'
    }; //必须加一个'\0'字符来表示结束
    printf("%s", str);  // %s作为一个字符串输出

    char sstr[] = "好耶";  //双引号表示字符串
    printf("\n%s",sstr);

    printf("\n\n//////////////////////////////////scanf、gets、puts函数///////////////////////////\n");
    /**
    float i_int;
    scanf("%f",&i_int) ;
    printf("%f",i_int);

     **/
    /**
    //get和puts是字符串专用函数
    char sssstr[20];
    gets(sssstr);
    puts(sssstr);
     **/
     /**
    char cc;
    cc = getchar();  //输入一个字符，不是字符串
    printf("%c", cc);
    **/

}

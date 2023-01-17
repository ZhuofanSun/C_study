#include <stdio.h>
#include "变量.c"
#include "基本格式和数据类型.c"
#include "类型转换.c"
#include "运算符.c"
int main() {  //#include<stdio.h> int main(){} 是程序基本格式
    printf("Hello World");  // 注意加英文分号, 输出内容中有分号要转译
    int a=10;
    int b = 20;
    int c = a +b;
    double d = 2.3;
    float e = 2.5f;  //数字后加f就变成了float
    printf("\n%d",c);  //printf接受的第一个parameter只能是字符，所以只能替换
    printf("\n%.1lf",d);  //不是四舍五入，直接删除一位以后的
    char g = 'a'; //char只能写一个，多写是字符串
    char i = 70;  //char 接数字是第21位ASCII码对应的字符
    char k = 10;  //第十位ASCII码是换行符
    char z = '\\';  //第一个反斜杠表示转译，所以\\表示一个反斜杠
    printf("%c%c%c",k,i,z);
    const int jjj = 20; // i就不能改了，只能使用
    // char占一个字节 -- 8个bit位--第一符号后七位表示二进制：-128～127

    unsigned char kkk = 128;  // 无符号数可以超过127
    printf("\n%u",kkk);
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //举例
    unsigned char ccc = -65;   //数据类型前面添加unsigned关键字表示采用无符号形式
    printf("\n%u", ccc);    //%u以无符号形式输出十进制数据
    // -65转补码是10111111，无符号形式就是二进制10111111 ---> 191
    int aa = 511;
    char bb = aa; //最大127
    printf("\nint 511 转换 chr: %d",bb);  // int四个字节，char一个，int转换成char会舍弃前三个字节

    //小数转整数会丢失小数部分
    double double_num = 3.14;
    int int_num = double_num;
    printf("\ndouble 3.14 转换 int： %d", int_num);
    printf("\n////////////////////////////////");
    //看类型转换.c
    // 自动转换
    float aaaa = 2;
    int bbbb = 3;
    double cccc = bbbb/ aaaa;
    printf("\nint 3 / float 2 = double %lf",cccc);
    // 优先级看类型转换.c
    // float先自动转换成double，double/int结果是高优先级的-->double
    int a_2 = 10;
    int b_2 = 3;
    double c_2 = a_2/b_2;
    printf("\nint 10 / int 3 = double %lf", c_2); // int/int结果是int--> 3.333被转换成3，
    // 然后定义c是double类型 --> int 3 被转换成double类型--> 3.000000
    /////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n//////////////////////////////");
    //强制类型转换：
    /**
    * (强制类型转换类型) 变量、常量或表达式；
    */
    double x = 3.3;
    int qiangzhi_a = (int)(10.5+x); // <--用来提升优先级，10.5是double，强制类型转换没有黄标, 括号运算和数学一样
    printf("\n（double 3.3 + double 10.5 ）强制转换int = int %d",qiangzhi_a);

    /////////////////////////////////////////运算符//////////////////////////////////////////////
    //运算符.c
    ////////////////////////////////////////自增自减运算符///////////////////////////////////////
    printf("\n\n/////////////////////////////////////////");
    printf("\n");

    int zizeng_a1 = 1;
    int jieguo_b1 = ++zizeng_a1;
    printf("a = 1");
    printf("\nb = ++a --> b = %d", jieguo_b1);
    printf("\nb = ++a --> a = %d", zizeng_a1);
    printf("\n\n/////////////////////////////////////////");
    printf("\n");

    int zizeng_a2 = 1;
    int jieguo_b2 = zizeng_a2++;
    printf("a = 1");
    printf("\nb = a++ --> b = %d", jieguo_b2);
    printf("\nb = a++ --> a = %d", zizeng_a2);
    //自减： "--a"和"a--" 和自增法则一样
    // "+=", "-="， "%=", "/="都存在
    // a %= 3 <=>a = a % 3
    ////////////////////////////////////////位运算符///////////////////////////////////////
    printf("\n\n/////////////////////////////////////////");
    printf("\n");

    int wei_a = 10;
    wei_a = wei_a << 1;
    printf("\n10 左移一位： %d", wei_a);
    wei_a <<= 1;
    // int a = 10 --> a = 00001010
    // a <<= 1 --> a = 00010100 = 20
    printf("\n20 左移一位： %d", wei_a);
    wei_a <<= 1;
    printf("\n40 左移一位： %d", wei_a);
    wei_a >>= 3;
    printf("\n\n80 右移三位： %d", wei_a);
    wei_a >>= 1;
    printf("\n10 右移一位： %d", wei_a);

    printf("\n\n///////////////////按位 与, 或，异或(否), 取反 操作//////////////////\n\n");
    int yu_a = 4;
    int yu_b = 6;
    int yu_c = yu_a & yu_b;
    printf("4 & 6: %d", yu_c);
    // 4: 00000100
    // 6: 00000110
    // 4 & 6: 00000100 --> 4
    printf("\n");
    int huo_a = 4;
    int huo_b = 6;
    int huo_c = huo_a | huo_b;
    printf("\n4 | 6: %d", huo_c);
    // 4: 00000100
    // 6: 00000110
    // 4 & 6: 00000110 --> 6
    printf("\n");
    int yihuo_a = 4;
    int yihuo_b = 6;
    int yihuo_c = yihuo_a ^ yihuo_b;
    printf("\n4 ^ 6: %d", yihuo_c);
    // 4: 00000100
    // 6: 00000110
    // 4 & 6: 00000010 --> 2
    printf("\n");
    int qufan_a = 0;
    printf("\n ~0: %d", ~qufan_a);
    // 0: 00000000
    // ~0: 11111111 --> 二进制补码转十进制：先减一，除了符号取反，二进制转十进制---> 10000001 = -1

    /////////////////////////////////////////逻辑运算符//////////////////////////////////////////////
    printf("\n\n//////////////////逻辑运算符////////////////");
    printf("\n");
    int luoji_a = 10;
    _Bool luoji_c = luoji_a < 0;    //我们现在想要判断a的值是否小于0，我们可以直接使用小于符号进行判断，最后得到的结果只能是1或0
    _Bool luoji_d = luoji_a > 0;
    //虽然结果是一个整数，但是这里推荐使用_Bool类型进行接收，它只能表示0和1（更加专业一些）
    printf("c = %d", luoji_c);
    printf("\nd = %d\n", luoji_d);
    int mod = 1740983 % 35;
    printf("mod is %d\n", mod);



}
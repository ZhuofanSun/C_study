/**
* #define    宏名(记号)    内容

 *#define PI 3.1415926
 * 是纯文本替换，就是相当于把程序里的PI全部删掉，换成3。14.....
* # define MUL(x) x*x // 替换x
 *     printf("%d\n", MUL(9)); ------> 81
 *     # define TEST(n) x##n  //会把x和接收到的n拼接
 *     取消定义：
 *     # undef 宏名
 *     宏的判定:
#ifdef PI//如果PI被定义了
#define MM = 111//定义M
#else//没定义PI
#define MM  999 //定义M
    //结束判定
# endif

#ifndef PI//如果PI没有被定义
#define MMM = 999
#endif
*/
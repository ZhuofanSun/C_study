#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void ex_1(){
    //题目：有 1、2、3、4 四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
    //程序分析：可填在百位、十位、个位的数字都是 1、2、3、4，组成所有的排列后再去掉不满足条件的排列。
    int size = 0;

    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            for (int k = 1; k < 5; ++k) {
                if(i!=j && i!=k && j!=k) {

                    size ++;
                    int num = 100 * i + 10 * j + k;
                    printf("第 %d 个是： %d\n", size, num);

                }

            }

        }

    }


}

void ex_2(){
    //题目：企业发放的奖金根据利润提成。
    //利润(profit)低于或等于10万元时，奖金可提10%；
    //利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
    //20万到40万之间时，高于20万元的部分，可提成5%；
    //40万到60万之间时高于40万元的部分，可提成3%；
    //60万到100万之间时，高于60万元的部分，可提成1.5%；
    //高于100万元时，超过100万元的部分按1%提成。
    //从键盘输入当月利润I，求应发放奖金总数？
    //程序分析：请利用数轴来分界，定位。注意定义时需把奖金定义成双精度浮点(double)型。
    double profit = 0, bonus = 0;
    printf("利润是多少万： ");
    scanf("%lf", &profit);
    printf("\n");

    if(profit <= 10){
        bonus = profit * 0.1;
        
    }else{ //profit > 10

        bonus += 10 * 0.1;

        if(profit<=20){ //10 < profit <= 20

            bonus += (profit - 10) * 0.075;

        }else{ //profit > 20

            bonus += 10 * 0.1;

            if(profit<=40){ //20 < profit <= 40

                bonus += (profit - 20) * 0.05;

            }else{ //profit > 40

                bonus += 20 * 0.05;

                if(profit<=60){ //40 < profit <= 60

                    bonus += (profit - 40) * 0.03;
                    
                } else{ //profit > 60

                    bonus += 20 * 0.03;

                    if(profit<=100){ //60 < profit <= 100
                        bonus += (profit - 60) * 0.015;
                        
                    }else{ //profit > 100

                        bonus += 40 * 0.015;
                        bonus += (profit - 100) * 0.01;
                        
                    }
                    
                }
                
            }
            
        }
    }

    printf("bonus = %lf", bonus);
}


_Bool check_number(char * str1, char *str2){
    int len1 = (int)strlen(str1), len2 = (int) strlen(str2);
    for (int index1 = 0; index1 < len1; ++index1) {
        if (!isdigit(str1[index1])){
            return 0;
        }
    }
    for (int index2 = 0; index2 < len2; ++index2) {
        if (!isdigit(str2[index2])){
            return 0;
        }
    }

    int num1 = (int)atoi(str1), num2 = (int)atoi(str2);
    if (num1 > num2){
        return 0;
    }

    return 1;
}

_Bool check_alpha(char * str1, char *str2){
    // 全大写返回-1， 全小写返回-2，错误返回0。
    int len1 = (int)strlen(str1), len2 = (int) strlen(str2);
    if (len1 !=1 || len2 != 1){
        return 0;
    }

    int flag1 = 0, flag2 = 0;
    if (isupper(*str1)){
        flag1 = -1;
    }
    else if (islower(*str1)){
        flag1 = -2;
    }
    else{
        return 0;
    }

    if (isupper(*str2)){
        flag2 = -1;
    }
    else if (islower(*str2)){
        flag2 = -2;
    }
    else{
        return 0;
    }

    if (flag1 != flag2){
        return 0;
    }
    if (*str1 > *str2){
        return 0;
    }

    return 1;
}


void println(){
    // 随表刷B站看到的，加了一些检查
    // 要求输入 "X-X" X替换成数字或者字母，打印从第一个字符到第二个字符之间所有的
    // 比如输入 0-5 就打印 0 1 2 3 4 5， a-d 就打印 a b c d

    char str1[100], str2[100];
    int i = 0;
    char letter;
    while ((letter = (char)fgetc(stdin)) != '-' && letter != '\n') {

        str1[i++] = letter;

    }
    str1[i] = '\0';
    if (letter == '\n') {
        fprintf(stderr, "shit!!!\n%s", str1);
        exit(1);
    }
    i = 0;
    while ((letter = (char)fgetc(stdin)) != '\n'){

        str2[i++] = letter;

    }
    str2[i] = '\0';
    printf("str1: %s\nstr2: %s\n", str1, str2);
    if (check_number(str1, str2)){
        for (int j = atoi(str1); j <= atoi(str2); ++j) {
            printf("%d ", j);
        }
        printf("\n");
    }
    else if (check_alpha(str1, str2)){
        for (int j = (int)*str1; j <= (int)*str2; ++j) {
            printf("%c ", j);
        }
        printf("\n");
    }
    else {
        fprintf(stderr,"shit!!\n");
        fprintf(stderr,"%s-%s\n", str1, str2);
        exit(EXIT_FAILURE);
    }

}

int main() {
    //ex_1();
    //ex_2();
    println();

    return 0;
}

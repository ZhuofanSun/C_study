#include <stdio.h>



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



int main() {
    //ex_1();
    //ex_2();
    return 0;
}

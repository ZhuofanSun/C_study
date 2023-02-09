#include <stdio.h>
/*
int main() {

    int height = 8;
    int length = 12;
    int width = 10;
    float profit = 123.888f; // 默认是double，添加f就没有警告了
    printf("%.3f\n", profit);
    int input;
    printf("随便输入个数：  ");
    scanf("%d", &input);
    printf("%d\n", input);

    printf("///////////////////////////////////\n");
    printf("%lu", sizeof (int));



}

*/
#define PI 3.14159
/*
void exponential(float * x, int exp){
    float k = *x;
    for (int i = 1; i < exp; ++i) {
        *x = (*x) * k;
    }
}
float exponential_x(float x, int exp){

    float answer;
    if (exp == 0) return 1;
    if (exp == 1) return x;
    answer = x;
    for (int i = 1; i < exp; ++i) {
        answer *= x;
    }
    return answer;

}
*/

int main(){
    /*
    float vol;
    printf("输入半径：");
    int radius;
    scanf("%d", &radius);
    vol = (4.0f/3.0f) * PI * radius;
    printf("%.3f\n", vol);
    float test = 3.0f/4.0f; //3/4 除号两侧都是int，优先级就是int，最终以int输出：0
    printf("%f", test);
     */
    /*
    printf("enter the amount:  ");
    float val;
    scanf("%f", &val);
    float with_tax = val * 1.05f;
    printf("With tax added: %.2f", with_tax);
    */

/*
    float x;
    printf("enter the value of x:");
    scanf("%f", &x);
x
    printf("answer is: %f", 3*exponential_x(x,5)+2* exponential_x(x,4)-5* exponential_x(x,3)- exponential_x(x,2)+7*x-6 );

*/

int twenty = 0, ten = 0, five = 0, one = 0;
int dollar;
    printf("please enter the amount: ");
    scanf("%d", &dollar);
    twenty += dollar / 20;
    ten += (dollar % 20) / 10;
    five += (dollar % 20 % 10) / 5;
    one += (dollar % 20 % 10 % 5) /1;
    if (twenty*20 + ten*10 + five*5 + one == dollar){

        printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d\n", twenty,ten,five,one);

    }


}
#include <stdio.h>

int main() {
    float i = 123.456f;
    int k = (int) i;
    printf("%d\n", k);
    printf("||%5.4d||\n", 322); //右对齐，一共占五个字符的位置，保留至少3位有效数字，不够3位用0
    printf("||%-5d||\n", 30);
    printf("''\n"); // printf单引号
    printf("\"\"\n"); // printf双引号
    printf("\\\n"); // printf \, 不能单独放一个\在双引号里

    int a = 10;
    int b = 20;
    printf("%d  %d \n", *&a, *&b); // 整活

    scanf("%d%d", &a, &b);
    printf("%d, %d\n", a, b);
    int month, day, year;
    printf("Please enter the date (dd/mm/yyyy) : ");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("You entered the date %.4d%.2d%.2d\n", year,month,day);

    printf("%d", -9 % 7);

}

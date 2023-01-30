# include <stdio.h>

int main (){

    int grade;
    scanf("%d", &grade);

    switch(grade){  // 也就是说只能匹配一个值，而不能范围

        case 10:
            printf("Ecxellent");
            break;

        case 20:
            printf("Good");
            break;

        case 30:
            printf("Average");
            break;

        case 50:
            printf("WTF?");
            break;

        case 100:
            printf("滚");

            case 300: case 400: case 500: case 600:
                grade ++;
            printf("%d", grade);
            break;
        default:  // 其他
            printf("啥呀");
            break;

    }

    return 0;

}
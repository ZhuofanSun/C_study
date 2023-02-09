#include <stdio.h>

double average(double a, double b){
    return (a+b) / 2;
}

void addone(int *a){
    (*a) += 1;
}

int main() {

    double a = 3, b = 4;
    printf("%f\n", average(a,b));

    int x = 5;
    addone(&x);
    printf("%d\n", x);

    int arr [20];
    arr[0] = 2;
    arr[1] = 3;
    x = sizeof (arr) / sizeof (arr[0]);  //数组大小
    printf("%d\n", x);



    return 0;
}

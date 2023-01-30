#include <stdio.h>

int main(){

    FILE *fp1= fopen("test.txt", "r");

    int a, b, c;
    fprintf(fp1, "%d/%d/%d", 12, 13, 14);
    fscanf(fp1, "%d/%d/%d", &a, &b, &c);
    printf("%d  %d  %d  ", a, b, c);


}
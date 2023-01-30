#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Hello, World!\n");
    FILE *fp1 = fopen(argv[1], "wr");

    if(argc != 2){

        printf("usage: ./main filename\n");
        exit(EXIT_FAILURE);

    }



    if (fp1 == NULL) {
        printf("fail to open");
        exit(EXIT_FAILURE);
    }
    printf("%s can be opened\n", argv[1]);
    printf("print something\n");

    fprintf(fp1, "1 2 3");
    int a, b, c;
    fscanf(fp1,"%d/%d/%d", &a, &b, &c);
    printf("%d   %d %d", a, b, c);
    fclose(fp1);
    return 0;
// argv[0] 指向可执行程序
// argv[1] 指向第一个变量.........
}

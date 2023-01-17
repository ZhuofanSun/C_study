#include <stdio.h>
/**
int main(){
    FILE * file = fopen("Hello.txt", "r");
    if(file == NULL){
        printf("文件打开失败了捏\n");
    }
    else{
        printf("成功了捏\n");
        int c;
        while((c = getc(file)) != EOF){
            putchar(c);//putchar()每次会自动向后推进一个字符
        }

    }
    fclose(file);//关闭文件
}
 **/

/**
int main(){
    FILE * file = fopen("test_write.txt", "w");//w会覆盖，a会从结尾开始添加
    for (int i = 0; i < 10; ++i) {
        putc('A' + i, file);
    }


}
 **/


int main(){
    FILE * file = fopen("test_write.txt", "a+");
    char buf[3];
    setvbuf(file, buf,_IOFBF,3);//设置缓冲区是3
/**    _IONBF：表示不使用缓冲区
    _IOFBF：表示只有缓冲区填满了才会更新到文件
    _IOLBF：表示遇到换行就更新到文件
**/
    while (1){
        char c = getchar();
        if (c == 'q')break;
        putc(c, file);
        //fflush(file);//刷新缓冲区
    }
    fprintf(file, "shit");
    fclose(file);



}
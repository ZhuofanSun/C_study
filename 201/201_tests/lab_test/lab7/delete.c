# include <stdio.h>
# include <string.h>
# include <ctype.h>

#define MAX_SIZE 100

int check_palindrome(char *string);  //接收字符串指针

int main(){
    // He lived as a devil, eh?
    // Madam, I am Adam.
    char string[MAX_SIZE];
    printf("Enter a message: ");
    fgets(string, MAX_SIZE, stdin);

    if (check_palindrome(string) == 1){
        printf("Palindrome\n");
    }
    else if (check_palindrome(string) == 0){
        printf("Not Palindrome\n");
    }
    return 0;
}

int check_palindrome(char *string){  //接收字符串指针
    char obverse[MAX_SIZE], reverse[MAX_SIZE];  // 初始化，要不不能分配内存
    // begin
    // toupper 接收int，返回int 都是ascii，只支持单个字符（char）
        //string = toupper(string); // toupper to convert to uppercase letters
        for (int i = 0; i < strlen(string); ++i) {
            *(string+i) = (char) toupper(*(string+i));  // (char)可以不加
        }
    //end

    //begin
        int i = 0;
        int j = 0;
        while (*(string+i) != '\n'){
            if (isalpha(*(string+i))){ // isalpha to check the passed character is a letter
                // *obverse++ = string;  // 这是什么, 不能把字符串首地址重新赋值
                *(obverse + (j++)) = *(string + i);
            }
            i++;
        }
        *(obverse + j) = '\0';  // 补上字符串结束符
    //end

    //start
        int reverse_pointer = 0;
        for (int obverse_pointer = (int)strlen(obverse) - 1; obverse_pointer >= 0; --obverse_pointer) {
            *(reverse+(reverse_pointer++)) = *(obverse+obverse_pointer);  // 我猜你是这个意思
        }
        *(reverse + reverse_pointer) = '\0';  // 补上字符串结束符
    //end

    if(strcmp(obverse, reverse) == 0){  // 比较字符串
        return 1;
    }
    else if(strcmp(obverse, reverse) != 0){
        return 0;
    }
}
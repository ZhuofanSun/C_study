#include "str_quicksort.h"
int read(char ** str_arr){
    _Bool flag = 1;
    int str_num = 0, str_len = 0;
    while(flag){
        str_arr[str_num] = malloc(sizeof (char));
        str_len = 0;
        printf("Enter word: ");
        char letter;

        while ((letter = (char)fgetc(stdin)) != '\n'){

            // str_len start from 0, allocate for the next char
            str_arr[str_num] =(char*)realloc(str_arr[str_num], sizeof (char) * (str_len +2));
            str_arr[str_num][str_len++] = letter;

            printf("char :  %c\n", str_arr[str_num][str_len-1]);

        }
        str_arr[str_num][str_len] = '\0';

        if (str_arr[str_num][0] == '\0'){
            flag = 0;
        }

        str_num ++;
    }

    return --str_num;

}


int main(){
    char *str_arr[20];
    * str_arr = malloc(sizeof (char));
    int str_num = read(str_arr);
    quicksort(str_arr, str_arr, str_arr+str_num -1 );
    return 0;
}
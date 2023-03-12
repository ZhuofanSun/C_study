#include "str_quicksort.h"
int read(char ** str_arr){
    _Bool flag = 1;
    int str_num = 0, str_len = 0;  // number of strings and string length
    while(flag){
        str_arr[str_num] = malloc(sizeof (char));
        str_len = 0;
        printf("Enter word: ");
        char letter;

        while ((letter = (char)fgetc(stdin)) != '\n'){

            // str_len start from 0, allocate for the next char
            str_arr[str_num] =(char*)realloc(str_arr[str_num], sizeof (char) * (str_len +2));
            str_arr[str_num][str_len++] = letter;

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
    if (str_arr[0][0] == '\0'){
        return 0;
    }
    quicksort(str_arr, str_arr, str_arr+str_num -1 );
    printf("In sorted order: ");
    for (int i = 0; i < str_num; ++i) {
        printf("%s ", str_arr[i]);
    }
    printf(".\n");
    return 0;
}
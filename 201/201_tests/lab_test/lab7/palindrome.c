#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
/*
int check_palindrome(char * msg){
    int i = 0, j = (int)(strlen(msg) - 1);

    while (i < j){

        if (*(msg+i) == *(msg+j)){
            i ++;
            j --;
        }
        else{

            if (*(msg+i) >= 'a' && *(msg+i) <= 'z' && *(msg+j) >= 'a' && *(msg+j) <= 'z'){
                return 0;
            }

            if (*(msg+i) >= 'A' && *(msg+i) <= 'Z'){
                *(msg+i) = *(msg+i) - 'A' + 'a';
            }
            else if (*(msg+i) < 'a' || *(msg+i) > 'z'){
                i ++;
            }

            if (*(msg+j) >= 'A' && *(msg+j) <= 'Z'){
                *(msg+j) = *(msg+j) - 'A' + 'a';
            }
            else if (*(msg+j) < 'a' || *(msg+j) > 'z'){
                j --;
            }
        }

    }
    return 1;
}
*/

int check_palindrome(char * msg){

    char reverse_msg[strlen(msg)];  // all lower-case alphabet msg char in reverse order
    int i = 0, j = 0;
    for (int k = (int)strlen(msg) - 1; k >= 0 ; --k) {  // start from the last element

        if (*(msg+k) >= 'a' && *(msg+k) <= 'z'){  // [a,z]
            reverse_msg[j++] = *(msg+k);
        }
        else if (*(msg+k) >= 'A' && *(msg+k) <= 'Z'){  // [A,Z] -- convert into lower case
            reverse_msg[j++] = *(msg+k) - 'A' + 'a';
        }

    }

    j = 0;
    for (; i < strlen(msg); ++i) {  // compare and return

        if (*(msg+j) >= 'a' && *(msg+j) <= 'z'){
            if(*(msg+j) != *(reverse_msg+j)){
                return 0;
            }
            j ++;
        }
        else if (*(msg+j) >= 'A' && *(msg+j) <= 'Z'){  // convert into lower case
            if(*(msg+j) - 'A' + 'a' != *(reverse_msg+j)){
                return 0;
            }
            j ++;
        }

    }
    return 1;  // loop end -> all same

}



int main(){
    // He lived as a devil, eh?
    // Madam, I am Adam.
    char msg[MAX_SIZE+2];  // 100 msg char, one \n, one \0
    printf("Enter a message: ");
    fgets(msg, MAX_SIZE+2, stdin); // get input string, include \n
    if (check_palindrome(msg)){  // palindrome return true otherwise false
        printf("Palindrome\n");
    }
    else{
        printf("Not a palindrome\n");
    }

}
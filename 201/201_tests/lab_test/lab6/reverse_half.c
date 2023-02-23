#include <stdio.h>

#define MAX_SIZE 100

int main() {
    char message[MAX_SIZE + 1];  // to store input string, with size 101

    printf("Enter a message: ");
    fgets(message, MAX_SIZE+1, stdin);

    int len = 0;  // length of input string
    while(*(message + len) != '\n')  // (message + len) always points at the next char
        len ++;
    int half_len = len / 2;
    int curr_index = half_len - 1;  // (message + half_len) is also pointing at the next chr
    for (; curr_index >= 0; curr_index--) {
        printf("%c", *(message+curr_index));
    }

    return 0;
}

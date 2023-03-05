/*
 * This program demos String conccepts and various functions from the String library
 */
#include <stdio.h>
#include <string.h>

#define SENT_LEN 40

int main(void){

    /* Test assigning string to smaller array */
    char test[5] = "Hello there";
    printf("%s\n", test);

    /* Difference between scanf & fgets when reading input */
    char sentence[SENT_LEN + 1]; //remember to acccount for the null character
    printf("Enter sentence for fgets:");
    fgets(sentence, SENT_LEN + 1, stdin);
    printf("fgsets read:%sEND\n", sentence);

    char otherSent[SENT_LEN + 1];
    printf("Enter sentence for scanf:");
    scanf("%s", otherSent);
    printf("Scanf read:%sEND\n", otherSent);
    
    /* string library functions */
    char *tmp, str[SENT_LEN + 1];
    
    /* Copying and length functions */
    printf("/* Copying sentence into str */\n");
    strncpy(str, sentence, sizeof(str));//note how sizeof can be used for the array here. Remember that a char occupies 1 byte
    printf("str is now: %s\n", str);
    
    printf("/* Copying a larger string into str */\n");
    strncpy(str, "This is a large string that is more than 40 characters", SENT_LEN + 1);
    printf("str is now \"%s\" with length %lu\n", str, strlen(str));//problem bec. there is no null char
    printf("The last character of str is: %c\n", str[SENT_LEN]);
    str[sizeof(str) - 1] = '\0';
    printf("After ensuring null char. string is \"%s\" with length %lu\n", str, strlen(str));
    
    /* Concatenation functions */
    char large_sentence[SENT_LEN + SENT_LEN + 1]; //ensure enough spacce
    strncpy(large_sentence, sentence, SENT_LEN + 1);
    strncat(large_sentence, otherSent, strlen(large_sentence) - strlen(otherSent)); //no need to subtract 1 since strlen already does not include the null character. strncat basically needs to be told how many characters to copy, not including the null character but it needs to have space for the null character after that
    printf("Concatenating sentence and otherSent results in \"%s\"\n", large_sentence);
    
    if(strcmp(sentence, otherSent) == 0){
        printf("Sentence and other sentence are the same\n");
    } else if(strcmp(sentence, otherSent) > 0){
        printf("Sentence comes alphabetically before other sentence\n");
    } else{
         printf("Sentence comes alphabetically after other sentence\n");
    }

    return 0;
}

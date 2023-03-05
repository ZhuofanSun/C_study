#include <stdio.h>

#define SENT_LEN 40

int main(void){

    /* Difference between scanf & fgets when reading input */
    char sentence[SENT_LEN + 1]; //remember to acccount for the null character
    printf("Enter sentence for fgets:");
    fgets(sentence, SENT_LEN + 1, stdin);
    printf("fgsets read:%sEND\n", sentence);

    char otherSent[SENT_LEN + 1];
    printf("Enter sentence for scanf:");
    scanf("%s", otherSent);
    printf("Scanf read:%sEND\n", otherSent);

	return 0;
}

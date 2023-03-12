#include <stdio.h>
#include <string.h>

enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};
typedef enum {clubs = 1, diamonds = 2, hearts = 3, spades = 4} Suit;

struct Card{
    enum suit s;
    int value;
};

int main(){

    enum suit s1;
    Suit s2;
    char input[20];

    printf("Enter suit:");
    fgets(input, 20, stdin);
    input[strlen(input) - 1] = '\0';

    if(strcmp(input, "clubs") == 0){
        s1 = CLUBS;
        s2 = clubs;
    }else if(strcmp(input, "diamonds") == 0){
        s1 = DIAMONDS;
        s2 = diamonds;
    }else if(strcmp(input, "hearts") == 0){
        s1 = HEARTS;
        s2 = hearts;
    }else if(strcmp(input, "spades") == 0){
        s1 = SPADES;
        s2 = spades;
    }

    printf("Value of your suit from \"suit\" is: %d\n", s1);
    printf("Value of your suit from \"Suit\" is: %d\n", s2);

    struct Card card = {s1, 20};
    printf("Your card value is:%d and suit is %d\n", card.value, card.s);
    return 0;
}

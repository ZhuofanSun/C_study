#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(){

    const char suits[] = {'C', 'S', 'D', 'H'};
    const char ranks[] = {'2','3','4','5','6','7','8','9','t','j','q','k','a'};
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};

    int numOfCards;

    printf("Enter a number of cards in hand: ");
    scanf("%d", &numOfCards);

    srand( (unsigned) time(NULL));

    while (numOfCards > 0){
        int suit, rank;
        suit = rand() % NUM_SUITS;
        rank = rand() % NUM_RANKS;
        if (in_hand[suit][rank] != true){
            in_hand[suit][rank] = true;
            printf("%c%c ", ranks[rank], suits[suit]) ;
            numOfCards--;
        }
    }

    printf("\n");

    return 0;
}


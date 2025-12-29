#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct poker {
    const char* face;
    const char* suit;
};
void shuffle_dealPro(struct poker[]);
int main()
{
    const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    const char* face[13] =
    { "Ace", "Deuce", "Three", "Four",
    "Five", "Six", "Seven", "Eight",
    "Nine", "Ten", "Jack", "Queen", "King" };
    struct poker theDeck[52];
    for (int i = 0; i < 52; theDeck[i].face = face[i % 13], theDeck[i].suit = suit[i % 4], i++);
    srand(time(0));
    shuffle_dealPro(theDeck);
    return 0;
}

void shuffle_dealPro(struct poker deck[]) {
    for (int i = 51, t; i > 0; i--) {
        struct poker temp = deck[t = rand() % i];
        deck[t] = deck[i];
        deck[i] = temp;
    }
    for (int i = 0; i < 52; i++)
        printf("%5s of %-8s%c", deck[i].face, deck[i].suit,
            i % 2 ? '\n' : '\t');
}
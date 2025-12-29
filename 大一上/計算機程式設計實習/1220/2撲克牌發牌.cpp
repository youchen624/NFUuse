#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle_deal(int[], const char* [], const char* []);
int main()
{
    const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    const char* face[13] =
    { "Ace", "Deuce", "Three", "Four",
    "Five", "Six", "Seven", "Eight",
    "Nine", "Ten", "Jack", "Queen", "King" };
    int deck[52];
    for (int i = 0; i < 52; deck[i] = i++);
    srand(time(0));
    shuffle_deal(deck, face, suit);
    return 0;
}

void shuffle_deal(int deck[], const char* face[], const char* suit[]) {
    for (int i = 51, t; i > 0; i--) {
        int temp = deck[t = rand() % i];
        deck[t] = deck[i];
        deck[i] = temp;
    }
    // for (int i = 0; i < 52; i++) printf("%d\n", deck[i]);
    for (int i = 0; i < 52; i++)
        printf("%5s of %-8s%c", face[deck[i] %13] , suit[deck[i] %4],
            i % 2 ? '\n' : '\t');

}
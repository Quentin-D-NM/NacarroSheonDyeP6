//Quentin

#include "Deck.h"
#include <chrono>

Deck::Deck()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    engine.seed(seed);

    for (int i = 0; i < 52; i++)
    {
        cards[i] = i;
    }
    Shuffle();
}

void Deck::Shuffle()
{
    //Goes throught the entire array once and switches the I with the random var
    for (int i = 0; i < 52; i++)
    {
        int switchWith = RandomCard();
        int temp = cards[switchWith];
        cards[switchWith] = cards[i];
        cards[i] = temp;
    }

}

int Deck::RandomCard()
{
    //gives random position in array
    uniform_int_distribution<int> dist(0, 51);
    return dist(engine);
}

void Deck::Deal(Card& c)
{
    //assigns the card passes the the next card in the deck
    Card card(cards[topCard]);
    c = card; 
    topCard++;
    if (topCard == 35)
    {
        Shuffle();
        topCard = 0;
    }
}

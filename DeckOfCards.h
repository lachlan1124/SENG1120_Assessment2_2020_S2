#ifndef GAURD_DECKOFCARDS
#define GAURD_DECKOFCARDS

#include "Card.h"
#include "Queue.h"

class DeckOfCards
{

    public:

        DeckOfCards();

        void shuffle();

        void test();


    private:
        Queue<Card> cards;

        void addCard(std::string face, int value, bool faceUp = false);

};


#endif
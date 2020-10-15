#ifndef GAURD_DECKOFCARDS
#define GAURD_DECKOFCARDS

#include "Card.h"
#include "Queue.h"

class DeckOfCards
{

    public:

        DeckOfCards();

        void addCard(std::string face, int value, bool faceUp = false);

        void test();


    private:
        Queue<Card> cards;

};


#endif
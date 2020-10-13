#ifndef GAURD_DECKOFCARDS
#define GAURD_DECKOFCARDS

#include "Card.h"
#include "Queue.h"
class DeckOfCards
{

    public:

        DeckOfCards();


    private:
        Queue<Card> cards;

};


#endif
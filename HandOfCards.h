#ifndef GUARD_HANDOFCARDS
#define GUARD_HANDOFCARDS

#include "Queue.h"
#include "Card.h"

class HandOfCards
{

    public:

        HandOfCards();

        int count();

        int countAll();

        std::string value();

        void faceUp();

        void add(Card card, bool face);

    private:
        Queue<Card> cards;

};

    std::ostream& operator <<(std::ostream& os, HandOfCards& p);


#endif
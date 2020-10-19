//HandOfCards - Class Template Declaration 
/******************************/
//Author: Lachlan Marler | C3351542
//Course: SENG1120
//Class Description: Stores a queue of cards used by the main program to implement the dealers and players hand

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
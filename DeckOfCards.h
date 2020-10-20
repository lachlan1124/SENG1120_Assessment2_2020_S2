//DeckOfCards - Class Template Declaration 
/******************************/
//Author: Lachlan Marler | C3351542
//Course: SENG1120
//Class Description: Stores a queue of cards used by the main program to the deck used in the game.

#ifndef GAURD_DECKOFCARDS
#define GAURD_DECKOFCARDS

#include "Card.h"
#include "Queue.h"

class DeckOfCards
{

    public:

        DeckOfCards();

        DeckOfCards(const bool empty);

        ~DeckOfCards();

        void shuffle();

        Card draw();

        std::string out();

        int getSize();

        void faceUp();

    private:
        Queue<Card> cards;

        void addCard(const std::string face,const int value,const bool faceUp = false);

        void addCard(const Card);

        void merge(DeckOfCards* Decks[]);
};


    std::ostream& operator <<(std::ostream& os, DeckOfCards& p);



#endif
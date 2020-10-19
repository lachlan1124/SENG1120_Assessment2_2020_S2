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

        DeckOfCards(bool empty);

        void shuffle();

        Card draw();

        std::string out();

        int getSize();

        void faceUp();

    private:
        Queue<Card> cards;

        void addCard(std::string face, int value, bool faceUp = false);

        void addCard(Card);

        void merge( DeckOfCards* Decks[]);
};


    std::ostream& operator <<(std::ostream& os, DeckOfCards& p);



#endif
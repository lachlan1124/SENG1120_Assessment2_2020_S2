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
#include "DeckOfCards.h"
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>   


 DeckOfCards::DeckOfCards()
{
    for(int i = 2; i <= 10; i++) // create cards between 2-10 for all suits
        {
            std::stringstream ss;

            ss << i << "-H";
            addCard(ss.str(), i);

            ss.str("");

            ss << i << "-D";
            addCard(ss.str(), i);

            ss.str("");

            ss << i << "-C";
            addCard(ss.str(), i);

            ss.str("");

            ss << i << "-S";
            addCard(ss.str(), i);

            ss.str("");
            
        }
        
        // Add jacks
        addCard("J-H", 10);
        addCard("J-D", 10);
        addCard("J-C", 10);
        addCard("J-S", 10);

        // Add kings
        addCard("K-H", 10);
        addCard("K-D", 10);
        addCard("K-C", 10);
        addCard("K-S", 10);

        // Add queens
        addCard("Q-H", 10);
        addCard("Q-D", 10);
        addCard("Q-C", 10);
        addCard("Q-S", 10);

        // Add aces
        addCard("A-H", 11);
        addCard("A-D", 11);
        addCard("A-C", 11);
        addCard("A-S", 11);
}

//creates a empty deck of cards, used to shuffle the main deck
DeckOfCards::DeckOfCards(bool empty)
{

}

// adds card to the deck by creating a new card
void DeckOfCards::addCard(std::string face, int value, bool faceUp)
{
    cards.enqueue(Card(face, value, faceUp));
}

// uses an existing card to add to the deck
void DeckOfCards::addCard(Card card)
{
    cards.enqueue(card);
}

Card DeckOfCards::removeCard()
{
    return cards.dequeue();
}

//shuffles the main deck of cards
void DeckOfCards::shuffle()
{

    srand (time(NULL)); // seeds the random generator with the time
    DeckOfCards* shuffleDecks[4];


    for(int i = 0; i < 4; i++) // for each new deck
    {

        shuffleDecks[i] = new DeckOfCards(true); // inisalize an empty deck

        for(int j = 0; j > 12; j++) // fill empty deck with 12 cards from the main deck
        {
            shuffleDecks[i]->addCard(removeCard());
        }
    }

    for(int k = 0; k < 1000; k++) // remove card from top of random deck and add to the bottom of a new deck for 1000 times
    {
        shuffleDecks[(rand() % 4)]->addCard(shuffleDecks[rand() % 4]->removeCard());
    }

    merge(shuffleDecks); // merge the 4 shuffled decks togther

}

void DeckOfCards::merge(DeckOfCards* shuffledDecks[])
{

}

void DeckOfCards::test()
{


}

int DeckOfCards::size()
{
    return cards.getSize();
}

// removes card, gets face, adds card back to deck
std::string DeckOfCards::out()
{
    Card tmp;
    std::string face;

    tmp = removeCard();
    face = tmp.getFace();
    addCard(tmp);
    return face;
}

std::ostream& operator <<(std::ostream& os, DeckOfCards& p)
{
    //for each card
    for(int i = 0; i < p.size(); i++)
    {
        os << p.out() << " ";
    }
    
    return os;
}
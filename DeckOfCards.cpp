//DeckOfCards - Class Template Implementation 
/******************************/
//Author: Lachlan Marler | C3351542
//Course: SENG1120
//Class Description: Stores a queue of cards used by the main program to the deck used in the game.

#include "DeckOfCards.h"
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>   
#include <sys/time.h>
#include <stdio.h>


// Constructor for a 52 card deck of cards
 DeckOfCards::DeckOfCards()
{
    timeval currentTime; // store time data

    gettimeofday(&currentTime, NULL); // gets time of day to millisecond 

    srand (currentTime.tv_usec * time(NULL) * currentTime.tv_sec); // seeds the random generator with the time

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
DeckOfCards::DeckOfCards(const bool empty)
{
    timeval currentTime;

    gettimeofday(&currentTime, NULL); // gets time of day to millisecond 
    
    srand (currentTime.tv_usec * time(NULL) * currentTime.tv_sec); // seeds the random generator with the time
}

DeckOfCards::~DeckOfCards() {}

// adds card to the deck by creating a new card
void DeckOfCards::addCard(const std::string face,const int value,const bool faceUp)
{
    cards.enqueue(Card(face, value, faceUp));
}

// uses an existing card to add to the deck
void DeckOfCards::addCard(const Card card)
{
    cards.enqueue(card);
}

//removes a card from the queue
Card DeckOfCards::draw()
{
    return cards.dequeue();
}

//shuffles the main deck of cards
void DeckOfCards::shuffle()
{

    DeckOfCards* shuffleDecks[4]; // store the location of the 4 temp decks


    for(int i = 0; i < 4; i++) // for each new deck
    {

        shuffleDecks[i] = new DeckOfCards(true); // inisalize an empty deck

        for(int j = 0; j < 13; j++) // fill empty deck with 12 cards from the main deck
        {
            shuffleDecks[i]->addCard(draw());
        }
    }

    for(int k = 0; k < 1000; k++) // remove card from top of random deck and add to the bottom of a new deck for ~1000 times 
    {
        int randA = rand() % 4;
        int randB = rand() % 4;

        if(shuffleDecks[randA]->getSize()  > 2) // don't remove all cards from deck
        {
            Card tmp = shuffleDecks[randA]->draw(); // remove card from deck A

            shuffleDecks[randB]->addCard(tmp); // add card to deck B
        }

    }

    merge(shuffleDecks); // merge the 4 shuffled decks togther

}

//merges 4 decks together
void DeckOfCards::merge(DeckOfCards* shuffledDecks[])
{
    for(int i = 0; i < 4; i++) // for each of the decks given
    {
        int deckSize = shuffledDecks[i]->getSize(); 
        for(int j = 0; j < deckSize; j++) // for each card in the deck
        {
            addCard(shuffledDecks[i]->draw()); // add back to the main deck
        }      

        delete shuffledDecks[i]; // delete the deck

    }
    
}


// returns the amount of cards in the deck
int DeckOfCards::getSize()
{
    return cards.getSize();
}

// removes card, gets face, adds card back to deck
std::string DeckOfCards::out()
{
    Card tmp; // stores the card
    std::string face; // store the face of that card

    tmp = draw(); // get top card
    face = tmp.getFace(); // gets face
    addCard(tmp); // add card back to the deck

    return face; // return the face
}

// operator overload for DeckOfCards
std::ostream& operator <<(std::ostream& os, DeckOfCards& p)
{
    //for each card
    for(int i = 0; i < p.getSize(); i++)
    {
        os << p.out() << " ";
    }
    
    return os;
}
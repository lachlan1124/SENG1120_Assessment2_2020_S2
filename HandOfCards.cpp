//HandOfCards - Class Template Implementation 
/******************************/
//Author: Lachlan Marler | C3351542
//Course: SENG1120
//Class Description: Stores a queue of cards used by the main program to implement the dealers and players hand

#include "HandOfCards.h"
#include <iostream>
#include <sstream>

HandOfCards::HandOfCards() {}

HandOfCards::~HandOfCards() {}


//adds a single card to the hand
void HandOfCards::add(Card card,bool face)
{
    card.setFaceUp(face);
    cards.enqueue(card);
} 

//counts the value of all the cards facing up
int HandOfCards::count() 
{
    int val = 0;
    for(int i = 0; i < cards.getSize(); i++) //for each card in the hand
    {
        Card currentCard = cards.dequeue(); // remove the card on top

        if(currentCard.getFaceUp()) // if the card is face up
        {
            val += currentCard.getValue(); // add the value to the count
        }

        cards.enqueue(currentCard); // add the cards back to the queue

    }

    return val; // return the total value 
}


//counts the value of all the cards including card facing down
int HandOfCards::countAll()
{
    int val = 0;
    for(int i = 0; i < cards.getSize(); i++ ) // for all cards in the hand
    {
        Card currentCard = cards.dequeue(); // remove the top card

        val += currentCard.getValue(); // add the value to the count
        cards.enqueue(currentCard); // add the card back to the queue
    }

    return val; // return the value


}
// returns a string with the cards in the player/dealers hand and the total value of the cards
std::string HandOfCards::value() 
{
    std::string val;

    for(int i = 0; i < cards.getSize(); i++) // for each card
    {
        Card currentCard = cards.dequeue(); // remove top card from hand

        if(currentCard.getFaceUp()) // if the card is faceUp
            val.append(currentCard.getFace() + " "); // print that cards face
        else
            val.append("?-? ");  // print ?-? if the card is not faceUp
    
        
        cards.enqueue(currentCard); // add the card back to the hand
    }

    std::stringstream ss; // create a string stream

    ss << count(); // get the value of all the cards in the hand that are faceUp and add it to the stream
    
    val.append("(" + ss.str() + " points)"); // format the count for the player

    return val; // return the string
}

//sets all the cards to faceUp
void HandOfCards::faceUp()
{
    for(int i = 0; i < cards.getSize(); i++) // for each card in the hand
    {
        Card currentCard = cards.dequeue(); // remove the top card

        currentCard.setFaceUp(true); // set the card to face up

        cards.enqueue(currentCard); // add the card back to the hand
    }
}

//overload opeation for the hand of cards
std::ostream& operator <<(std::ostream& os, HandOfCards& p)
{

    os << p.value(); // get the cards and the value

    return os; // return the stream
}
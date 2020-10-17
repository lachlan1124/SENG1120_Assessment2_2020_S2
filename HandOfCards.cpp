#include "HandOfCards.h"
#include <iostream>
#include <sstream>

HandOfCards::HandOfCards()
{

}

//adds a single card to the hand
void HandOfCards::add(Card card, bool face)
{

    card.setFaceUp(face);

    cards.enqueue(card);


} 

//counts the value of all the cards facing up
int HandOfCards::count()
{
    int val = 0;
    for(int i = 0; i < cards.getSize(); i++)
    {
        Card currentCard = cards.dequeue();

        if(currentCard.getFaceUp())
        {
            val += currentCard.getValue();
        }

        cards.enqueue(currentCard);

    }

    return val;
}


//counts the value of all the cards including card facing down
int HandOfCards::countAll()
{
    int val = 0;
    for(int i = 0; i < cards.getSize(); i++ )
    {
        Card currentCard = cards.dequeue();

        val += currentCard.getValue();
        cards.enqueue(currentCard);
    }

    return val;


}

std::string HandOfCards::value()
{
    std::string val;

    for(int i = 0; i < cards.getSize(); i++)
    {
        Card currentCard = cards.dequeue();

        if(currentCard.getFaceUp())
            val.append(currentCard.getFace() + " ");
        else
            val.append("?-? ");  
    
        
        cards.enqueue(currentCard);
    }

    std::stringstream ss;

    ss << count();
    
    val.append("(" + ss.str() + " points)");

    return val;
}

void HandOfCards::faceUp()
{
    for(int i = 0; i < cards.getSize(); i++)
    {
        Card currentCard = cards.dequeue();

        currentCard.setFaceUp(true);

        cards.enqueue(currentCard);
    }
}


std::ostream& operator <<(std::ostream& os, HandOfCards& p)
{

    os << p.value();

    return os;
}
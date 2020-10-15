#include "DeckOfCards.h"

 DeckOfCards::DeckOfCards()
{
    for(int i = 2; i < 10; i++)
        {
            addCard(i+"H", i);
            addCard(i+"D", i);
            addCard(i+"C", i);
            addCard(i+"S", i);
            
        }
}

void DeckOfCards::addCard(std::string face, int value, bool faceUp)
{
    cards.enqueue(Card(face, value, faceUp));
}

void DeckOfCards::test()
{
    std::cout << cards.dequeue().getFace() << std::endl;
    std::cout << cards.dequeue().getFace() << std::endl;
}
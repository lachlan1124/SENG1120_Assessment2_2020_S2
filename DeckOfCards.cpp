#include "DeckOfCards.h"
#include <sstream>
#include <string>

 DeckOfCards::DeckOfCards()
{
    for(int i = 2; i <= 10; i++)
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


        // Jacks Queen King and ACE needs to be added here.

        addCard("J-H", 10);
        addCard("J-D", 10);
        addCard("J-C", 10);
        addCard("J-S", 10);

        addCard("K-H", 10);
        addCard("K-D", 10);
        addCard("K-C", 10);
        addCard("K-S", 10);

        addCard("Q-H", 10);
        addCard("Q-D", 10);
        addCard("Q-C", 10);
        addCard("Q-S", 10);

        addCard("A-H", 11);
        addCard("A-D", 11);
        addCard("A-C", 11);
        addCard("A-S", 11);
}

void DeckOfCards::addCard(std::string face, int value, bool faceUp)
{
    cards.enqueue(Card(face, value, faceUp));
}

void DeckOfCards::test()
{


}
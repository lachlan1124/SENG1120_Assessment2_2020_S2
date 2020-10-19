//DeckOfCards - Class Template Implementation 
/******************************/
//Author: Lachlan Marler | C3351542
//Course: SENG1120
//Class Description: Store the face of a card (10-H) the value of that card and if it is faceUp or faceDown.


#include "Card.h"

    Card::Card(std::string f, int i, bool fa)
    {
        face = f;
        value = i;
        faceUp = fa;
    }

    Card::Card()
    {
        
    }

     void Card::setFace(std::string f)
    {
        face = f;
    }

    void Card::setValue(int i)
    {
        value = i;
    }

    void Card::setFaceUp(bool f)
    {
        faceUp = f;
    }

    std::string Card::getFace()
    {
        return face;
    }

    int Card::getValue()
    {
        return value;
    }

    bool Card::getFaceUp()
    {
        return faceUp;
    }
//DeckOfCards - Class Template Implementation 
/******************************/
//Author: Lachlan Marler | C3351542
//Course: SENG1120
//Class Description: Store the face of a card (10-H) the value of that card and if it is faceUp or faceDown.


#include "Card.h"

    Card::Card(const std::string f,const int i,const bool fa)
    {
        face = f;
        value = i;
        faceUp = fa;
    }

    Card::Card() {}

    Card::~Card() {}


     void Card::setFace(const std::string f)
    {
        face = f;
    }

    void Card::setValue(const int i)
    {
        value = i;
    }

    void Card::setFaceUp(const bool f)
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
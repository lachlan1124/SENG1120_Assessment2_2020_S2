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
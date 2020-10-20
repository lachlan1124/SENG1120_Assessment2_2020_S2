//DeckOfCards - Class Template Declaration 
/******************************/
//Author: Lachlan Marler | C3351542
//Course: SENG1120
//Class Description: Store the face of a card (10-H) the value of that card and if it is faceUp or faceDown.


#ifndef GAURD_CARD
#define GAURD_CARD

#include <iostream>

class Card
{

    public:

        Card();
        Card(const std::string f, const int i,const bool fa);
        ~Card();

        void setFace(const std::string f);
        void setValue(const int i);
        void setFaceUp(const bool f);

        std::string getFace();

        int getValue();

        bool getFaceUp();


    private:

        std::string face;

        int value;

        bool faceUp;


};


#endif
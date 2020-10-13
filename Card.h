#ifndef GAURD_CARD
#define GAURD_CARD

#include <iostream>

class Card
{

    public:

        Card();
        Card(std::string f, int i, bool fa);

        void setFace(std::string f);
        void setValue(int i);
        void setFaceUp(bool f);

        std::string getFace();

        int getValue();

        bool getFaceUp();


    private:

        std::string face;

        int value;

        bool faceUp;


};


#endif
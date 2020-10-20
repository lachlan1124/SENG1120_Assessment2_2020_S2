//Queue - Class Template Declaration 
/******************************/
//Author: Lachlan Marler | C3351542
//Course: SENG1120
//Class Description: Restricts the access on a linkedlist, data enters at the tail and exits at the head.

#ifndef GAURD_QUEUE
#define GAURD_QUEUE

#include "LinkedList.h"

template <typename valueType>
class Queue
{

    public:

        Queue();

        ~Queue();

        void enqueue(const valueType& toAdd);

        valueType dequeue();


        int getSize() const;


    private:

        LinkedList<valueType> data;
        int size;


};

#include "Queue.hpp"

#endif
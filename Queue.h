#ifndef GAURD_QUEUE
#define GAURD_QUEUE

#include "LinkedList.h"

template <typename valueType>
class Queue
{

    public:

        Queue();

        void enqueue(valueType toAdd);

        valueType dequeue();


        int getSize();


    private:

        LinkedList<valueType> data;
        int size;


};

#include "Queue.hpp"

#endif
#ifndef GAURD_QUEUE
#define GAURD_QUEUE

#include "LinkedList.h"

template <typename valueType>

class Queue
{

    public:
        void enqueue(valueType toAdd);
        {
           data.addToTail();
        }

        valueType dequeue()
        {
            valueType tmp = data.getHeadData();
            data.deleteHead();
            return tmp;
        }

    private:

        LinkedList<valueType> data;
        int size;


};

//#include "Queue.hpp"

#endif
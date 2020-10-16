#ifndef GAURD_QUEUE
#define GAURD_QUEUE

#include "LinkedList.h"

template <typename valueType>

class Queue
{

    public:

        Queue()
        {
            size = 0;
        }

        void enqueue(valueType toAdd)
        {
           data.addToTail(toAdd);
           size++;
        }

        valueType dequeue()
        {
            valueType tmp = data.getHeadData();
            data.deleteHead();
            size--;
            return tmp;
        }

        int getSize()
        {
            return size;
        }

    private:

        LinkedList<valueType> data;
        int size;


};

//#include "Queue.hpp"

#endif
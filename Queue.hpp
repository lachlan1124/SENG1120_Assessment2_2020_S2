//Queue - Class Template Implementation 
/******************************/
//Author: Lachlan Marler | C3351542
//Course: SENG1120
//Class Description: Restricts the access on a linkedlist, data enters at the tail and exits at the head.


#include "Queue.h"
template<typename valueType> Queue<valueType>::Queue()
{
    size = 0;
}

template<typename valueType> Queue<valueType>::~Queue() {}


template<typename valueType> void Queue<valueType>::enqueue(const valueType& toAdd)
{
    data.addToTail(toAdd); // adds the data to the tail
    size++; // increments the size of the queue
}


// gets the data stored in the top of the queue, removes it from queue then returns the data.
template<typename valueType> valueType Queue<valueType>::dequeue()
{
    valueType tmp = data.getHeadData(); // get head data
    data.deleteHead(); // delete the head
    size--; // update the size
    return tmp; // return data
}

template<typename valueType> int Queue<valueType>::getSize() const
{
    return size;
}
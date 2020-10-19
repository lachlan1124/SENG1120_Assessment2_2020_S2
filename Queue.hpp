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

template<typename valueType> void Queue<valueType>::enqueue(const valueType& toAdd)
{
    data.addToTail(toAdd);
    size++;
}

template<typename valueType> valueType Queue<valueType>::dequeue()
{
    valueType tmp = data.getHeadData();
    data.deleteHead();
    size--;
    return tmp;
}

template<typename valueType> int Queue<valueType>::getSize()
{
    return size;
}

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
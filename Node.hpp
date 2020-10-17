#include "Node.h"

template<typename valueType> Node<valueType>::Node(const valueType& d, Node* n, Node* p)
{
    data = d;

    next = n;
    prev = p;
}

template<typename valueType> void Node<valueType>::setNext(Node* n)
{
    next = n;
}

template<typename valueType> void Node<valueType>::setPrev(Node* p)
{
    prev = p;
}


template<typename valueType> Node<valueType>* Node<valueType>::getNext() const
{
    return next;
}


template<typename valueType> Node<valueType>* Node<valueType>::getPrev() const
{
    return prev;
}


template<typename valueType> void Node<valueType>::setData(const valueType& d)
{
    data = d;
}


template<typename valueType> valueType Node<valueType>::getData() const
{
    return data;
}



template<typename valueType> Node<valueType>::~Node() {}

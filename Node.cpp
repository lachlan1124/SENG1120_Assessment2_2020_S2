//Node - Class Implementation 
/******************************/
//Author: Lachlan Marler | C3351542
//Course: SENG1120
//Class Description: This class stores a valueType in data and then two points to Nodes. 
// It is desgined to be useded as the Node for a doublely LinkedList

#include "Node.h"
template <typename valueType>

Node<valueType>::Node(const valueType& d, Node* n, Node* p)
{
    data = d;

    next = n;
    prev = p;
}

template <typename valueType>
Node<valueType>::~Node()
{
    
}

template <typename valueType>
void Node<valueType>::setNext(Node* n)
{
    next = n;
}

template <typename valueType>
void Node<valueType>::setPrev(Node* p)
{
    prev = p;
}

template <typename valueType>
Node* Node<valueType>::getNext() const
{
    return next;
}   

template <typename valueType>
Node* Node<valueType>::getPrev() const
{
    return prev;
}

template <typename valueType>
void Node<valueType>::setData(const valueType& d)
{
    data = d;
}

template <typename valueType>
Node::valueType Node<valueType>::getData() const
{
    return data;
}


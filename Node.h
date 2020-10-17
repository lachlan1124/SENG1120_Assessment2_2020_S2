//Node - Class Declaration 
/******************************/
//Author: Lachlan Marler | C3351542
//Course: SENG1120
//Class Description: 

#ifndef GUARD_NODE
#define GUARD_NODE

#include <iostream>

template <typename valueType>
class Node
{



    public:



        Node(const valueType& d, Node* n = NULL, Node* p = NULL);


        ~Node();

        // Precondition: that n is a valid Node
        // Postcondition: next is set to n
        void setNext(Node* n);

        // Precondition: that p is a valid Node
        // Postcondition: prev is set to p
        void setPrev(Node* p);


        // Precondition: none
        // Postcondition: returns next
        Node* getNext() const;


        // Precondition: none
        // Postcondition: returns prev
        Node* getPrev() const;



        // Precondition: that d is of valueType and is valid
        // Postcondition: data is set to d
        void setData(const valueType& d);


        // Precondition: none
        // Postcondition: returns data
        valueType getData() const;



    private:

    Node* next;
    Node* prev;

    valueType data;

    
};


#include "Node.hpp"

#endif
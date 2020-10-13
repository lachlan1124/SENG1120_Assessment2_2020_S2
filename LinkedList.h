//LinkedList - Class Declaration 
/******************************/
//Author: Lachlan Marler | C3351542
//Course: SENG1120
//Class Description: This class dynamicaly stores nodes. Nodes are added to the tail of the LinkedList.
// This is a double linkedlist meaning that each node stores the next and prev data.

#ifndef GAURD_LINKEDLIST
#define GAURD_LINKEDLIST

#include <iostream>
#include "Node.h"

template <typename valueType>

class LinkedList
{


    public:

        LinkedList()
        {
            head = NULL; // head default value
            tail = NULL; // tail default value
            current = NULL; // current default value
            
            size = 0; // size of list when first initialized
        }

        ~LinkedList() 
        {
            reset(); // sets current to head

            for(int i = 0; i < size; i++) // traverses list and deletes nodes
            {
                Node<valueType>* next = current->getNext();
                delete current;
                current = next; 
            }
        }

        // Precondition: Only takes a string, won't work for other data types
        // Postcondition: each word within the string is added to a Node within the LinkedList
/*         void add(const std::string toAdd)
        {

            std::istringstream ss(toAdd);

            while(ss) // while there are words left in string
            {
                std::string word; // has to be a string

                ss >> word; // get word from string stream

                if (word != "") // if the word has a value
                {
                    addToTail(word); // add word to tail of the linked list
                }

            }

        } */

        // Precondition: atleast one Node exists
        // Postcondition: Removes all data that matches the given data
        void remove(const valueType toRemove)
        {
            reset(); // sets the current pointer to the head of the linked list

            int ammountRemoved = 0;

            for(int i = 0; i < size; i++) // for each item in list
            {
                

                if (current->getData() == toRemove) // if search is a match delete node
                    {
                        
                        if(current == head ) // if the data being removed is at the head of the linked list
                        {
                            Node<valueType>* nodeDelete = current; // location of the node being deleted

                            nextCurrent(); // move current to next Node

                            current->setPrev(NULL); // point the new head prev to NULL

                            head = current; // move the head to the new start of the LinkedList

                            delete nodeDelete; // deallocate the memory assigned to the node
                        }
                        else if (current == tail) // if the data being removed is at the tail of the linked list
                        {
                            Node<valueType>* nodeDelete = current; // location of the node being deleted

                            prevCurrent(); // move current to prev Node

                            current->setNext(NULL); // point the new tail next to NULL

                            tail = current; // move the tail to the new end of the LinkedList
                            
                            delete nodeDelete; // deallocate the memory assigned to the node
                        }
                        
                        else
                        {

                            Node<valueType>* nodeDelete = current; // store the location of the node to be delete.

                            prevCurrent(); // move back in the list 

                            current->setNext(nodeDelete->getNext()); // remove the link between the current node and the node to be deleted

                            nextCurrent(); // move forward in the list | Note: nodeDelete will be skipped cause the link was removed above

                            current->setPrev(nodeDelete->getPrev()); // remove the link between the current node and the node to be delete | the node has now been removed from list

                            delete nodeDelete; // deallocate the memory assigned to the node

                        }
                        
                        
                        ammountRemoved++; // store the size decrease of the linked list

                    }
                    else // contine to the next node
                    {
                        nextCurrent(); // increment the LinkedList
                    }
                    
            }

            size -= ammountRemoved; // reduce the size of the list by the ammount of items removed
        }


        // Precondition: List length is greater or equal to 2
        // Postcondition: the LinkedList is sorted
        void sort()
        {
            bool swapped; // bool to test if the sort swapped somthing


            reset(); // set current to head

            for(int i = 0; i < (size - 1); i++) // for each item in list excpeted the last item
            {
                Node<valueType>* tmp = current->getNext();



                if(current->getData() > tmp->getData()) // if current is larger then temp swap them
                {


                    valueType tmpData = current->getData();

                    //swap
                    current->setData(tmp->getData());
                    tmp->setData(tmpData);

                    swapped = true; // set swap to true

                }

                nextCurrent(); // incremetns current pointer
            }





            if (swapped) // if an item was swapped run sort again.
                sort();


        }

        // Precondition: none
        // Postcondition: returns how many data item within the LinkedList match a given data item.
        int count(const valueType toCount)
        {
            reset(); // set current to head
            
            int i = 0;
            
            for (int j = 0; j < size; j++) // for each item in list
                {
                    if(current->getData() == toCount) // if search matches
                        i++; // increment count

                    nextCurrent(); // move to next node
                }

            
            return	i; // return counted ammount
        }
                
        // Precondition: atleast one Node exists
        // Postcondition: puts all the data within the LinkedList into a single valueType
        valueType out()
        {
            valueType output;


            for(int i = 0; i < size; i++) // for each item in list
            {

                //std::cout << current << " " << current->getData() << " " <<  i << std::endl;
                output.append( current->getData() + " " );
                nextCurrent();

            }
            
            return output;
        }

        
        // Precondition: none
        // Postcondition: The current pointer is set to the head of the LinkedList
        void reset()
        {
            current = head;
        }

        // Operator Overloads:

        // Precondition: their are two LinkedLists
        // Postcondition: a copy of the second list is now on the end of the first
        void operator +=( LinkedList& ll)
        {
            //ensure the LL current pointers are at the head
            reset();
            ll.reset();

            while(!ll.atEnd()) // while there are more nodes
            {
                addToTail(ll.getCurrentData()); // add current data to LinkedList

                ll.nextCurrent(); // increment the ll
            }


        }

        // Precondition: the data to add is given
        // Postcondition: A valueType is added to the end of the LinkedList
        void addToTail(const valueType toAdd)
        {

            if (size == 0) // if there are no other nodes
            {
                head = new Node<valueType>(toAdd); // create new node and point head at it
                tail = head; // aslo point tail at it
                reset();


                size = 1; // set list size to 0
            }
            else
            {
                current = new Node<valueType>(toAdd, NULL, tail); // point current to a new Node with the data value of toAdd next to NULL and tail to Prev

                tail->setNext(current); // Link current to the tail

                tail = current; // move the tail to the new end of the linked list

                reset();

                size++; // increment the size of the list
            }
            

        }
        
        valueType getHeadData()
        {
            return head->getData();
        }

        void deleteHead()
        {
            reset();

            Node<valueType>* nodeDelete = current; // location of the node being deleted

            nextCurrent(); // move current to next Node

            current->setPrev(NULL); // point the new head prev to NULL

            head = current; // move the head to the new start of the LinkedList

            delete nodeDelete; // deallocate the memory assigned to the node
        }


    private:
        Node<valueType>* head;
        Node<valueType>* tail;
        Node<valueType>* current;

        int size;

        // Precondition: none
        // Postcondition: returns true if the current pointer points to NULL.
        bool atEnd() const
        {
            if (current == NULL) // if the current pointer is null
                return true; // the return that we are at the end of list
            else
                return false;
        }


        // Precondition: none
        // Postcondition: the current pointer is moved to the next Node
        void nextCurrent()
        {
            current = current->getNext();
        }

        // Precondition: none
        // Postcondition: the current pointer to moved to the prev Node
        void prevCurrent()
        {
            current = current->getPrev();
        }
        
        // Precondition: Current is not NULL
        // Postcondition: the data store in the Node current points to is returned
        valueType getCurrentData() const
        {
            return current->getData();
        }
};
/* 

    std::ostream& operator <<(std::ostream& os, LinkedList& p)
    {
        p.reset();

        os << p.out();
        return os;
    } */


#endif
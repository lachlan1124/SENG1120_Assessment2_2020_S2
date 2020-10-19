#include "LinkedList.h"

template<typename valueType> LinkedList<valueType>::LinkedList()
{
    head = NULL; // head default value
    tail = NULL; // tail default value
    current = NULL; // current default value
            
    size = 0; // size of list when first initialized
}

template<typename valueType> LinkedList<valueType>::~LinkedList()
{
    reset(); // sets current to head

    for(int i = 0; i < size; i++) // traverses list and deletes nodes
    {
        Node<valueType>* next = current->getNext();
        delete current;
        current = next; 
    }
}

template<typename valueType> void LinkedList<valueType>::remove(const valueType toRemove)
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

template<typename valueType> void LinkedList<valueType>::sort()
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


template<typename valueType> int LinkedList<valueType>::count(const valueType toCount)
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

template<typename valueType> valueType LinkedList<valueType>::out()
{
    valueType output;


    for(int i = 0; i < size; i++) // for each item in list
    {
        output.append( current->getData() + " " );
        nextCurrent();

    }
    
    return output;
}

template<typename valueType> void LinkedList<valueType>::reset()
{
    current = head;
}

template<typename valueType> void LinkedList<valueType>::operator +=( LinkedList& ll)
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

template<typename valueType> void LinkedList<valueType>::addToTail(const valueType toAdd)
{
    reset();
    
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

template<typename valueType> valueType LinkedList<valueType>::getHeadData()
{
    return head->getData();
}

template<typename valueType> void LinkedList<valueType>::deleteHead()
{
    if (size == 1) // if only one node left
    {
        delete head;
        tail = NULL;
        head = NULL;
    }
    
    if (size > 1)
    {
    reset();

    Node<valueType>* nodeDelete = current; // location of the node being deleted

    nextCurrent(); // move current to next Node

    current->setPrev(NULL); // point the new head prev to NULL

    head = current; // move the head to the new start of the LinkedList

    delete nodeDelete; // deallocate the memory assigned to the node

    }
    
    

    size--; // increment the size
}



// Privte functions implementations below



template<typename valueType> bool LinkedList<valueType>::atEnd() const
{
    if (current == NULL) // if the current pointer is null
        return true; // the return that we are at the end of list
    else
        return false;
}

template<typename valueType> void LinkedList<valueType>::nextCurrent()
{
    current = current->getNext();
}

template<typename valueType> void LinkedList<valueType>::prevCurrent()
{
    current = current->getPrev();
}

template<typename valueType> valueType LinkedList<valueType>::getCurrentData() const
{
    return current->getData();
}


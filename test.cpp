
#include "Node.h"
#include "Card.h"

int main()
{
    Node<Card>* test = new Node<Card>(Card("test", 5, true), NULL, NULL);

    std::cout << test->getData().getValue() << std::endl; 
}


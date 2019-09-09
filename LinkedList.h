//Originally copied from Lab 1

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include <string>

//  LinkedList is the class that manages nodes to build a list that can
//  be traversed both forwards and backwards
class LinkedList
{
public:

    //  @pre    None.
    //  @post   A LinkedList object is created, with null pointers to the first and last nodes
    LinkedList();

    ~LinkedList();

    //  @pre    None.
    //  @post   None.
    //  @return Returns the size of the list (the number of nodes)
    int getSize();

    //  @pre    None.
    //  @post   A new node is created with the passed value and pointers are updated properly
    //  @param  value - the integer value to be stored in the new node
    //  @note   The new node is at the end of the list
    bool insert(string value);

    //  @pre    None.
    //  @post   None.
    //  @return True if the list is empty, false otherwise
    bool isEmpty();

    //  These were used for debugging, they return pointers to the first and last nodes respectively
    Node* getFirst(); // temporary, used for testing
    // Node* getLast(); // same here

    //  @pre    None.
    //  @post   The list is printed from "first" to "last"
    void print();

    //  @pre    At least one node with the requested value exists
    //  @post   The node is removed
    //  @param  value - The requested value to be removed
    //  @return False if fails (i.e. the value doesn't exist), true otherwise
    bool remove(string value);

    // The following functions were removed when converting to a singly linked list

    //  @pre    At least one node exists.
    //  @post   None.
    //  @return The smallest and largest value in the list, respectively
    // int smallest();
    // int largest();

    //  @pre    At least one node exists.
    //  @post   None.
    //  @return The average (mean) value of all the numbers in the list
    // float average();

    //  @pre    At least one node exists
    //  @post   Reverses the list (the first node becomes the last node, etc.)
    // bool reverse();

    //  @pre    None
    //  @post   The parent list is merged with the new parameter list, and they are sorted in ascending order
    // void merge(LinkedList* newList);
    
private:
    Node* m_first;
    // Node* m_last;
    int m_size;
};

#endif
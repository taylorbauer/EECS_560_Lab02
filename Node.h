//Originally copied from Lab 1

#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

//  The node class is contains the values and pointers of each position on the
//  linked list.  It should only be called by LinkedList
class Node
{
public:

    //  @pre    None.
    //  @param  value - the value to be stored to the node
    //  @post   A node is created with the value stored and pointers initialized.
    Node(string value);

    //  @pre    None.
    //  @return The value stored by the called node
    string getValue();

    //  @pre    None.
    //  @return Returns the pointer the the "next" node.
    //  @note:  Value is nullptr if it is the last (or only) node in the list
    Node* getNext();

    //  @pre    None.
    //  @param  next - a pointer to what will now be the next node in the list
    //  @post   The next node pointer is set
    void setNext(Node* next);

    //  The following were removed when converting to a singly linked list

    //  @pre    None.
    //  @return Returns the pointer the the "previous" node.
    //  @note:  Value is nullptr if it is the first (or only) node in the list
    // Node* getPrev();

    //  @pre    None.
    //  @param  prev - a pointer to what will now be the previous node in the list
    //  @post   The previous node pointer is set
    // void setPrev(Node* prev);

private:
    string m_value;
    // Node* m_prev;
    Node* m_next;
    
};

#endif
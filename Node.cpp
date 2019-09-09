//Originally copied from Lab 1
// Converted from a doubly linked list that took ints to a singly linked list that takes strings

#include "Node.h"
#include <string>

using namespace std;

Node::Node(string value){
    m_value = value;
}

string Node::getValue(){
    return m_value;
}

Node* Node::getNext(){
    return m_next;
}

void Node::setNext(Node* next){
    m_next = next;
}

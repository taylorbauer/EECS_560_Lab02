//Originally copied from Lab 1

#include "Node.h"

Node::Node(int value){
    m_value = value;
}

int Node::getValue(){
    return m_value;
}

Node* Node::getNext(){
    return m_next;
}

void Node::setNext(Node* next){
    m_next = next;
}

Node* Node::getPrev(){
    return m_prev;
}

void Node::setPrev(Node* prev){
    m_prev = prev;
}
// Originally copied from Lab 1

#include "LinkedList.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

LinkedList::LinkedList() {
    m_size = 0;
    m_first = nullptr;
}

LinkedList::~LinkedList() {
    Node* current = m_first;
    Node* next = nullptr;
    while (m_size != 0) {
        next = current->getNext();
        delete current;
        m_size --;
        current = next;
    }
}

int LinkedList::getSize(){
    return m_size;
}

bool LinkedList::insert(string value){
    Node* finder = m_first;
    for (int i = 0; i < m_size; i++) {
        if (finder->getValue() == value) {
            return false;
        }
        else {
            finder = finder->getNext();
        }
    }

    Node* tempNode = new Node(value);
    
    if (!isEmpty()) {
        tempNode->setNext(m_first);
    }

    m_first = tempNode;

    m_size ++;
    return true;
}

bool LinkedList::isEmpty(){
    if (m_size == 0) {
        return true;
    }
    else {
        return false;
    }
}

Node* LinkedList::getFirst(){
    return m_first;
}

void LinkedList::print(){
    if (isEmpty()) {
        cout << "\n";
        return;
    }

    Node* tempPtr = m_first;
    for (int i = 0; i < m_size; i++) {
        cout << " <- " << tempPtr->getValue();
        tempPtr = tempPtr->getNext();
    }
    cout << "\n";
}

bool LinkedList::remove(string value){
    Node* nodePtr = m_first;
    Node* prevPtr = nullptr;
    int nodeCount = 0;
    for (int i = 0; i < m_size; i++){
        if (nodePtr->getValue() == value){
            if (m_size == 1){
                m_first = nullptr;
            }
            else if (nodeCount == 0){
                m_first = m_first->getNext();
            }
            else {
                prevPtr->setNext(nodePtr->getNext());
            }

            delete nodePtr;

            m_size --;
            return true;
        }
        
        nodeCount ++;
        prevPtr = nodePtr;
        nodePtr = nodePtr->getNext();
    }
    return false;
}

bool LinkedList::find(string key) {
    Node* tracker = m_first;
    for (int i = 0; i < m_size; i++) {
        if (tracker->getValue() == key) {
            return true;
        }
        else {
            tracker = tracker->getNext();
        }
    }
    return false;
}

// int LinkedList::smallest(){
//     Node* nodeTracker = m_first;
//     int smallest = nodeTracker->getValue();
//     nodeTracker = nodeTracker->getNext();
//     for (int i = 1; i < m_size; i ++) {
//         if (nodeTracker->getValue() < smallest){
//             smallest = nodeTracker->getValue();
//         }
//         nodeTracker = nodeTracker->getNext();
//     }
//     return smallest;
// }

// int LinkedList::largest(){
//     Node* nodeTracker = m_first;
//     int largest = nodeTracker->getValue();
//     nodeTracker = nodeTracker->getNext();
//     for (int i = 1; i < m_size; i ++) {
//         if (nodeTracker->getValue() > largest){
//             largest = nodeTracker->getValue();
//         }
//         nodeTracker = nodeTracker->getNext();
//     }
//     return largest;
// }

// float LinkedList::average(){
//     int sum = 0;
//     Node* nodeTracker = m_first;
//     for (int i = 0; i < m_size; i++) {
//         sum = sum + nodeTracker->getValue();
//         nodeTracker = nodeTracker->getNext();
//     }
//     return ((float)sum / m_size);
// }

// bool LinkedList::reverse(){
//     if (m_size < 1){
//         return false;
//     }
//     else {
//         Node* nodeTracker = m_last;
//         int lastValue = 0;
//         int staticSize = m_size;  // Forces our loop to work
//         for (int i = 0; i < staticSize; i++) {
//             insert(nodeTracker->getValue());
//             nodeTracker = nodeTracker->getPrev();
//         }
//         for (int i = 0; i < staticSize; i++) {
//             remove(m_first->getValue());
//         }
//         return true;
//     }
// }

// void LinkedList::merge(LinkedList* userList) {
//     // Copy and delete each value from the old list to the user list
//     int tempValue;
//     while (m_size != 0){
//         tempValue = m_first->getValue();
//         userList->insert(tempValue);
//         remove(tempValue);
//     }

//     // Now user list is a long list containing both lists, and orignal list is empty
//     // Scan through the new list, copy the smallest value over to the original list, and delete it from the new
//     int smallest;
//     Node* nodeTracker;
//     if (userList->getSize() == 0 && m_size == 0) {
//         cout << "\nBoth lists are empty!\n\n";
//         return;
//     }
//     while (userList->getSize() > 0) {
//         smallest = userList->getFirst()->getValue();
//         nodeTracker = userList->getFirst();
//         for (int i = 0; i < userList->getSize(); i++) {

//             if (smallest > nodeTracker->getValue()) {
//                 smallest = nodeTracker->getValue();
//             }
//             nodeTracker = nodeTracker->getNext();
//         }

//         insert(smallest);
//         userList->remove(smallest);
//     }
//     cout << "\nLists merged and sorted successfully!\n";
//     return;
// }
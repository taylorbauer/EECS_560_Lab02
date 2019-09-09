// The class that handles all user interaction and managing of hash table

#ifndef MENU_H
#define MENU_H

#include "HashTable.h"

class Menu {
public:
    Menu(HashTable* table);
    void run();
private:
    HashTable* m_table;
};

#endif
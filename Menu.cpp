#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;

Menu::Menu(HashTable* table) {
    m_table = table;
}

void Menu::run() {
    cout << "Running...\n\n";
}
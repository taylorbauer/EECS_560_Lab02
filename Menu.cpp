#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;

Menu::Menu(HashTable* table) {
    m_table = table;
}

void Menu::run() {
    cout << "Running...\n\n";
    int selection = 0;
    string insertion = "";
    string searchKey = "";
    string deletion = "";
    int searchReturn = -1;
    while (selection != 5) {
        cout << "\n------------------------------------------------------------\n";
        cout << "Please choose one of the following commands:\n";
        cout << "1) Insert\n";
        cout << "2) Delete\n";
        cout << "3) Find\n";
        cout << "4) Print\n";
        cout << "5) Exit\n\n";
        cout << "Your selection: ";
        cin >> selection;

        switch (selection)  //  This is the first time I've written a switch case in C++
        {
            case 1:
                cout << "Enter the string you would wish to insert (all lowercase, no spaces): ";
                cin >> insertion;
                if (m_table->insert(insertion)) {
                    cout << '\'' << insertion << "\' inserted successfully!\n";
                }
                else {
                    cout << "Unable to insert " << insertion << ", make sure it's not already on the list.\n";
                }
                break;

            case 2:
                cout << "Enter an element to remove: ";
                cin >> deletion;
                if (m_table->remove(deletion)) {
                    cout << '\'' << deletion << "\' deleted successfully!\n";
                }
                else {
                    cout << "Unable to delete " << deletion << ", make sure it's already on the list.\n";
                }
                break;

            case 3:
                cout << "Enter an element to be found: ";
                cin >> searchKey;
                searchReturn = m_table->find(searchKey);
                if (searchReturn != -1 ) {
                    cout << '\'' << searchKey << "\' is found in bucket " << searchReturn << ".\n";
                }
                else {
                    cout << '\'' << searchKey << "\' cannot be found.\n\n";
                }
                break;
            
            case 4:
                m_table->print();
                break;
        }
    }
}
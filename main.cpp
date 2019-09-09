//Originally copied from Lab 1

#include "LinkedList.h"
#include "Node.h"
#include "Menu.h"

#include <iostream>
#include <fstream>
using namespace std;

//  main checks to make sure the program was called properly, creates a LinkedList, and passes
//  it to the Menu class which handles user interaction. 
int main(int argc, char *argv[])
{
    if (argc != 2){
        cout << "Please include a file containing a list of strings.\n";
    }



    fstream myFile;
    myFile.open(argv[1]);

    string value;
    int valueCount = 0;
    
    if (myFile.is_open()){

        //  This block simply counts how many values will go into the hash table to start, and then re-opens it to read
        while (myFile >> value){
            valueCount ++;
        }
        myFile.close();
        myFile.open(argv[1]);

        HashTable* mainTable = new HashTable(valueCount);

        while (myFile >> value){
            mainTable->insert(value);
        }
        myFile.close();
        cout << "\nSuccessfully copied data from " << argv[1] << endl << endl;

        Menu mainMenu(mainTable);
        mainMenu.run();

    }
    else {
        cout << "Error opening file\n";
    }

    return 0;

}
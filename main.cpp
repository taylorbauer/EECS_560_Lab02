//Originally copied from Lab 1

#include "LinkedList.h"
#include "Node.h"

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
    
    if (myFile.is_open()){
        while (myFile >> value){
            
        }
        myFile.close();
        cout << "\nSuccessfully copied data from " << argv[1] << endl << endl;

    }
    else {
        cout << "Error opening file\n";
    }

    return 0;

}
#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

void menu();
void addRecord(StringBinaryTree &tree);
void deleteRecord(StringBinaryTree &tree);
void searchRecord(StringBinaryTree &tree);
void modifyRecord(StringBinaryTree &tree);

int main() {
    StringBinaryTree codesTree;
    string code;
    
    ifstream inputFile("codes.txt");
    if(!inputFile) {
        cout << "Could not open the designated file\n";
    }
    else {
        while(inputFile >> code) {
            codesTree.insertNode(code);
        }
    }

    inputFile.close();

    int choice;

    while (choice != 5) {
        menu();
        
        cout << "Please enter your choice: (1-5) ";
        cin >> choice;

        if (choice < 1 || choice > 5) {
            cout << "Invalid input. Please try again.\n";
        }
        else {
            switch(choice) {
                case 1:
                    addRecord(codesTree);
                    break;
                case 2:
                    deleteRecord(codesTree);
                    break;
                case 3:
                    searchRecord(codesTree);
                    break;
                case 4:
                    modifyRecord(codesTree);
                    break;
                case 5:
                    cout << "Goodbye!\n"; 
                    break;
            }
        }
    }



    codesTree.displayInOrder();

    return 0;
}

void menu() {
    cout << "BST Menu:\n";
    cout << "1. Add a new code\n";
    cout << "2. Delete an existing code\n";
    cout << "3. Search for a code\n";
    cout << "4. Modify a code\n";
    cout << "5. Exit\n";
}
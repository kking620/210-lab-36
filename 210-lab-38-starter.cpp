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

    codesTree.displayInOrder();

    return 0;
}
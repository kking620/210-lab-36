#include <iostream>
#include <fstream>
#include <string>
//including the header file in order to ensure that the proper Binary Tree functions will be executed
#include "IntBinaryTree.h"
using namespace std;

//prototype functions for displaying the menu, adding a record, deleting a record, searching for a record, and modifying a given record respectively
void menu();
void addRecord(StringBinaryTree &tree);
void deleteRecord(StringBinaryTree &tree);
void searchRecord(StringBinaryTree &tree);
void modifyRecord(StringBinaryTree &tree);

int main() {
    //initializing a StringBinaryTree object labeled codesTree that will store our codes
    StringBinaryTree codesTree;
    //initializing the string variable labeled code that will serve as a temporary storage of the codes we will retrieve from the external text file
    string code;
    
    //This code block attempts to open the external text file and if it successfully does so, then it retrieves the codes from the text file and calls the insertNode function with the code as an argument
    //until the text file has been fully traversed. If this file cannot be opened, then it returns an error message.
    ifstream inputFile("codes.txt");
    if(!inputFile) {
        cout << "Could not open the designated file\n";
    }
    else {
        while(inputFile >> code) {
            codesTree.insertNode(code);
        }
    }

    //closes the files that was previously opened
    inputFile.close();

    //initializing the choice variable, which is what will determine what action will be taken with the menu
    int choice;

    //a while loop that will continuously loop until the sentinel value of 5 is entered into the choice variable
    while (choice != 5) {
        //calls the menu function to display the user options
        menu();
        
        //prompts the user to enter their desired action
        cout << "Please enter your choice: (1-5) ";
        cin >> choice;
        
        //if the choice variable is not valid, then we will return this message
        if (choice < 1 || choice > 5) {
            cout << "Invalid input. Please try again.\n";
        }
        //if the choice value is valid, then we will use the choice variable as an argument for the switch to determine what function is called
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

    //once the user has finished interacting with the tree, the program displays the updated tree
    codesTree.displayInOrder();

    return 0;
}

//void function that displays the options the user can take
void menu() {
    cout << "BST Menu:\n";
    cout << "1. Add a new code\n";
    cout << "2. Delete an existing code\n";
    cout << "3. Search for a code\n";
    cout << "4. Modify a code\n";
    cout << "5. Exit\n";
}

//void function that adds a piece of user inputted code to the tree, unless the code already exists then we will return a message saying that the code exists without adding it to the tree
void addRecord(StringBinaryTree &tree) {
    string code;
    cout << "Enter the new code you wish to add: ";
    cin >> code;

    if(tree.searchNode(code)) {
        cout << "This code already exists!\n";
    }
    else {
        tree.insertNode(code);
        cout << code << " has been succefully added.\n";
    }
}

//void function that deletes a designated string of code from the tree, but if the code does not exist within our tree, then we will return an error message without deleting anything from the tree
void deleteRecord(StringBinaryTree &tree){ 
    string code;
    cout << "Enter the code you wish to delete: ";
    cin >> code;

    if(!tree.searchNode(code)) {
        cout << "This code does not exist!\n";
    }
    else {
        tree.remove(code);
        cout << code << " has been succefully deleted.\n";
    }
}

//void function that asks the user to input a specific code to determine whether or not it is in the designated tree
void searchRecord(StringBinaryTree &tree){ 
    string code;
    cout << "Enter the code you wish to find: ";
    cin >> code;

    if(tree.searchNode(code)) {
        cout << code << " exists in the tree!\n";
    }
    else {
        cout << code << " does not exist in the tree.\n";
    }
}

//void function that modifies a specific code within the text file
void modifyRecord(StringBinaryTree &tree){ 
    
    //initializes the original code and the newly modified code
    string originalCode;
    string newCode;

    //requests the user to input which code they want to modify
    cout << "Enter the code you wish to modify: ";
    cin >> originalCode;

    if (!tree.searchNode(originalCode)) {
        cout << "Original code not found within the tree.\n";
        return;
    }

    //requests the user to enter the new modified code
    cout << "Enter the modified code: ";
    cin >> newCode;

    if (tree.searchNode(newCode)) {
        cout << "Modified code already exists elsewhere. Cannot modify.\n";
        return;
    }
    
    //removes the old code and replaces it with the newly modified code
    tree.remove(originalCode);
    tree.insertNode(newCode);
    cout << "Code successfully modified from " << originalCode << " to " << newCode << ".\n";
}

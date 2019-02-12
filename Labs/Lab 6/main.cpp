/*********************************************************************
** Author: Andrew Wilson
** Date: Jan 15, 2019
** Description: Main file for linked list
*********************************************************************/
#include <iostream>
#include "node.hpp"
#include "linkedlist.hpp"
#include "validation.hpp"


using std::cin;
using std::cout;
using std::endl;

void showMainMenu();

int main()
{
    int userChoice = 0;
    Linkedlist list;

    clearScreen();
    while(userChoice != 9)
    {
        showMainMenu();
        userChoice = validateInt(1, 9);

        switch(userChoice)
        {
            case 1: 
            {
                cout << "Please enter a positive integer: ";
                list.addNodeHead(validatePositiveInt());
                list.transverseForward();
                break;
            }
            case 2:
            {
                cout << "Please enter a positive integer: ";
                list.addNodeTail(validatePositiveInt());
                list.transverseForward();
                break;
            } 
            case 3:
            {
                list.rmNodeHead();
                list.transverseForward();
                break;
            } 
            case 4:
            {
                list.rmNodeTail();
                list.transverseForward();
                break;
            } 
            case 5:
            {
                list.transverseBackward();
                break;            
            } 
            case 6:
            {
                list.getHeadValue();
                list.transverseForward();
                break;
            } 
            case 7:
            {
                list.getTailValue();
                list.transverseForward();
                break;
            }
            case 8:
            {
                list.readFromFile();
                list.transverseForward();
                break;
            }  
            case 9:
            {
                return 0;
            }
        }
    }
    return 0;
}

void showMainMenu()
{
    cout << "\nChoose from the following options: \n" << endl;
    cout << "1. Add a new node to the head" << endl;
    cout << "2. Add a new node to the tail" << endl;
    cout << "3. Delete from head" << endl;
    cout << "4. Delete from tail" << endl;
    cout << "5. Traverse the list reversely" << endl;
    cout << "6. Print the value of the head node" << endl;
    cout << "7. Print the value of the tail node" << endl;
    cout << "8. Add values from \"numberfile.txt\"" << endl;    
    cout << "9. Exit\n" << endl;
    cout << "Choice: ";
}
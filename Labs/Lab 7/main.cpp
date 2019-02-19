/*********************************************************************
** Author: Andrew Wilson
** Date: Jan 15, 2019
** Description: Main file for linked list
*********************************************************************/
#include <iostream>
#include "queue.hpp"
#include "validation.hpp"


using std::cin;
using std::cout;
using std::endl;

void showMainMenu();

int main()
{
    int userChoice = 0;
    Queue queue;

    clearScreen();
    while(userChoice != 5)
    {
        showMainMenu();
        userChoice = validateInt(1, 5);
        clearScreen();

        switch(userChoice)
        {
            case 1: 
            {
                cout << endl << "Please enter a positive integer: ";
                queue.addBack(validatePositiveInt());
                clearScreen();
                break;
            }
            case 2:
            {
                if(queue.isEmpty())
                {
                    std::cout << "The queue is empty! \n";
                }
                else
                {
                    cout << "The front value is: " << queue.getFront();
                }
                break;
            } 
            case 3:
            {
                if(queue.isEmpty())
                {
                    std::cout << "The queue is empty! \n";
                }
                else
                {
                    queue.removeFront();
                }
                break;
            } 
            case 4:
            {
                if(queue.isEmpty())
                {
                    std::cout << "The queue is empty! \n";
                }
                else
                {
                    cout << "The queue is: ";
                    queue.printQueue();
                }
                break;
            } 
            case 5:
            {
                return 0;
                break;            
            } 
        }
    }
    return 0;
}

void showMainMenu()
{
    cout << "\nChoose from the following options: \n" << endl;
    cout << "1. Add a value to the back of queue" << endl;
    cout << "2. Display the front value" << endl;
    cout << "3. Remove the front node" << endl;
    cout << "4. Display the queue's content" << endl;   
    cout << "5. Exit\n" << endl;
    cout << "Choice: ";
}
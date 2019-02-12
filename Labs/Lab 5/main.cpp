/*********************************************************************
** Author: Andrew Wilson
** Date: Jan 15, 2019
** Description: Main file for recursive functions
*********************************************************************/
#include <iostream>
#include <string>
#include "recursiveFunctions.hpp"
#include "validation.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void menuReverseString();  //submenu, prompts user for string input and prints the revers
void menuSumArray();  //submenu, prompts user for array size and contents, and prints the sum
void menuTriangle();  //submenu, prompts user for triangle "seed" and prints its triangle number

int main()
{
    int mainMenuChoice = 0;

    while(mainMenuChoice != 4)
    {
        clearScreen();
        cout << "1. Reverse string" << endl;
        cout << "2. Sum array" << endl;
        cout << "3. Calculate triangle number" << endl;
        cout << "4. Exit" << endl;
        cout << "Please enter selection: ";
        cin >> mainMenuChoice;
        validateInt(mainMenuChoice, 1, 4);
        
        if(mainMenuChoice == 1)
        {
            menuReverseString();
        }
        else if(mainMenuChoice == 2)
        {
            menuSumArray();
        }
        else if(mainMenuChoice == 3)
        {
            menuTriangle();
        }
    }

    cout << endl << "Goodbye!" << endl;
    return 0;
}

void menuReverseString()  //submenu, prompts user for string input and prints the revers
{
    clearScreen();
    string inputString;

    cout << "Please enter a string to reverse:" << endl;
    inputString = getValidatedString();
    reverseString(inputString);

    std::cout << "Press enter to continue...";
    std::cin.get();  //Proceed after user presses enter
}

void menuSumArray()  //submenu, prompts user for array size and contents, and prints the sum
{
    clearScreen();
    int arraySize = 0;

    cout << "How many integers will you sum?" << endl;
    cin >> arraySize;
    validateInt(arraySize);
    
    int * intArray = new int[arraySize];

    for(int i = 0; i < arraySize; i++)
    {
        int temp;
        cout << "Please enter integer #" << i + 1 << ": ";
        cin >> temp;
        validateInt(temp);
        intArray[i] = temp;
    }
    
    cout << endl << "The sum is: " << sumArray(intArray, arraySize) << endl;
    delete [] intArray;
    systemPause();
}

void menuTriangle()  //submenu, prompts user for triangle "seed" and prints its triangle number
{
    clearScreen();
    int triangle = 0;

    cout << "Please enter a value to display its triangle number (0-65000): " << endl;
    cin >> triangle;
    validateInt(triangle, 0, 65000);
    cout << endl << "The triangle number is: " << triangleNum(triangle) << endl;
    systemPause();
}
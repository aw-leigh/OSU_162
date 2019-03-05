#include <iostream>
#include <string>
#include <stack> 
#include <queue> 
#include <stdlib.h> //rand
#include <time.h>  //time

#include "validation.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stack;
using std::queue;


void palindromize();
void buffer();

int main()
{
    srand (time(NULL));  //initialize random seed

    int menuChoice = 0;

    do
    {
        clearScreen();
        cout << "1. Make a palindrome" << endl;
        cout << "2. Simulate a buffer" << endl;
        cout << "3. Exit" << endl;
        cout << "Please choose an option: ";

        menuChoice = validateInt(1, 3);

        if(menuChoice == 1)
            palindromize();
        else if(menuChoice == 2)
            buffer();

    }while(menuChoice != 3);

    return 0;
}

void palindromize()
{
    string input;
    stack<char> charStack;

    clearScreen();
    
    cout << "Please enter a string to palindromize:" << endl;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::getline(cin, input);

    for(char i : input)
    {
        charStack.push(i);
    }

    cout << "\nYour palindromized string is:" << endl
         << input;

    for(char i : input)
    {
        cout << charStack.top();
        charStack.pop();
    }
	cout << endl << endl << "Press enter to continue...";
	cin.get();  // Proceed after new input from user
    return;    
}

void buffer()
{
    int N, rounds, addChance, removeChance;
    double avgLength = 0;
    std::queue<int> queue;
    std::queue<int> tempQueue;

    clearScreen();

    cout << "How many rounds would you like to run? (1-10000): ";
    rounds = validateInt(1, 10000);

    cout << "\nChoose a percentage chance to add a random number to the buffer (1-100): ";
    addChance = validateInt(1, 100);

    cout << "\nChoose a percentage chance to remove the front number from the buffer (1-100): ";
    removeChance = validateInt(1, 100);

    for(int i = 0; i < rounds; i ++)
    {
        N = ((rand() % 1000) + 1);

        if(((rand() % 100) + 1) <= addChance)
        {
            queue.push(N);
        }

        if(((rand() % 100) + 1) <= removeChance)
        {
            if(!queue.empty())
            {
                queue.pop();
            }
        }

        cout << "\nRound " << i+1 << "\nCurrent numbers in the buffer:" << endl;
        tempQueue = queue;
        while(!tempQueue.empty())
        {
            cout << tempQueue.front() << ' ';
            tempQueue.pop();
        }

        cout << "\nCurrent buffer length: " << queue.size() << endl;

        avgLength = ((avgLength * i) + queue.size()) / (i+1);

        cout << "Average buffer length: " << avgLength << endl;
    }
    systemPause();
}
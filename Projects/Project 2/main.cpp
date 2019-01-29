#include <iostream>
#include <iomanip> //setw
#include "validation.hpp"
#include "zoo.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::setw;

int main()
{

    int startingFunds, numTigers, numPenguins, numTurtles= 0;

    clearScreen();

    cout << "WELCOME TO ZOO TYCOON" << endl << endl;

    cout << "You have $25000 to start with, spend it wisely!" << endl << endl;
    startingFunds = 25000;

    cout << "There are three types of animal available for purchase:" << endl << endl;
    cout << setw(22) << "Tigers" << setw(12) << "Penguins" << setw(12) << "Turtles" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Cost: " << setw(16) << "$10,000" << setw(12) << "$1,000" << setw(12) << "$100" << endl;
    cout << "Litter size:" << setw(10) << "1 baby" << setw(12) << "5 babies" << setw(12) << "10 babies" << endl;
    cout << "Food cost:" << setw(12) << "5x base" << setw(12) << "1x base" << setw(12) << "1/2 base" << endl;
    cout << "Payout:" << setw(15) << "$2,000" << setw(12) << "$100" << setw(12) << "$5" << endl << endl;
    cout << "Keep in mind, the base food cost is $100 per day!" << endl << endl;
    
    cout << "You must buy either 1 or 2 of each animal." << endl << endl;
    cout << "How many tigers will you buy? (1 or 2): ";
    cin >> numTigers;
    validateRangedInt(numTigers, 1, 2);
    cout << "How many penguins will you buy? (1 or 2): ";
    cin >> numPenguins;
    validateRangedInt(numPenguins, 1, 2);
    cout << "How many turtles will you buy? (1 or 2): ";
    cin >> numTurtles;
    validateRangedInt(numTurtles, 1, 2);

    Zoo(startingFunds, numTigers, numPenguins, numTurtles);
    cout << "Thanks for playing!" << endl;
    return 0;
}
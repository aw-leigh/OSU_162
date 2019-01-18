/********************************************************************* 
** Author:      Andrew Wilson
** Date:        Jan 13, 2019
** Description: Main function for Langdon's ant.

                The ant starts at a user specified location on the board.

                If the ant is on a white space, turn right 90 degrees and change the space to black.
                If the ant is on a black space, turn left 90 degrees and change the space to white.
                
                For the initial direction of the ant, it can be either random,
                or fixed, or a choice from the user; it is up to your design decision. 
                 
                During each step, the program should print the board.
                If the space is occupied by an ant, no matter what the color of that square is, 
                the program should print a “*” on that space; 
                
                otherwise, if the space is white space, print a space character, 
                and if the space is a black space, print a “#” character.

*********************************************************************/

#include <iostream>
#include <stdlib.h> //rand
#include <time.h>  //time
#include "menu.hpp"
#include "ant.hpp"
#include "validation.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int rows, cols, startRow, startCol, numMoves, mainMenuChoice, randomChoice = 0;
    
    if(mainMenu() == 2)
    {
        return 0;
    }

    do{
    clearScreen();

    cout << "EXTRA CREDIT: Would you like to use a random starting location?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Please Enter 1 or 2: ";
    cin >> randomChoice;
    validateRangedInt(randomChoice, 1, 2);

    clearScreen();

    cout << "How many rows? (1-100)\n";
    cin >> rows;
    validateRangedInt(rows, 1, 100);

    cout << "How many columns? (1-100)\n";
    cin >> cols;
    validateRangedInt(cols, 1, 100);

    if(randomChoice == 1)
    {
        srand (time(NULL)); //initialize random seed
        startRow = (rand() % rows + 1);
        startCol = (rand() % cols + 1);
    }
    else
    {
        cout << "Which row will the ant start in? (1-" << rows << ")\n";
        cin >> startRow;
        validateRangedInt(startRow, 1, rows);

        cout << "Which column will the ant start in? (1-" << cols << ")\n";
        cin >> startCol;
        validateRangedInt(startCol, 1, cols);
    }

    cout << "How many steps will the ant take? (1-15000)\n";
    cin >> numMoves;
    validateRangedInt(numMoves, 1, 15000);

    Ant ant(rows, cols, startRow, startCol, numMoves);

    cout << "Would you like to play again?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No (end the program)" << endl;

    cin >> mainMenuChoice;
    validateMenuChoice(mainMenuChoice, 2);  //2 is the main menu length
        
    }while(mainMenuChoice != 2);
    
    return 0;
}
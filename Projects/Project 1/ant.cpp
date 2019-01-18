/*********************************************************************
** Author: Andrew Wilson
** Date: Jan 12, 2019
** Description: Implementation file for Ant class
*********************************************************************/
#include <iostream>
#include "ant.hpp"

Ant::Ant(int rowsIn, int colsIn, int startRowIn, int startColIn, int numMovesIn)
{
    numMoves = numMovesIn;
    boardRows = rowsIn+2; //adding 2 to account for border
    boardCols = colsIn+2; //adding 2 to account for border
    antDirection = NORTH;
    antTile = WHITEANT;
    antRow = startRowIn;
    antCol = startColIn;

    //instantiate the game board
    gameBoard = new char*[boardRows];  
    for (int i = 0; i < boardRows; i++) 
    {
        gameBoard[i] = new char[boardCols];
    }

    //creates border and fills game board with 'white spaces'
    for(int i = 0; i < boardRows; i++)  
    {
        for(int j = 0; j < boardCols; j++)
        {
            if((i == 0 && j == 0)||(i == boardRows-1 && j == 0)||(i == 0 && j == boardCols-1)||(i == boardRows-1 && j == boardCols-1))
            {
                gameBoard[i][j] = '+'; //put a plus symbol in the corners
            }
            else if(i == 0 || i == boardRows-1)
            {
                gameBoard[i][j] = '-'; //put a horizontal line on top/bottom borders
            }
            else if(j == 0 || j == boardCols-1)
            {
                gameBoard[i][j] = '|'; //put a vertical line on side borders
            }
            else
            {
                gameBoard[i][j] = ' ';  //fill with white everywhere else
            }
        }
        std:: cout << std::endl;
    }

    gameBoard[startRowIn][startColIn] = '*';  //place ant in starting location
                                              //normally we would -1 to account for zero indexing,
                                              //but there is a border so the first "movable" row/column starts at index 1
    
    printBoard();
    
    antMove(); //moves the ant numMoves number of times, printing the board each time
}

Ant::~Ant()  //frees memory
{
    for (int i = 0; i < boardRows; i++)
    {
        delete [] gameBoard[i];
    }
    delete [] gameBoard;
}

void Ant::printBoard()
{
    for(int i = 0; i < boardRows; i++)
    {
        for(int j = 0; j < boardCols; j++)
        {
            std::cout << gameBoard[i][j];
        }
        std:: cout << std::endl;
    }
}

void Ant::antMove()
{
    while(numMoves > 0)  //continue until out of moves
    {
        if(antTile == WHITEANT)
        {
            switch (antDirection)
            {
                case NORTH: antDirection = EAST;
                            toggleCurrentSpaceColor(antRow, antCol);  //previous space is now black
                            antCol += 1;  //move one column east
                            boundsCheck(antRow, antCol);  //teleport to other side of board if it's a boundary
                            tileColorCheck(antRow, antCol);

                            gameBoard[antRow][antCol] = '*';
                            break;

                case EAST:  antDirection = SOUTH;
                            toggleCurrentSpaceColor(antRow, antCol);
                            antRow += 1;  //move one row south
                            boundsCheck(antRow, antCol);
                            tileColorCheck(antRow, antCol);

                            gameBoard[antRow][antCol] = '*';
                            break;

                case SOUTH: antDirection = WEST;
                            toggleCurrentSpaceColor(antRow, antCol);
                            antCol -= 1;  //move one column west
                            boundsCheck(antRow, antCol);
                            tileColorCheck(antRow, antCol);

                            gameBoard[antRow][antCol] = '*';
                            break;

                case WEST:  antDirection = NORTH;
                            toggleCurrentSpaceColor(antRow, antCol);
                            antRow -= 1; //move one row north
                            boundsCheck(antRow, antCol);
                            tileColorCheck(antRow, antCol);

                            gameBoard[antRow][antCol] = '*';
                            break;

            }
        }
        else if (antTile == BLACKANT)
        {
            switch (antDirection)
            {
                case NORTH: antDirection = WEST;
                            toggleCurrentSpaceColor(antRow, antCol);  //previous space is now white
                            antCol -= 1;  //move one column west
                            boundsCheck(antRow, antCol);  //teleport to other side of board if it's a boundary
                            tileColorCheck(antRow, antCol);

                            gameBoard[antRow][antCol] = '*';
                            break;

                case EAST:  antDirection = NORTH;
                            toggleCurrentSpaceColor(antRow, antCol);
                            antRow -= 1;  //move one row north
                            boundsCheck(antRow, antCol);
                            tileColorCheck(antRow, antCol);

                            gameBoard[antRow][antCol] = '*';
                            break;

                case SOUTH: antDirection = EAST;
                            toggleCurrentSpaceColor(antRow, antCol);
                            antCol += 1;  //move one column east
                            boundsCheck(antRow, antCol);
                            tileColorCheck(antRow, antCol);

                            gameBoard[antRow][antCol] = '*';
                            break;

                case WEST:  antDirection = SOUTH;
                            toggleCurrentSpaceColor(antRow, antCol);
                            antRow += 1;  //move one row south
                            boundsCheck(antRow, antCol);
                            tileColorCheck(antRow, antCol);
                            
                            gameBoard[antRow][antCol] = '*';
                            break;
            }
        }
        printBoard();
        numMoves--;
    }
    //printBoard();  //this prints the final board state, useful for testing
}

void Ant::boundsCheck(int antRowIn, int antColIn)
{
    if(antRow == 0)  //if ant hits top, teleport to bottom
    {
        antRow = boardRows - 2;
    }
    else if(antRow == boardRows - 1)  //if ant hits bottom, teleport to top
    {
        antRow = 1;
    }
    else if(antCol == 0)  //if ant hits left side, teleport to right side
    {
        antCol = boardCols - 2;
    }
    else if(antCol == boardCols - 1)  //if ant hits right side, teleport to left side
    {
        antCol = 1;
    }
}

void Ant::tileColorCheck(int antRowIn, int antColIn)
{
    if(gameBoard[antRow][antCol] == ' ')
    {
        antTile = WHITEANT;
    }
    else
    {
        antTile = BLACKANT;
    }
}

void Ant::toggleCurrentSpaceColor(int antRowIn, int antColIn)
{
    if(antTile == BLACKANT)
    {
        gameBoard[antRow][antCol] = ' ';
    }
    else
    {
        gameBoard[antRow][antCol] = '#';
    }
}
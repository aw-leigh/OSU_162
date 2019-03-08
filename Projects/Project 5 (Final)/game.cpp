/***************************************************************
** Program name: Final.cpp
** Author:       Andrew Wilson
** Date:         Mar 11, 2019
** Description:  This is the game implementation file for the final project
** Methods:      
***************************************************************/
#include <iostream>

#include "game.hpp"
#include "validation.hpp"
#include "terrain.hpp"
#include "normal.hpp"
#include "player.hpp"
#include "rocket.hpp"

//constructor. Initializes the board
Game::Game(int rows, int cols)
{
    this->numRows = rows;
    this->numCols = cols;
    this->playerDeath = false;
    this->playerWin = false;
    this->lavaTimer = 50;

    //create the board
    gameBoard = new Terrain**[this->numRows];

    for (int i = 0; i < this->numRows; i++)
    {
        gameBoard[i] = new Terrain*[this->numCols];
    }
    //initialize board to normal terrain
    for(int i = 0; i < this->numRows; i++)
    {
        for(int j = 0; j < this->numCols; j++)
        {
            gameBoard[i][j] = new Normal(i, j, rows, cols, gameBoard, 1);
        }
    }

    //fix all the pointers because I can't figure out how to do it in one go
    for(int i = 0; i < this->numRows; i++)
    {
        for(int j = 0; j < this->numCols; j++)
        {
            gameBoard[i][j]->updatePointers(i, j, rows, cols, gameBoard);
        }
    }
    
    //create the rocket in the top row, in the middle. Manually remove fog so it's visible to start.
    gameBoard[0][cols/2]->setContents(new Rocket());
    gameBoard[0][cols/2]->setFOW(false);


    //create the player on the 2nd bottom row, in the middle
    gameBoard[rows-2][cols/2]->setContents(new Player());
    playerPtr = gameBoard[rows-2][cols/2];
}

//constructor. Initializes the board
Game::~Game()
{
    //Deallocate memory for the dynamic arrow.
    for (int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            delete gameBoard[i][j];
        }
        delete [] gameBoard[i];
    }
    delete [] gameBoard;
    gameBoard = nullptr;
}

//prints the board
void Game::printBoard()
{
    playerPtr->updateFOW(gameBoard);
    //Top border
    std::cout.width(numCols + 2);
    std::cout.fill('-');
    std::cout << '-' << std::endl;
    std::cout.fill(' ');

    for(int i = 0; i < numRows; i++)
    {
        std::cout << "|";
        for(int j = 0; j < numCols; j++)
        {
            gameBoard[i][j]->print();
        }
        std::cout << "|\n";
    }

    //Bottom border
    std::cout.width(numCols + 2);
    std::cout.fill('-');
    std::cout << '-' << std::endl;
    std::cout.fill(' ');
}

//prints the board
void Game::runGame()
{
    while(!this->playerDeath && !this->playerWin)  //loop until player wins or dies
    {
        int direction;
        bool moved = false;
        //print instructions/controls/timer etc here
        printBoard();

        //Player interact/move
        do{
            //choose direction
            std::cout << "Choose a direction to move (1 = Up  2 = Left  3 = Down  4 = Right): ";
            std::cin >> direction;
            
            switch(direction)
            {
                case 1: 
                {
                    if(playerPtr->getUp() == nullptr)
                    {
                        std::cout << "You can't move any further in this direction!";
                    }
                    else
                    {
                        playerPtr->interact(playerPtr->getUp());
                        playerPtr = playerPtr->getUp();
                        moved = true;
                    }
                } break;
                case 2:
                {
                    if(playerPtr->getLeft() == nullptr)
                    {
                        std::cout << "You can't move any further in this direction!";
                    }
                    else
                    {
                        playerPtr->interact(playerPtr->getLeft());
                        playerPtr = playerPtr->getLeft();
                        moved = true;
                    }
                } break;
                case 3:
                {
                    if(playerPtr->getDown() == nullptr)
                    {
                        std::cout << "You can't move any further in this direction!";
                    }
                    else
                    {
                        playerPtr->interact(playerPtr->getDown());
                        playerPtr = playerPtr->getDown();
                        moved = true;
                    }
                } break;
                case 4:
                {
                    if(playerPtr->getRight() == nullptr)
                    {
                        std::cout << "You can't move any further in this direction!";
                    }
                    else
                    {
                        playerPtr->interact(playerPtr->getRight());
                        playerPtr = playerPtr->getRight();
                        moved = true;
                    }
                } break;
            }
        }while(!moved);
            
            //player interaction
            //player move
                //move "player" item into new spot "contents"
                //remove "player" item from old spot "contents"
                //update player pointer
        
        //decrement time remaining until lava
            //if 0, lava, and reset timer
    }
}
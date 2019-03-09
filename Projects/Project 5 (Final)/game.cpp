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
#include "rocketpart.hpp"

const int LAVA_FREQUENCY = 15;
const int NUM_ROCKET_PARTS = 6;

//constructor. Initializes the board
Game::Game(int rows, int cols)
{
    this->numRows = rows;
    this->numCols = cols;
    this->playerDeath = false;
    this->playerWin = false;
    this->lavaTimer = LAVA_FREQUENCY;

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
    //fix all the pointers because I can't figure out how to do it in one go; now everything is doubly pointing to its neighbours.
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

    //add items here
    playerPtr->getLeft()->setContents(new Rocketpart()); //put rocket part next to player for testing 

    for (int i = 0; i < NUM_ROCKET_PARTS; i++)
    {
        //The While-loop picks a random row/col, attempts to place a rocket part
        //if unsuccessful pick two more random row/col until success
        while (!addRocketPart(rand() % this->numRows, rand() % this->numCols));
    }

    //add other terrain types here

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
    playerPtr->updateFOW(this->numRows, this->numCols, this->gameBoard);
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
            direction = validateInt(1, 4);
            
            switch(direction)
            {
                case 1: 
                {
                    if(playerPtr->getUp() == nullptr){
                        std::cout << "You can't move any further in this direction!" << std::endl;
                    }
                    else{
                        moved = move(playerPtr->getUp());
                    }
                } break;
                case 2:
                {
                    if(playerPtr->getLeft() == nullptr){
                        std::cout << "You can't move any further in this direction!" << std::endl;
                    }
                    else{
                        moved = move(playerPtr->getLeft());
                    }
                } break;
                case 3:
                {
                    if(playerPtr->getDown() == nullptr){
                        std::cout << "You can't move any further in this direction!" << std::endl;
                    }
                    else{
                        moved = move(playerPtr->getDown());
                    }
                } break;
                case 4:
                {
                    if(playerPtr->getRight() == nullptr){
                        std::cout << "You can't move any further in this direction!" << std::endl;
                    }
                    else{
                        moved = move(playerPtr->getRight());
                    }
                } break;
            }
        }while(!moved);

        lavaCalc();    
        playerWin = true;    
        //decrement time remaining until lava
            //if 0, lava, and reset timer
    }
}

bool Game::move(Terrain* destination)
{
    //clearScreen();
    if(destination->getContents() != nullptr)
    {
        if(destination->getContents()->getName() == "Rocket part") //add part to player inventory
        {
            playerPtr->getContents()->addToInventory(destination->getContents());
            destination->setContents(nullptr);
            std::cout << "You found a rocket part!" << std::endl;
        }
    }
    if(playerPtr->interact(destination)) //if interation was succesful, update player pointer
    {
        playerPtr = destination;
        return true;
    }
    else //if interaction was not successful, kick them back to the direction choice switch
    {
        return false;
    }
}

void Game::lavaCalc(int input)
{
    this->lavaTimer -= input;
    if(this->lavaTimer <= 0)
    {
        //do lava stuff
        this->lavaTimer += LAVA_FREQUENCY;
    }
    std::cout << this->lavaTimer << std::endl;
}

bool Game::addRocketPart(int row, int col)
{
    if (gameBoard[row][col]->getContents() == nullptr) //if the space doesn't have an item already
    {
        gameBoard[row][col]->setContents(new Rocketpart()); //put rocket part there
        return true;
    }
    else  //if the board spot is already filled, return false
    {
        return false;
    }
}
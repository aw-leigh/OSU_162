/***************************************************************
** Program name: Final.cpp
** Author:       Andrew Wilson
** Date:         Mar 11, 2019
** Description:  This is the game specification file for the final project
** Methods:      Game contains a gameboard constructor and destructor,
**               and a printBoard function();
***************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "terrain.hpp"
#include "item.hpp"

class Game
{
    private:
        Terrain*** gameBoard;
        int numRows;
        int numCols;
        int lavaTimer;
        bool playerDeath;
        bool playerWin;
        Terrain* playerPtr = nullptr;
        Terrain* rocketPtr = nullptr;
    public:
        //Constructors and Deconstructor
        Game(int rows, int cols);
        virtual ~Game();

        //Functions
        void runGame();
        void printBoard();
        void setPlayerPtr(Terrain* in);
        //void printGameInfo();
        //bool addAnt(int, int);
        //bool addDoodlebug(int, int);
};

#endif  //Game
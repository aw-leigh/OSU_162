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
        int lavaCounter = 1;
        bool playerDeath;
        bool playerWin;
        Terrain* playerPtr = nullptr;
        Terrain* rocketPtr = nullptr;
    public:
        //Constructors and Deconstructor
        Game(int rows, int cols);
        virtual ~Game();

        //Functions
        bool runGame();
        bool move(Terrain* destination);
        void printBoard();
        void setPlayerPtr(Terrain* in);
        void lavaCalc(int input = 1);
        //void printGameInfo();
        bool addRocketPart(int row, int col);
        bool addLava(int row, int col);
};

#endif  //Game
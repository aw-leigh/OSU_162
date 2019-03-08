/***************************************************************
** Program name: Final.cpp
** Author:       Andrew Wilson
** Date:         Mar 11, 2019
** Description:  This is the main file for the final project
***************************************************************/
#include <iostream>
#include "game.hpp"
#include "headerGraphics.hpp"
#include "validation.hpp"

int main()
{
    clearScreen();
    titleTest();
    Game game(21, 21);
    game.runGame();

    return 0;
}
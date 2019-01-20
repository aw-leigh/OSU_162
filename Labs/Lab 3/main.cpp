/********************************************************************* 
** Author:      Andrew Wilson
** Date:        Jan 20, 2019
** Description: Main function for War Game.

                This is a 2-player game. It is played through dice.
                The player who rolls higher number gets one point. 
                If both players roll the same number, it is considered a draw and no one gets a point.

                It is played with two types of dice: Die, and LoadedDie.
                Die is a fair die, and LoadedDie rolls higher on average than Die.

                The game will prompt for the number of rounds will be played,
                the type of die for each player, and the number of dice sides of each player

                It will output the detailed result of each round, 
                including the side and type of die used for each player, 
                the number each player rolls, and the score result. 
                Afterwards, display the final score count after results of all rounds are printed, 
                and the final winner of the game.

*********************************************************************/
#include <iostream>
#include "validation.hpp"
#include "game.hpp"
#include "die.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Game();
    return 0;
}
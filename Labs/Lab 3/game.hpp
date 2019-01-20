/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 20, 2019
** Description: Header file for Game class
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "die.hpp"

class Game
{   private:
        Die player1;  //stores player 1's die
        Die player2;  //stores player 1's die
        int p1_score;  //tracks player 1's score
        int p2_score;  //tracks player 1's score
        int numRounds;  //stores the number of rounds
        void mainMenu();  //displays main menu
        void gameSetup();  //displays game setup menu
        void playGame();  //runs the game numRounds number of times, reporting results and winner
        void clearScreen();  //clears the screen
    public:
        Game();  //default constructor, shows main menu then sets up game

};

#endif //Die
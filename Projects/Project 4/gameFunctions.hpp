/********************************************************************* 
** Author:      Andrew Wilson
** Date:        Jan 20, 2019
** Description: THe menu and game logic functions for Fantasy Combat Game.
**
** Functions:   showMainMenu shows the main fighter selection menu
                selectCharacters instantiates appropriate character objects
                beginGame runs the game until one character is dead
                combatRound performs one combat round and reports the results
                attackDetails performs an individual attack action
                checkDeath checks if a character has died (SP <= 0)
*********************************************************************/

#include <iostream>
#include <iomanip>  //setw
#include <string>
#include "character.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"
#include "bluemen.hpp"
#include "queue.hpp"


//Takes and int for team #. Prompts for team size, Returns int for team size.
int getTeamSize(int teamNumber);

//shows the menu with fighter options
void showFighterMenu();

//Takes queue pointer by reference, and team size & number. Shows fighter menu, Loops through team size creating fighters.
void createTeam(Queue *&team, int teamSize, int teamNumber);

//takes a queue pointer by reference, instantiates appropriate character objects and adds them to queue
void selectCharacter(Queue *&team);

//takes three queue pointers by reference, and two team score ints by reference. Runs the game until team is all dead, updates score.
void playGame(Queue *&team1, Queue *&team2, Queue *&loserPile, int &team1Score, int &team2Score);

//takes two character pointers by reference and two character names as strings, and performs one combat round and reports results
int combatRound(Character *&fighter1, Character *&fighter2, std::string fighter1Name, std::string fighter2Name);

//takes two character pointers by reference and two character names as strings, and performs an individual attack action
void attackDetails(Character *&char1, Character *&char2, std::string attackerName, std::string defenderName);

//returns true if fighter is dead, false if alive. Takes a character pointer by reference
bool checkDeath(Character *&fighter);

//takes two ints for team scores, prints win/lose/tie message to console based on scores
void showScore(int team1Score, int team2Score);

//prompts console whether to display loser pile, and displays if chosen
void showLosers(Queue * const losers);
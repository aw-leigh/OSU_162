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


//shows the main menu with fighter options
void showMainMenu();

//takes two character pointers by reference, instantiates appropriate character objects and assigns them to pointers
void selectCharacters(Character *&char1, Character *&char2);

//takes two character pointers by reference, runs the game until one character is dead
void beginGame(Character *&char1, Character *&char2);

//takes two character pointers by reference and two character names as strings, and performs one combat round and reports results
void combatRound(Character *&char1, Character *&char2, std::string char1Name, std::string char2Name);

//takes two character pointers by reference and two character names as strings, and performs an individual attack action
void attackDetails(Character *&char1, Character *&char2, std::string attackerName, std::string defenderName);

//returns true if char2 is dead, false if alive. Takes two character pointers by reference and two character names as strings
bool checkDeath(Character *&char1, Character *&char2, std::string char1Name, std::string char2Name);
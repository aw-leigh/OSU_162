/*********************************************************************
** Author: Andrew Wilson
** Date: Jan 12, 2019
** Description: Functions for menu display and interaction
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

int mainMenu();  //displays main menu, validates choice, and returns item number
void clearScreen();  //clears the screen
void systemPause();
void validateMainMenuChoice(int &menuChoice);  //ensures input is an integer

#endif
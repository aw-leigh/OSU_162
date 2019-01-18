/*********************************************************************
** Author: Andrew Wilson
** Date: Jan 12, 2019
** Description: Functions for menu display and interaction
*********************************************************************/

#include <iostream>
#include <cctype>
#include "menu.hpp"
#include "validation.hpp"

const int MAIN_MENU_LENGTH = 2;

int mainMenu()
{
	int mainMenuChoice;

	clearScreen();
	std::cout << "Select One of the Following Options:\n" << std::endl;
	std::cout << "	1: Start Langton's Ant simulation" << std::endl;
	std::cout << "	2: Quit" << std::endl << std:: endl;
	std::cout << "Please Enter 1 or " << MAIN_MENU_LENGTH << ": ";

	std::cin >> mainMenuChoice;
	validateMenuChoice(mainMenuChoice, MAIN_MENU_LENGTH);
	return mainMenuChoice;
}

void clearScreen()
{
	#ifdef _WIN32
		std::system("cls");
	#else
		std::cout << "\033[2J\033[1;1H";
	#endif
}

void systemPause()
{
	std::cin.clear();
	std::cin.ignore(1024, '\n');  // Discart old input
	std::cout << "Simulation finished!";
	std::cin.get();  // Proceed after new input from user
}
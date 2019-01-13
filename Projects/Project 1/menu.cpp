/*********************************************************************
** Author: Andrew Wilson
** Date: Jan 12, 2019
** Description: Functions for menu display and interaction
*********************************************************************/

#include <iostream>
#include "menu.hpp"

const int MAIN_MENU_LENGTH = 2;

int mainMenu()
{
	int mainMenuChoice;

	clearScreen();
	std::cout << "Select One of the Following Options:\n" << std::endl;
	std::cout << "	1: Start Langton's Ant simulation" << std::endl;
	std::cout << "	2: Quit" << std::endl;
	std::cout << "Please Enter 1 or " << MAIN_MENU_LENGTH << std::endl;

	std::cin >> mainMenuChoice;
	validateMainMenuChoice(mainMenuChoice);
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

void validateMainMenuChoice(int &menuChoice)  //assumes menu choices start at 1
{
	while (!std::cin || /*std::cin.get()!= '\n' ||*/ menuChoice < 1 || menuChoice > MAIN_MENU_LENGTH)
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << std::endl << "Please enter a number between 1 and " << MAIN_MENU_LENGTH << std::endl;
		std::cin >> menuChoice;
	}
}

void systemPause()
{
	std::cin.clear();
	std::cin.ignore(1024, '\n');  // Discart old input
	std::cout << "Simulation finished!";
	std::cin.get();  // Proceed after new input from user
}
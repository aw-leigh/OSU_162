/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 20, 2019
** Description: Implementation file for Game class
*********************************************************************/
#include <iostream>
#include <stdlib.h> //rand
#include <time.h>  //time

#include "game.hpp"
#include "validation.hpp"

const int MAIN_MENU_LENGTH = 2;

Game::Game()
{
    srand (time(NULL));  //initialize random seed
    player1made = false;  //sets flag for player memory allocation
    player2made = false;
    
    while(mainMenu() != 2);
}

int Game::mainMenu()
{
	int mainMenuChoice;

	clearScreen();
	std::cout << "Select One of the Following Options:\n" << std::endl;
	std::cout << "	1: Start Dice War game" << std::endl;
	std::cout << "	2: Quit" << std::endl << std:: endl;
	std::cout << "Please enter 1 or " << MAIN_MENU_LENGTH << ": ";
	std::cin >> mainMenuChoice;
	validateMenuChoice(mainMenuChoice, MAIN_MENU_LENGTH);

    if (mainMenuChoice == 1)  //if choice is 2, main menu function ends and the program finishes via main
    {
        gameSetup();
    }
    return mainMenuChoice;
}

void Game::gameSetup()
{
    const int MAX_DIE_SIDES = 100;
    const int MAX_ROUNDS = 10000;
    int numRounds, p1die, p2die, p1sides, p2sides = -1;  //initialized to junk value
    
    clearScreen();

    std::cout << "How many rounds? (1-" << MAX_ROUNDS << ")" << std::endl;
    std::cin >> numRounds;
    validateRangedInt(numRounds, 1, MAX_ROUNDS);
    std::cout << "Player 1 die: Loaded or unloaded?" << std::endl;
    std::cout << "1: Loaded      2: Unloaded" << std::endl;
    std::cin >> p1die;
    validateRangedInt(p1die, 1, 2);
    std::cout << "Player 2 die: Loaded or unloaded?" << std::endl;
    std::cout << "1: Loaded      2: Unloaded" << std::endl;
    std::cin >> p2die;
    validateRangedInt(p2die, 1, 2);
    std::cout << "How many sides on Player 1's die? (2-" << MAX_DIE_SIDES << ")" << std::endl;
    std::cin >> p1sides;
    validateRangedInt(p1sides, 2, MAX_DIE_SIDES);
    std::cout << "How many sides on Player 2's die? (2-" << MAX_DIE_SIDES << ")" << std::endl;
    std::cin >> p2sides;    
    validateRangedInt(p2sides, 2, MAX_DIE_SIDES);

    this->numRounds = numRounds;
    this->p1_score = 0;  //initializes scores to 0
    this->p2_score = 0;

    if(p1die == 1){
        player1 = new LoadedDie(p1sides);
        player1made = true;  //sets flag to delete allocated memory later
    }   
    else{
        player1 = new Die(p1sides);
        player1made = true;
    }

    if(p2die == 1){
        player2 = new LoadedDie(p2sides);
        player2made = true;
    }   
    else{
        player2 = new Die(p2sides);
        player2made = true;
    }
    clearScreen();
    playGame();

    if(player1made == true){  //deletes allocated memory
        delete player1;
        player1made = false;
    }
    if(player2made == true){
        delete player2;
        player2made = false;
    }
}
void Game::playGame()
{
    for(int currentRound = 0; currentRound < numRounds; currentRound++)  //loop for the number of rounds specified
    {
        int p1roll = player1->rollDie();
        int p2roll = player2->rollDie();
        
        std::cout << "Round " << currentRound + 1 << std::endl;

        std::cout << "Player 1 is using a " << player1->getSides() << "-sided ";  //report die status
        if(player1->getLoaded())
        {
            std::cout << "loaded die" << std::endl;
        }
        else
        {
            std::cout << "fair die" << std::endl;    
        }
        std::cout << "Player 2 is using a " << player2->getSides() << "-sided ";  //report die status
        if(player2->getLoaded())
        {
            std::cout << "loaded die" << std::endl;
        }
        else
        {
            std::cout << "fair die" << std::endl;    
        }
        
        std::cout << "Player 1 rolled: " << p1roll << std::endl;  //report roll result
        std::cout << "Player 2 rolled: " << p2roll << std::endl;  //report roll result
        
        if(p1roll > p2roll)
        {
            std::cout << "Player 1 wins the round!" << std::endl << std::endl;
            p1_score++;
        }
        else if(p1roll < p2roll)
        {
            std::cout << "Player 2 wins the round!" << std::endl << std::endl;
            p2_score++;            
        }
        else
        {
            std::cout << "This round is a tie!" << std::endl << std::endl;
        }

        std::cout << "The score is now " << p1_score << " : " << p2_score << std::endl << std::endl;
    }

    std::cout << "This final score is " << p1_score << " : " << p2_score << std::endl;
    
    if(p1_score > p2_score)
    {
        std::cout << "Player 1 wins!" << std::endl << std::endl;
    }
    else if (p1_score < p2_score)
    {
        std::cout << "Player 2 wins!" << std::endl << std::endl;
    }
    else
    {
        std::cout << "The game is a tie!" << std::endl << std::endl;
    }

    std::cout << "Press Enter to return to the main menu...";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cin.get();

}
void Game::clearScreen()
{
	#ifdef _WIN32
		std::system("cls");
	#else
		std::cout << "\033[2J\033[1;1H";
	#endif
}

Game::~Game()  //these checks were used in a previous iteration and should not be necessary now
{
    if(player1made = true)
    {
        delete player1;
    }
    if(player2made = true)
    {
        delete player2;
    }
}
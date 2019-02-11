/********************************************************************* 
** Author:      Andrew Wilson
** Date:        Jan 20, 2019
** Description: Main function for Fantasy Combat Game.

                This game presents the user with a choice of 5 
                fantasy characters to pit against each other.
                The user chooses two characters to fight, 
                and this program returns the results of each combat round.

*********************************************************************/
#include <stdlib.h> //rand
#include <time.h>  //time
#include "gameFunctions.hpp"
#include "validation.hpp"

int main()
{
    bool keepPlaying = true;
    srand (time(NULL));  //initialize random seed
    Character *char1 = nullptr;
    Character *char2 = nullptr;

    do{
    showMainMenu();
    selectCharacters(char1, char2);
    keepPlaying = playGame(char1, char2);
    }while(keepPlaying);

    return 0;
}
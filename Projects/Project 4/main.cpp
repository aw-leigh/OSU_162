#include <iostream>

#include "character.hpp"
#include "queue.hpp"
#include "validation.hpp"
#include "gameFunctions.hpp"

int main()
{
    bool keepPlaying = true;
    int team1Size = 0, team2Size = 0, team1Score = 0, team2Score = 0;

    srand (time(NULL));  //initialize random seed

    Queue * team1 = new Queue;
    Queue * team2 = new Queue;
    Queue * losers = new Queue;

    do{
        clearScreen();
        std::cout << "Welcome to Fantasy Combat!" << std::endl << std::endl;
        std::cout << "The winner of each round earns 2 points, and the loser loses 1 point" << std::endl << std::endl;
        team1Size = getTeamSize(1);
        team2Size = getTeamSize(2);    
        createTeam(team1, team1Size, 1);
        createTeam(team2, team2Size, 2);

        while(!team1->isEmpty() && !team2->isEmpty())
        {
            playGame(team1, team2, losers, team1Score, team2Score);
        }

        clearScreen();
        showScore(team1Score, team2Score);
        showLosers(losers);
        
        while(!team1->isEmpty())
        {
            team1->removeFrontandDelete();
        }
        while(!team2->isEmpty())
        {
            team2->removeFrontandDelete();
        }
        while(!losers->isEmpty())
        {
            losers->removeFrontandDelete();
        }

        std::cout << "Play again? (1 = Yes  2 = No): ";
        int choice = validateInt(1,2);
        if(choice == 2)
        {
            keepPlaying = false;
        }

    }while(keepPlaying);
    
    
    delete team1;
    delete team2;
    delete losers;

    return 0;
}
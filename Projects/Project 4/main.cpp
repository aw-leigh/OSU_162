#include <iostream>
//#include <>

#include "character.hpp"
#include "queue.hpp"
#include "validation.hpp"
#include "gameFunctions.hpp"

int main()
{
    bool keepPlaying = true;
    int team1Size = 0, team2Size = 0, team1Score = 0, team2Score = 0;

    Queue * team1 = new Queue;
    Queue * team2 = new Queue;
    Queue * losers = new Queue;

    srand (time(NULL));  //initialize random seed

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
    std::cout << "Final result: \n"<< "Team 1: "<< team1Score << "\nTeam 2: " << team2Score << std::endl;
    if(team1Score > team2Score)
    {
        std::cout << "Team 1 Wins!!\n\n";
    }
    else if(team2Score > team1Score)
    {
        std::cout << "Team 2 Wins!!\n\n";
    }
    else
    {
        std::cout << "We have a tie!!\n\n";
    }

    std::cout << "Display loser pile? (1 = Yes  2 = No): ";
    int choice = validateInt(1,2);
    if(choice = 1)
    {
        std::cout << "Losers" << std::endl;
        std::cout << "------" << std::endl;
        losers->printQueue();
    }
    

/*

After the results are displayed, the menu should provide 2 options for user to choose:

Play again
Exit
*/
    
    return 0;
}
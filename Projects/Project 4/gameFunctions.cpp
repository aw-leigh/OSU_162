/********************************************************************* 
** Author:      Andrew Wilson
** Date:        Jan 20, 2019
** Description: THe menu and game logic functions for Fantasy Combat Game.

                This game presents the user with a choice of 5 
                fantasy characters to pit against each other.
                The user chooses two characters to fight, 
                and this program returns the results of each combat round.

*********************************************************************/
#include "gameFunctions.hpp"
#include "validation.hpp"
#include "queue.hpp"

//shows the main menu
int getTeamSize(int teamNumber)
{
    std::cout << "How many fighters on Team " << teamNumber <<"? (1-10)" << std::endl;
    return validateInt(1, 10);
}

//shows the menu with fighter options
void showFighterMenu()
{
    std::cout << "Please choose from the below 5 fighters:" << std::endl << std::endl;
    std::cout << std::setw(20) << "Attack" << std::setw(10) << "Defense" << std::setw(8) << "Armor" << std::setw(14) << "Strength P." << std::setw(10) << "Special" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "1. Vampire: " << std::setw(6) << "1d12" << std::setw(8) << "1d6" << std::setw(8) << "1" << std::setw(9) << "18" << std::setw(17) << "Charm" << std::endl;
    std::cout << "2. Barbarian: " << std::setw(3) << "2d6" << std::setw(9) << "2d6" << std::setw(8) << "0" << std::setw(9) << "12" << std::setw(13) << "-" << std::endl;
    std::cout << "3. Blue Men: " << std::setw(5) << "2d10" << std::setw(8) << "3d6" << std::setw(8) << "3" << std::setw(9) << "12" << std::setw(15) << "Mob" << std::endl;
    std::cout << "4. Medusa: " << std::setw(6) << "2d6" << std::setw(9) << "1d6" << std::setw(8) << "3" << std::setw(8) << "8" << std::setw(18) << "Glare" << std::endl;
    std::cout << "5. H. Potter: " << std::setw(3) << "2d6" << std::setw(9) << "2d6" << std::setw(8) << "0" << std::setw(12) << "10/20" << std::setw(17) << "Hogwarts" << std::endl << std::endl;
}

//shows fighter menu, then loops through team size creating fighters
void createTeam(Queue *&team, int teamSize, int teamNumber)
{
    clearScreen();
    std::cout << "TEAM " << teamNumber << std::endl;    
    std::cout << "------" << std::endl;
    showFighterMenu();
    for(int i = 0; i < teamSize; i++)
    {
        std::cout << "Fighter " << i+1 << " of " << teamSize << " (Select 1-5): ";
        selectCharacter(team);
    }
}

//takes a queue by reference, instantiates appropriate character objects and adds them to queue
void selectCharacter(Queue *&team)
{
    Character * fighter = nullptr;
    int selection = validateInt(1, 5);
    std::cout << "Name: ";
    std::string name = getValidatedString();

    //make character object
    switch(selection)
    {
        case 1: { fighter = new Vampire(); break;}
        case 2: { fighter = new Barbarian(); break;}
        case 3: { fighter = new BlueMen(); break;}
        case 4: { fighter = new Medusa(); break;}
        case 5: { fighter = new HarryPotter(); break;}
    }
    team->addBack(fighter, name);
}

//takes two character pointers by reference, runs the game until one character is dead
void playGame(Queue *&team1, Queue *&team2, Queue *&loserPile, int &team1Score, int &team2Score)
{
    int round = 1;
    Character * dead = nullptr;
    Character * survivor = nullptr;
    Queue * winningTeam = nullptr;
    Queue * losingTeam = nullptr;
    std::string survivorName;
    std::string deadName;

    Character * fighter1 = team1->getFront()->fighter;  //fighter 1 is the first character in Team 1's lineup
    std::string fighter1Name = team1->getFront()->name;
    Character * fighter2 = team2->getFront()->fighter;  //fighter 2 is the first character in Team 2's lineup
    std::string fighter2Name = team2->getFront()->name;

    std::cout << "Team 1's " << fighter1Name << " vs. Team 2's " << fighter2Name << std::endl << std::endl; 
  
    while(!checkDeath(fighter1) && !checkDeath(fighter2))  //play until someone dies
    {
        clearScreen();
        std::cout << "Team 1's " << fighter1Name << " vs. Team 2's " << fighter2Name << std::endl << std::endl; 
        std::cout << "Round " << round << std::endl << std::endl; 
        ++round;
        combatRound(fighter1, fighter2, fighter1Name, fighter2Name);
        if(!checkDeath(fighter1) && !checkDeath(fighter2))
        {
            std::cout << "Press enter to continue to the next round!";
            std::cin.get();  // Proceed after new input from user   
        }
    }
    if(checkDeath(fighter1)) //fighter 1 is dead: clone fighter1 and add to dead pile. heal fighter 2
    {
        std::cout << fighter1Name << " is dead! " << fighter2Name << " heals " << fighter2->heal() <<" SP and moves to the back of the lineup!" << std::endl;
        dead = fighter1->clone();
        deadName = fighter1Name;
        winningTeam = team2;
        losingTeam = team1;
        survivor = fighter2->clone();
        survivorName = fighter2Name;
        team2Score += 2;
        team1Score -= 1;
    }
    else //fighter 2 is dead: clone fighter2 and add to dead pile. heal fighter 1
    {
        std::cout << fighter2Name << " is dead! " << fighter1Name << " heals " << fighter1->heal() <<" SP and moves to the back of the lineup!" << std::endl;
        dead = fighter2->clone();
        deadName = fighter2Name;
        winningTeam = team1;
        losingTeam = team2;
        survivor = fighter1->clone();
        survivorName = fighter1Name;
        team1Score += 2;
        team2Score -= 1;
    }
    //TODO: tell which next fighter is up
    std::cout << "Press enter to continue to the next round!";
    std::cin.get();   

    
    losingTeam->removeFront();  //move loser to loser pile: delete front node
    loserPile->addBack(dead, deadName);  //and add new node with cloned dead to loser pile

    winningTeam->removeFront();  
    winningTeam->addBack(survivor, survivorName);
}

//takes two character pointers by reference and two character names as strings, and performs one combat round and reports results. Returns 1 if fighter 1 dies, 2 if fighter 2 dies
int combatRound(Character *&fighter1, Character *&fighter2, std::string fighter1Name, std::string fighter2Name)
{
    attackDetails(fighter1, fighter2, fighter1Name, fighter2Name); //fighter 1 attacks
    if(!checkDeath(fighter2)) //if figher 2 isn't dead, fighter 2 attacks
    {
        attackDetails(fighter2, fighter1, fighter2Name, fighter1Name);
    }
}

//returns true if char2 is dead, false if alive. Takes two character pointers by reference
bool checkDeath(Character *&fighter)
{
    if(fighter->getSP() < 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//takes two character pointers by reference and two character names as strings, and performs an individual attack action
void attackDetails(Character *&attacker, Character *&defender, std::string attackerName, std::string defenderName)
{
    int damage = 0;

    int attackRoll = attacker->attack(); 
    if(attackRoll == 1337)  //Glare returns an attack roll of 1337
    {
        std::cout << attackerName << " uses Glare!! It's super effective!!" << std::endl;
    }
    else
    {
        std::cout << attackerName << " rolled " << attackRoll << " for its attack!" << std::endl;
    }

    std::cout << defenderName <<" has " << defender->getArmor() << " armor and "<< defender->getSP() << "SP!" << std::endl;
    
    int defenseRoll = defender->defend(attackRoll);
    if(defenseRoll == 1337) //Charm returns a defense roll of 1337
    {
        std::cout << defenderName << " used Charm! It's too charming to hit!" << std::endl;
    }
    else
    {
        std::cout << defenderName << " rolled " << defenseRoll << " for its defense!" << std::endl;
        std::cout << "Damage roll: " << attackRoll << " - (" << defenseRoll << " + " << defender->getArmor() << ") damage!" << std::endl;
        
        damage = attackRoll - (defenseRoll + defender->getArmor());
        if(damage < 0)
        {
            damage = 0;
        }
        std::cout << defenderName << " took " << damage << " damage!" << std::endl;
    }
    if(defender->getSP() == 20 && damage > 0) //20 SP only happens when Harry Potter revives
    {
        std::cout << defenderName << " was struck down, but revives with 20 SP!!" << std::endl;
    }
    std::cout << defenderName << " has " << defender->getSP() << " SP remaining!" << std::endl << std::endl;
}
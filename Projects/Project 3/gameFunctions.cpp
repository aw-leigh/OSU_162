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

//shows the main menu with fighter options
void showMainMenu()
{
    clearScreen();
    std::cout << "Welcome to Fantasy Combat!" << std::endl << std::endl;
    std::cout << "Please choose from the below 5 fighters:" << std::endl << std::endl;
    std::cout << std::setw(20) << "Attack" << std::setw(10) << "Defense" << std::setw(8) << "Armor" << std::setw(14) << "Strength P." << std::setw(10) << "Special" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "1. Vampire: " << std::setw(6) << "1d12" << std::setw(8) << "1d6" << std::setw(8) << "1" << std::setw(9) << "18" << std::setw(17) << "Charm" << std::endl;
    std::cout << "2. Barbarian: " << std::setw(3) << "2d6" << std::setw(9) << "2d6" << std::setw(8) << "0" << std::setw(9) << "12" << std::setw(13) << "-" << std::endl;
    std::cout << "3. Blue Men: " << std::setw(5) << "2d10" << std::setw(8) << "3d6" << std::setw(8) << "3" << std::setw(9) << "12" << std::setw(15) << "Mob" << std::endl;
    std::cout << "4. Medusa: " << std::setw(6) << "2d6" << std::setw(9) << "1d6" << std::setw(8) << "3" << std::setw(8) << "8" << std::setw(18) << "Glare" << std::endl;
    std::cout << "5. H. Potter: " << std::setw(3) << "2d6" << std::setw(9) << "2d6" << std::setw(8) << "0" << std::setw(12) << "10/20" << std::setw(17) << "Hogwarts" << std::endl << std::endl;
}

//takes two character pointers by reference, instantiates appropriate character objects and assigns them to pointers
void selectCharacters(Character *&char1, Character *&char2)
{
    int selection = 0;

    std::cout << "Fighter 1: ";
    selection = validateInt(1, 5);

    //make character object
    switch(selection)
    {
        case 1: { char1 = new Vampire(); break;}
        case 2: { char1 = new Barbarian(); break;}
        case 3: { char1 = new BlueMen(); break;}
        case 4: { char1 = new Medusa(); break;}
        case 5: { char1 = new HarryPotter(); break;}
    }

    std::cout << "Fighter 2: ";
    selection = validateInt(1, 5);   

    //make character object
    switch(selection)
    {
        case 1: { char2 = new Vampire(); break;}
        case 2: { char2 = new Barbarian(); break;}
        case 3: { char2 = new BlueMen(); break;}
        case 4: { char2 = new Medusa(); break;}
        case 5: { char2 = new HarryPotter(); break;}
    }
    std::cin.ignore(10000,'\n'); //clear the buffer because if affects the pause screen in the next function
    clearScreen();
}

//takes two character pointers by reference, runs the game until one character is dead
bool playGame(Character *&char1, Character *&char2)
{
    int round = 1;
    std::string char1Name;
    std::string char2Name;

    if(char1->name() == char2->name()) //if player chose 2 of the same character, append 1 and 2 to class names
    {
        char1Name = char1->name() + " 1";
        char2Name = char2->name() + " 2";
    }
    else  //otherwise, refer to fighters by class name
    {
        char1Name = char1->name();
        char2Name = char2->name();        
    }
    
    while(char1->getSP() > 0 && char2->getSP() > 0)  //play until someone dies
    {
        clearScreen();
        std::cout << "Round " << round << std::endl << std::endl;
        combatRound(char1, char2, char1Name, char2Name);
        ++round;
    }

    delete char1;  //delete characters when game ends
    delete char2;

    std::cout << "Play again? (Yes = 1   No = 2): ";  //prompt to play again
    int choice = validateInt(1, 2);
    if(choice == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//takes two character pointers by reference and two character names as strings, and performs one combat round and reports results
void combatRound(Character *&char1, Character *&char2, std::string char1Name, std::string char2Name)
{
    attackDetails(char1, char2, char1Name, char2Name); //fighter 1 attacks
    if(!checkDeath(char1, char2)) //if figher 2 isn't dead, fighter 2 attacks
    {
        attackDetails(char2, char1, char2Name, char1Name);
    }
    else  //if fighter 2 is dead, fighter 1 wins
    {
        std::cout << char2Name << " is dead! "<< char1Name << " wins!" << std::endl;
    }
    if(checkDeath(char2, char1)) //if fighter 1 is dead, fighter 2 wins
    {
        std::cout << char1Name << " is dead! " << char2Name << " wins!" << std::endl;
    }
    
    if(checkDeath(char2, char1) || checkDeath(char1, char2))
    {
        std::cout << "Thank you for playing!";
	    std::cin.get();  // Proceed after new input from user
    }
    else
    {
        std::cout << "Press enter to continue to the next round!";
	    std::cin.get();  // Proceed after new input from user
    }
}

//returns true if char2 is dead, false if alive. Takes two character pointers by reference
bool checkDeath(Character *&char1, Character *&char2)
{
    if(char2->getSP() < 1)
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
        std::cout << "Harry Potter was struck down, but revives with 20 SP!!" << std::endl;
    }
    std::cout << defenderName << " has " << defender->getSP() << " SP remaining!" << std::endl << std::endl;
}
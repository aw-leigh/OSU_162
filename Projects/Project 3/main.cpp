/********************************************************************* 
** Author:      Andrew Wilson
** Date:        Jan 20, 2019
** Description: Main function for Fantasy Combat Game.

                This game presents the user with a choice of 5 fantasy characters to pit against each other.
                The user chooses two characters to fight, and this program returns the results of each combat round.

*********************************************************************/
#include <stdlib.h> //rand
#include <time.h>  //time
#include <iostream>
#include <iomanip>  //setw
#include "character.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "validation.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::string;

void showMainMenu();

//takes two character pointers by reference, instantiates appropriate character objects and assigns them to pointers
void selectCharacters(Character *&char1, Character *&char2);

//takes two character pointers by reference, runs the game until one character is dead
void beginGame(Character *&char1, Character *&char2);

//performs one combat round
void combatRound(Character *&char1, Character *&char2, string char1Name, string char2Name);

void attackDetails(Character *&char1, Character *&char2, string attackerName, string defenderName);

int main()
{
    srand (time(NULL));  //initialize random seed
    Character *char1 = nullptr;
    Character *char2 = nullptr;

    showMainMenu();
    selectCharacters(char1, char2);
    beginGame(char1, char2);

    if(char1 != nullptr)
        delete char1;
    if(char2 != nullptr)
        delete char2;

    return 0;
}

void showMainMenu()
{
    clearScreen();
    cout << "Welcome to Fantasy Combat!" << endl << endl;
    cout << "Please choose from the below 5 fighters:" << endl << endl;
    cout << setw(20) << "Attack" << setw(10) << "Defense" << setw(8) << "Armor" << setw(14) << "Strength P." << setw(10) << "Special" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "1. Vampire: " << setw(6) << "1d12" << setw(8) << "1d6" << setw(8) << "1" << setw(9) << "18" << setw(17) << "Charm" << endl;
    cout << "2. Barbarian: " << setw(3) << "2d6" << setw(9) << "2d6" << setw(8) << "0" << setw(9) << "12" << setw(13) << "-" << endl;
    cout << "3. Blue Men: " << setw(5) << "2d10" << setw(8) << "3d6" << setw(8) << "3" << setw(9) << "12" << setw(15) << "Mob" << endl;
    cout << "4. Medusa: " << setw(6) << "2d6" << setw(9) << "1d6" << setw(8) << "3" << setw(8) << "8" << setw(18) << "Glare" << endl;
    cout << "5. H. Potter: " << setw(3) << "2d6" << setw(9) << "2d6" << setw(8) << "0" << setw(12) << "10/20" << setw(17) << "Hogwarts" << endl << endl;
}

void selectCharacters(Character *&char1, Character *&char2)
{
    int selection = 0;

    cout << "Fighter 1: ";
    selection = validateInt(1, 5);

    //make character object
    switch(selection)
    {
        case 1: { char1 = new Vampire(); break;}
        case 2: { char1 = new Barbarian(); break;}
    }

    cout << "Fighter 2: ";
    selection = validateInt(1, 5);   
    //make character object
    switch(selection)
    {
        case 1: { char2 = new Vampire(); break;}
        case 2: { char2 = new Barbarian(); break;}
    }
    std::cin.ignore(10000,'\n'); //clear the buffer because if affects the pause screen in the next function
    clearScreen();
}

void beginGame(Character *&char1, Character *&char2)
{
    int round = 1;
    string char1Name;
    string char2Name;

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
    

    while(char1->getSP() > 0 && char2->getSP() > 0)
    {
        clearScreen();
        cout << "Round " << round << endl << endl;
        combatRound(char1, char2, char1Name, char2Name);
        ++round;
    }
}

void combatRound(Character *&char1, Character *&char2, string char1Name, string char2Name)
{
    attackDetails(char1, char2, char1Name, char2Name);

    if(char2->getSP() > 0)
    {
        attackDetails(char2, char1, char2Name, char1Name);
    }
    else
    {
        cout << char2Name << " is dead! "<< char1Name << " wins!" << endl;
    }

    if(char1->getSP() < 1)
    {
        cout << char1Name << " is dead! " << char2Name << " wins!" << endl;
    }
    
	std::cout << "Press enter to continue...";
	std::cin.get();  // Proceed after new input from user
}

void attackDetails(Character *&attacker, Character *&defender, string attackerName, string defenderName)
{
    bool charm = false;
    bool glare = false;
    
    int attackRoll = attacker->attack(); 
    int defenseRoll = defender->defend();
    int damage = attackRoll - (defenseRoll + defender->getArmor());

    if(defenseRoll == 1337){  //vampire's Charm returns 1337
        charm = true;
    }
    if(attackRoll == 1337){  //vampire's Charm returns 1337
        glare = true;
    }

    if(damage < 1){  //if attack-defense is negative, attack = 0
        damage = 0;
    }

    if(!charm)
    {
        if(!glare)
        {   //no charm no glare
            cout << attackerName << " rolled " << attackRoll << " for its attack!" << endl;
            cout << defenderName << " rolled " << defenseRoll << " for its defense!" << endl;
            cout << defenderName <<" has " << defender->getArmor() << " armor and "<< defender->getSP() << "SP!" << endl;
            cout << "Damage roll: " << attackRoll << " - (" << defenseRoll << " + " << defender->getArmor() << ") damage!" << endl;
            cout << defenderName << " took " << damage << " damage!" << endl;

            defender->takeDamage(damage);
            cout << defenderName << " has " << defender->getSP() << " SP remaining!" << endl << endl;
        }
        else //glare, no charm
        {
            
        }
    }
    else  //charm
    {
    cout << defenderName << " is too charming! " << attackerName << " couldn't attack!" << endl << endl;        
    }
}
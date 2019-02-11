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

void showMainMenu();

//takes two character pointers by reference, instantiates appropriate character objects and assigns them to pointers
void selectCharacters(Character *&char1, Character *&char2);

//takes two character pointers by reference, runs the game until one character is dead
void beginGame(Character *&char1, Character *&char2);

//performs one combat round
void combatRound(Character *&char1, Character *&char2);

void C1_attack(Character *&char1, Character *&char2);
void C2_attack(Character *&char1, Character *&char2);

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
        case 1: { char1 = new Vampire(); }
        case 2: { char1 = new Barbarian(); }
    }

    cout << "Fighter 2: ";
    selection = validateInt(1, 5);   
    //make character object
    switch(selection)
    {
        case 1: { char2 = new Vampire(); }
        case 2: { char2 = new Barbarian(); }
    }
    clearScreen();
}

void beginGame(Character *&char1, Character *&char2)
{
    int round = 1;
    while(char1->getSP() > 0 && char2->getSP() > 0)
    {
        clearScreen();
        cout << "Round " << round << endl << endl;
        cout << "Fighter 1: " << char1->name() << endl;
        cout << "Fighter 2: " << char2->name() << endl << endl;
        combatRound(char1, char2);
        ++round;
    }
}

void combatRound(Character *&char1, Character *&char2)
{
    C1_attack(char1, char2);

    if(char2->getSP() > 0)
    {
        C2_attack(char1, char2);
    }
    else
    {
        cout << "Fighter 2 is dead! Fighter 1 wins!" << endl;
    }

    if(char1->getSP() < 1)
    {
        cout << "Fighter 1 is dead! Fighter 2 wins!" << endl;
    }
    
	std::cout << "Press enter to continue...";
	std::cin.get();  // Proceed after new input from user
}

void C1_attack(Character *&char1, Character *&char2)
{
    bool charm = false;
    bool glare = false;
    
    int C1_attackRoll = char1->attack(); 
    int C2_defenseRoll = char2->defend();
    int damage = C1_attackRoll - (C2_defenseRoll + char2->getArmor());

    if(C2_defenseRoll == 1337){  //vampire's Charm returns 1337
        charm = true;
    }
    if(C1_attackRoll == 1337){  //vampire's Charm returns 1337
        glare = true;
    }

    if(damage < 1){  //if attack-defense is negative, attack = 0
        damage = 0;
    }

    if(!charm)
    {
        if(!glare)
        {   //no charm no glare
            cout << "Fighter 1 rolled " << C1_attackRoll << " for its attack!" << endl;
            cout << "Fighter 2 rolled " << C2_defenseRoll << " for its defense!" << endl;
            cout << "Fighter 2 has " << char2->getArmor() << " armor and "<< char2->getSP() << "SP!" << endl;
            cout << "Damage roll: " << C1_attackRoll << " - (" << C2_defenseRoll << " + " << char2->getArmor() << ") damage!" << endl;
            cout << "Fighter 2 took " << damage << " damage!" << endl;

            char2->takeDamage(damage);
            cout << "Fighter 2 has " << char2->getSP() << " SP remaining!" << endl << endl;
        }
        //glare, no charm
    }
    //charm
    cout << "Fighter 2 is too charming! Fighter 1 couldn't attack!" << endl;
}

void C2_attack(Character *&char1, Character *&char2)
{
    int C2_attackRoll = char2->attack();
    int C1_defenseRoll = char1->defend();


    int damage = C2_attackRoll - (C1_defenseRoll + char1->getArmor());
    if(damage < 1){
        damage = 0;
    }

    cout << "Fighter 2 rolled " << C2_attackRoll << " for its attack!" << endl;
    cout << "Fighter 1 rolled " << C1_defenseRoll << " for its defense!" << endl;
    cout << "Fighter 1 has " << char1->getArmor() << " armor and "<< char1->getSP() << "SP!" << endl;
    cout << "Damage roll: " << C2_attackRoll << " - (" << C1_defenseRoll << " + " << char1->getArmor() << ") damage!" << endl;
    cout << "Fighter 1 took " << damage << " damage!" << endl;

    char1->takeDamage(damage);
    cout << "Fighter 1 has " << char1->getSP() << " SP remaining!" << endl << endl;
}


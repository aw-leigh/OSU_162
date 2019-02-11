/***************************************************************
** Program name: Character.cpp
** Author:       Andrew Wilson
** Date:         February 11, 2019
** Description:  This is the Character class implementation file.
**               Barbarian, Vampire, Blue Men, Medusa, and Harry Potter inherit from Character.
** Methods:      
**               Constructor, deconstructor
**               int getArmor()
**               int getSP()
**
** Pure virtual functions:
**               int attack()
**               int defend()
***************************************************************/

#include "Character.hpp"

//Character constructor. Unused
Character::Character()
{
    this->strengthPoints = 1337;  //junk values
    this->armor = 1337;
}

//Character destructor. Unused
Character::~Character() {}

//Returns armor value
int Character::getArmor()
{
    return armor;
}

//Returns SP value
int Character::getSP()
{
    return strengthPoints;
}

//Takes an int. Subtracts that int from SP
void Character::takeDamage(int damage)
{
    this->strengthPoints -= damage;
}
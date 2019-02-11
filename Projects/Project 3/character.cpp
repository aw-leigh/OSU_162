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

#include "character.hpp"

//Character constructor. Unused
Character::Character()
{
    this->strengthPoints = 1337;  //junk values
    this->armor = 1337;
    this->canRevive = false;
}

//Character destructor. Unused
Character::~Character() {}

int Character::getArmor()
{
    return this->armor;
}

int Character::getSP()
{
    return this->strengthPoints;
}

bool Character::getCanRevive()
{
    return this->canRevive;
}

void Character::setCanRevive(bool revive)
{
    this->canRevive = revive;
}

void Character::setSP(int SP)
{
    this->strengthPoints = SP;
}
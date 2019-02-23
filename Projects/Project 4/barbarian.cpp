/***************************************************************
** Program name: Barbarian.cpp
** Author:       Andrew Wilson
** Date:         February 11, 2019
** Description:  This is the Barbarian class implementation file.
**               Inherits from Character.
** Methods:      
**               Constructor, deconstructor
**               int attack()
**               int defend()
***************************************************************/

#include "character.hpp"
#include "barbarian.hpp"

//Default constructor
Barbarian::Barbarian(): Character()
{
    this->strengthPoints = 12;
    this->maxSP = 12;
    this->armor = 0;
}

//clones current Barbarian object
Barbarian* Barbarian::clone() const
{
    return new Barbarian(*this);
}

//Destructor.
Barbarian::~Barbarian() {}

//Returns attack roll
int Barbarian::attack()
{
    return (((rand() % 6) + 1) + ((rand() % 6) + 1));  //2d6
}

//Takes attack roll, calculates & returns damage taken. Applies damage to SP.
int Barbarian::defend(int attack)
{
    int defenseRoll = (((rand() % 6) + 1) + ((rand() % 6) + 1));
    int damage = attack - (defenseRoll + this->armor);  //2d6 defense + armor - attack
    if(damage > 0)
    {
        this->strengthPoints -= damage;
    }
    return defenseRoll;
}

//Returns string "Barbarian"
std::string Barbarian::name() const
{
    return "Barbarian";
}


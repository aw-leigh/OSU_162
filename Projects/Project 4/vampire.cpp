/***************************************************************
** Program name: Vampire.cpp
** Author:       Andrew Wilson
** Date:         February 11, 2019
** Description:  This is the Vampire class implementation file.
**               Inherits from Character.
** Methods:      
**               Constructor, deconstructor
**               int attack()
**               int defend()
***************************************************************/

#include "character.hpp"
#include "vampire.hpp"

//Default constructor
Vampire::Vampire(): Character()
{
    this->strengthPoints = 18;
    this->maxSP = 18;
    this->armor = 1;
}

//clones current Vampire object
Vampire* Vampire::clone() const
{
    return new Vampire(*this);
}

//Destructor.
Vampire::~Vampire() {}

//Returns attack roll
int Vampire::attack()
{
    return ((rand() % 12) + 1);  //1d12
}

//DefReturns defense roll. 50% to proc Charm
int Vampire::defend(int attack)
{
    int defenseRoll, damage = 0;

    if(rand() % 2) //50% of the time
    {

        defenseRoll = 1337;
    }
    else
    {
        defenseRoll = ((rand() % 6) + 1);
        damage = attack - (defenseRoll + this->armor);  //1d6 defense + armor - attack
    }

    if(damage > 0)
    {
        this->strengthPoints -= damage;
    }
    return defenseRoll;
}

//Returns string "Vampire"
std::string Vampire::name() const
{
    return "Vampire";
}
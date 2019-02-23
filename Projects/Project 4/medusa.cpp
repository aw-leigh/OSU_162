/***************************************************************
** Program name: Medusa.cpp
** Author:       Andrew Wilson
** Date:         February 11, 2019
** Description:  This is the Medusa class implementation file.
**               Inherits from Character.
** Methods:      
**               Constructor, deconstructor
**               int attack()
**               int defend()
***************************************************************/

#include "character.hpp"
#include "medusa.hpp"

//Default constructor
Medusa::Medusa(): Character()
{
    this->strengthPoints = 8;
    this->maxSP = 8;
    this->armor = 3;
}

//clones current Medusa object
Medusa* Medusa::clone() const
{
    return new Medusa(*this);
}

//Destructor.
Medusa::~Medusa() {}

//Returns attack roll. A 12 procs Glare.
int Medusa::attack()
{
    int attack = (((rand() % 6) + 1) + ((rand() % 6) + 1));
    if(attack == 12)
    {
        return 1337;
    }
    else
    {
        return attack;
    }
}

//Returns defense roll
int Medusa::defend(int attack)
{
    int defenseRoll = (rand() % 6) + 1;  //1d6
    int damage = attack - (defenseRoll + this->armor);  //1d6 defense + armor - attack
    if(damage > 0)
    {
        this->strengthPoints -= damage;
    }
    return defenseRoll;
}

//Returns string "Medusa"
std::string Medusa::name() const
{
    return "Medusa";
}
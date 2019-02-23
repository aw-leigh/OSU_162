/***************************************************************
** Program name: Barbarian.cpp
** Author:       Andrew Wilson
** Date:         February 11, 2019
** Description:  This is the BlueMen class implementation file.
**               Inherits from Character.
** Methods:      
**               Constructor, deconstructor
**               int attack()
**               int defend()
***************************************************************/

#include "character.hpp"
#include "bluemen.hpp"

//Default constructor
BlueMen::BlueMen(): Character()
{
    this->strengthPoints = 12;
    this->maxSP = 12;
    this->armor = 3;
}

//clones current BlueMen object
BlueMen* BlueMen::clone() const
{
    return new BlueMen(*this);
}

//Destructor.
BlueMen::~BlueMen() {}

//Returns attack roll
int BlueMen::attack()
{
    return (((rand() % 10) + 1) + ((rand() % 10) + 1));  //2d10
}

//Returns defense roll
int BlueMen::defend(int attack)
{
    int defenseRoll = 0;
    int damage = 0;
    
    if(this->strengthPoints <= 4)
    {
        defenseRoll = ((rand() % 6) + 1);
        damage = attack - (defenseRoll + this->armor);
    }
    else if(this->strengthPoints <= 8)
    {
        defenseRoll += ((rand() % 6) + 1);
        defenseRoll += ((rand() % 6) + 1);
        damage = attack - (defenseRoll + this->armor);
    }
    else
    {
        defenseRoll += ((rand() % 6) + 1);
        defenseRoll += ((rand() % 6) + 1);
        defenseRoll += ((rand() % 6) + 1);
        damage = attack - (defenseRoll + this->armor);
    }
    if(damage > 0)
    {
        this->strengthPoints -= damage;
    }
    return defenseRoll; 
}
//Returns string "BlueMen"
std::string BlueMen::name() const
{
    return "Blue Men";
}

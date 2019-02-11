/***************************************************************
** Program name: HarryPotter.cpp
** Author:       Andrew Wilson
** Date:         February 11, 2019
** Description:  This is the HarryPotter class implementation file.
**               Inherits from Character.
** Methods:      
**               Constructor, deconstructor
**               int attack()
**               int defend()
***************************************************************/

#include "character.hpp"
#include "harrypotter.hpp"

//Default constructor
HarryPotter::HarryPotter(): Character()
{
    this->strengthPoints = 10;
    this->armor = 0;
    this->canRevive = true;
}

//Destructor.
HarryPotter::~HarryPotter() {}

//Returns attack roll
int HarryPotter::attack()
{
    return (((rand() % 6) + 1) + ((rand() % 6) + 1));  //2d6
}

//Returns defense roll
int HarryPotter::defend(int attack)
{
    int defenseRoll = (((rand() % 6) + 1) + ((rand() % 6) + 1));  //2d6
    int damage = attack - (defenseRoll + this->armor);  //1d6 defense + armor - attack
    if(damage > 0)
    {
        this->strengthPoints -= damage;
        if(this->strengthPoints < 1 && this->canRevive == true)
        {
            this->canRevive = false;
            this->strengthPoints = 20;
        }
    }
    return defenseRoll;
}

//Returns string "HarryPotter"
std::string HarryPotter::name() const
{
    return "Harry Potter";
}
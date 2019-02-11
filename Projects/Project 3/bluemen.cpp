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
    this->armor = 3;
}

//Destructor.
BlueMen::~BlueMen() {}

//Returns attack roll
int BlueMen::attack()
{
    return (((rand() % 10) + 1) + ((rand() % 10) + 1));  //2d10
}

//Returns defense roll
int BlueMen::defend()
{
    int defense = 0;
    
    if(this->strengthPoints <= 4)
    {
        defense = ((rand() % 6) + 1);
    }
    else if(this->strengthPoints <= 8)
    {
        defense += ((rand() % 6) + 1);
        defense += ((rand() % 6) + 1);
    }
    else
    {
        defense += ((rand() % 6) + 1);
        defense += ((rand() % 6) + 1);
        defense += ((rand() % 6) + 1);
    }
    return defense; 
}
//Returns string "BlueMen"
std::string BlueMen::name() const
{
    return "Blue Men";
}
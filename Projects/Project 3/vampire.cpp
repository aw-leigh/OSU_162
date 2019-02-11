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
    this->armor = 1;
}

//Destructor.
Vampire::~Vampire() {}

//Returns attack roll
int Vampire::attack()
{
    return ((rand() % 12) + 1);  //1d12
}

//DefReturns defense roll. 50% to proc Charm
int Vampire::defend()
{
    if(rand() % 2) //50% of the time
    {
        return 1337;
    }
    else
    {
        return ((rand() % 6) + 1);  //1d6
    }
}

//Returns string "Vampire"
std::string Vampire::name() const
{
    return "Vampire";
}
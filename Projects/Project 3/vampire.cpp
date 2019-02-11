/***************************************************************
** Program name: Vampire.cpp
** Author:       Andrew Wilson
** Date:         February 11, 2019
** Description:  This is the Barbarian class implementation file.
**               Inherits from Character.
** Methods:      
**               Constructor, deconstructor
**               int attack()
**               int defend()
***************************************************************/

#include "Character.hpp"
#include "Vampire.hpp"

//Default constructor
Vampire::Vampire(): Character()
{
    this->strengthPoints = 18;
    this->armor = 1;
}

//Destructor.
Vampire::~Vampire() {}

//Returns armor value
int Vampire::attack()
{
    return ((rand() % 12) + 1);  //1d12
}

//Returns SP value
int Vampire::defend()
{
    if(rand() % 2) //50% of the time
    {
        return 1337;
    }
    else
    {
        return (((rand() % 6) + 1) + ((rand() % 6) + 1));  //2d6
    }
}

//Returns string "Vampire"
std::string Vampire::name() const
{
    return "Vampire";
}
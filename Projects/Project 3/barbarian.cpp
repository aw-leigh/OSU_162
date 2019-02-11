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

#include "Character.hpp"
#include "Barbarian.hpp"

//Default constructor
Barbarian::Barbarian(): Character()
{
    this->strengthPoints = 12;
    this->armor = 0;
}

//Destructor.
Barbarian::~Barbarian() {}

//Returns armor value
int Barbarian::attack()
{
    return (((rand() % 6) + 1) + ((rand() % 6) + 1));  //2d6
}

//Returns SP value
int Barbarian::defend()
{
    return (((rand() % 6) + 1) + ((rand() % 6) + 1));  //2d6
}

//Returns string "Barbarian"
std::string Barbarian::name() const
{
    return "Barbarian";
}
/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 20, 2019
** Description: Implementation file for Die class
*********************************************************************/
#include <stdlib.h> //rand
#include <time.h>  //time

#include "die.hpp"

Die::Die()  //unused default constructor
{
    this->numSides = 1337;
}
Die::Die(int numSides)  //Die constructor
{
    this->numSides = numSides;
    this->isLoaded = false;
}
int Die::getSides()
{
    return this->numSides;
}
bool Die::getLoaded()
{
    return this->isLoaded;
}
LoadedDie::LoadedDie(int numSides) : Die(numSides)  //Loaded die constructor
{
    this->numSides = numSides;
    this->isLoaded = true;
}
int Die::rollDie()
{
    return ((rand() % numSides) + 1);  //returns a random number between 1 and numSides
}
int LoadedDie::rollDie()  //returns a random number between 2 and numSides. All rolls of 1 become numSides.
{
    int roll = ((rand() % numSides) + 1);
    if (roll == 1)
    {
        roll = numSides;
    }
    return roll;
}
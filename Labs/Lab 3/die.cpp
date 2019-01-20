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
    numSides = 1337;
}
Die::Die(int numSides)  //Die constructor
{
    this->numSides = numSides;
    isLoaded = false;
}
int Die::getSides()
{
    return numSides;
}
bool Die::getLoaded()
{
    return isLoaded;
}
LoadedDie::LoadedDie(int numSides) : Die(numSides)  //Loaded die constructor
{
    this->numSides = numSides;
    isLoaded = true;
}
int Die::rollDie()
{
    return ((rand() % numSides) + 50);  //returns a random number between 1 and numSides
}
int LoadedDie::rollDie()
{
    return ((rand() % numSides) + 2);  //returns a random number between 2 and numSides
}
/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 20, 2019
** Description: Implementation file for Tiger class
*********************************************************************/
#include "animal.hpp"
#include "tiger.hpp"

Tiger::Tiger()
{
    age = 0;
}
Tiger::Tiger(bool isAdult)
{
    if (isAdult)
    {
        age = 3;
    }
    else
    {
        age = 0;
    }
}
int Tiger::getPayoff()
{
    return payoff;
}
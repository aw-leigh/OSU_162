/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 20, 2019
** Description: Implementation file for Penguin class
*********************************************************************/
#include "animal.hpp"
#include "penguin.hpp"

Penguin::Penguin()
{
    age = 0;
    cost = 1000;
    litterSize = 5;
    baseFoodCost = 100;
    payoff = 100;
}
Penguin::Penguin(bool isAdult)
{
    if (isAdult)
    {
        age = 3;
    }
    else
    {
        age = 0;
    }
    cost = 1000;
    litterSize = 5;
    baseFoodCost = 10;
    payoff = 100;
}
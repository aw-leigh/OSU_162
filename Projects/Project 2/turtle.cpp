/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 20, 2019
** Description: Implementation file for Turtle class
*********************************************************************/
#include "animal.hpp"
#include "turtle.hpp"

Turtle::Turtle()
{
    age = 0;
    cost = 100;
    litterSize = 10;
    baseFoodCost = 50;
    payoff = 5;
}
Turtle::Turtle(bool isAdult)
{
    if (isAdult)
    {
        age = 3;
    }
    else
    {
        age = 0;
    }
    cost = 100;
    litterSize = 10;
    baseFoodCost = 5;
    payoff = 5;
}
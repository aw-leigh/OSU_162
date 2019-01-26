/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 20, 2019
** Description: Implementation file for Tiger class
*********************************************************************/
#include "animal.hpp"
#include "tiger.hpp"

Tiger::Tiger()  //one problem I see is that I'm creating a new copy of this data for each tiger, even though it's constant except for age
{
    age = 0;
    cost = 10000;
    litterSize = 1;
    baseFoodCost = 50;
    payoff = 2000;
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
    cost = 10000;
    litterSize = 1;
    baseFoodCost = 50;
    payoff = 2000;
}
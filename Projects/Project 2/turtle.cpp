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
}
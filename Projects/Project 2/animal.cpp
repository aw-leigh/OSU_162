/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 20, 2019
** Description: Implementation file for Animal class
*********************************************************************/
#include "animal.hpp"
#include "zoo.hpp"

Animal::Animal()
{
    int age = 0;  //stores animal's age in days
    int cost = -666;  //junk value, to be overridden by each animal
    int litterSize = -666;  //junk value, to be overridden by each animal
    int baseFoodCost = -666;  //junk value, to be overridden by each animal
    int payoff = -666;  //junk value, to be overridden by each animal
}
int Animal::getAge()  //returns animal age
{
    return age;
}  
void Animal::incrementAge()  //adds 1 to animal age
{
    ++age;
}
int Animal::getCost()  //returns cost
{
    return cost;
}
int Animal::getLitterSize()  //returns litter size
{
    return litterSize;
}
int Animal::getBaseFoodCost()
{
    return baseFoodCost;
}
int Animal::getPayoff() //returns payoff
{
    return payoff;
}
/*********************************************************************
** Author:      Andrew Wilson
** Date:        Feb 1, 2019
** Description: Implementation file for Building class.
*********************************************************************/
#include <iostream>
#include "building.hpp"

Building::Building() {};  //unused default constructor
Building::Building(std::string name, std::string address, int size)  //constructor
{
    this->name = name;
    this->address = address;
    this->size = size;
}
std::string Building::getName()
{
    return this->name;
}
std::string Building::getAddress()
{
    return this->address;
}
int Building::getSize()
{
    return this->size;
}
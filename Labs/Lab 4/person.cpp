/*********************************************************************
** Author:      Andrew Wilson
** Date:        Feb 1, 2019
** Description: Implementation file for Person class.
*********************************************************************/
#include <iostream>
#include "person.hpp"

Person::~Person() {};
Person::Person() {};
Person::Person(std::string name, int age)
{
    this->name = name;
    this->age = age;
}
int Person::getAge()
{
    return this->age;
}
std::string Person::getName()
{
    return this->name;
}
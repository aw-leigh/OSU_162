/*********************************************************************
** Author:      Andrew Wilson
** Date:        Feb 1, 2019
** Description: Implementation file for University class.
*********************************************************************/
#include <iostream>
#include "university.hpp"

University::University()
{
    this->name = "Oregon State University";
}
void University::addBuilding(Building* buildingIn)  //prints the information on all buildings
{
    buildingArray.push_back(buildingIn);
}
void University::addPerson(Person* personIN)  //prints the information on all people
{
    personArray.push_back(personIN);
}
void University::printBuildings()  //prints the information on all buildings
{
    for(int i = 0; i < buildingArray.size(); i++)
    {
        std::cout << buildingArray[i]->getName() << " is " << buildingArray[i]->getSize() << " sqft. "<< std::endl;
        std::cout << "Its address is " << buildingArray[i]->getAddress() << std::endl;
    }
}
void University::printPeople()  //prints the information on all people
{
    for(int i = 0; i < personArray.size(); i++)
    {
        std::cout << personArray[i]->getName() << " is " << personArray[i]->getAge() << " years old. ";
        personArray[i]->showScore();
        std::cout << std::endl;
        personArray[i]->doWork();
        std::cout << std::endl << std::endl;
    }
}
void University::printUniversityName()  //prints the information on all people
{
    std::cout << this->name << std::endl;
}
University::~University()
{
    for(int i; i < buildingArray.size(); i++)
    {
        delete buildingArray[i];
    }
    buildingArray.clear();

    for(int i; i < personArray.size(); i++)
    {
        delete personArray[i];
    }
    personArray.clear();
};
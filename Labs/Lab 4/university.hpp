/*********************************************************************
** Author:      Andrew Wilson
** Date:        Feb 1, 2019
** Description: Header file for University class.
*********************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <string>
#include <vector> //vectors
#include "person.hpp"
#include "building.hpp"

class University
{   private:
        std::string name;  //stores the university name
        std::vector<Building *> buildingArray;  //stores buildings
        std::vector<Person *> personArray;  //stores people
    public:
        void printBuildings();  //prints the information on all buildings
        void printPeople();  //prints the information on all people
        void addBuilding(Building* buildingIn);  //appends building to array
        void addPerson(Person* personIN);  //appends person to array
        void printUniversityName(); //for testing 
        University();  //default constructor
        ~University();  //destructor
};

#endif //University
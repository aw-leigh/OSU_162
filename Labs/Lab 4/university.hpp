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
        void addBuilding(Building* buildingIn);  //appends building to array
        void addPerson(Person* personIN);  //appends person to array
        void printBuildings();  //prints the information on all buildings
        void printPeopleFull();  //prints all the information on all people
        void printPeopleNames();  //prints all the peoples' names
        int getNumPeople();  //returns size of people array
        void makePersonWork(int num); //makes a person work
        void printUniversityName(); //for testing 
        void saveToFile();  //saves newly added people
        void loadFile();  //loads people
        University();  //default constructor
        ~University();  //destructor
};

#endif //University
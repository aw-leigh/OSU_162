/*********************************************************************
** Author:      Andrew Wilson
** Date:        Feb 1, 2019
** Description: Main file for Lab 4
*********************************************************************/
#include <iostream>
#include <vector>
#include <stdlib.h> //rand
#include <time.h>  //time
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include "university.hpp"
#include "building.hpp"


int main()
{
    srand (time(NULL));  //initialize random seed
    University OSU;  //instantiate university

    //create students, instructors, and buildings
    Student* student1 = new Student("Andrew", 28, 4.0);
    Student* student2 = new Student("Jesse", 23, 3.5);
    Building* building1 = new Building("The Valley Library", "201 SW Waldo Pl", 333920);
    Building* building2 = new Building("Gill Coliseum", "660 SW 26th St", 257106);
    Instructor* inst1 = new Instructor("Carl Sagan", 54, 4.9);
    Instructor* inst2 = new Instructor("Neil deGrasse Tyson", 60, 1.5);    
    
    OSU.addPerson(student1);
    OSU.addPerson(student2);
    OSU.addPerson(inst1);
    OSU.addPerson(inst2);    
    OSU.printPeople();
    OSU.addBuilding(building1);
    OSU.addBuilding(building2);
    OSU.printBuildings();
    return 0;
}





/*

When the program starts, you need to manually instantiate at least 
1 student, 
1 instructor, and 
2 buildings inside the University object. 

It can be done by either hard coding that information, 
or have the user input all the information at the start of the program.

The menu must have at least the following options:

1. Prints information about all the buildings
2. Prints information of everybody at the university
3. Choose a person to do work
4. Exit the program

If option 3 is selected, the program should print another menu that 
prints all the people’s name and let the user input the choice of the person the user would like to do work.

*/

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
#include "validation.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int mainMenu(University &OSU);
int workMenu(University &OSU);
int saveLoadMenu(University &OSU);

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
    
    //adds students, instructors, and buildings to the appropriate arrays
    OSU.addPerson(student1);
    OSU.addPerson(student2);
    OSU.addPerson(inst1);
    OSU.addPerson(inst2);    
    OSU.addBuilding(building1);
    OSU.addBuilding(building2);
    mainMenu(OSU);
    return 0;
}

int mainMenu(University &OSU)
{
    int choice = 0;
    while(choice != 5)
    {
        clearScreen();
        cout << "Welcome to the OSU Information System" << endl << endl;
        cout << "Please choose from the following options:" << endl;
        cout << "1. Print information about all buildings" << endl;
        cout << "2. Print information about all students and faculty" << endl;
        cout << "3. Choose a person to do work" << endl;
        cout << "4. Add a person/Save/Load" << endl;
        cout << "5. Exit the program" << endl << endl;
        cout << "Choice: ";
        cin >> choice;
        validateInt(choice, 1, 5);

        if(choice == 1)
        {
            clearScreen();
            OSU.printBuildings();
            systemPause();        
        }
        else if(choice == 2)
        {
            clearScreen();
            OSU.printPeopleFull();
            systemPause();              
        }
        else if(choice == 3)
        {
            clearScreen();
            workMenu(OSU);
        }
        else if(choice == 4)
        {
            clearScreen();
            saveLoadMenu(OSU);
        }
        else
        {
            cout << "Goodbye!";
        }
    }
}

int workMenu(University &OSU)
{
    int choice = 0;
    
    cout << "Who will you put to work?" << endl;
    OSU.printPeopleNames();
    cout << endl << "Choice: ";
    cin >> choice;
    validateInt(choice, 1, OSU.getNumPeople());  //ensures choice is between 1 and <max number of people>
    cout << endl;

    OSU.makePersonWork(choice);
    cout << endl;

    systemPause();
}

int saveLoadMenu(University &OSU)
{
    int choice = 0;

    clearScreen();
    cout << "What would you like to do?" << endl;
    cout << "1. Add a person" << endl;
    cout << "2. Save people added this session" << endl;
    cout << "3. Load people from a previous session" << endl;
    cout << "4. Return to main menu" << endl << endl;
    cout << "Choice: ";
    cin >> choice;
    validateInt(choice, 1, 4);

    if(choice == 1)
    {
        int age, personChoice;
        string name;
        double rating;

        cout << "Instructor or Student? (1 = Instructor  2 = Student): ";
        cin >> personChoice;
        validateInt(choice, 1, 2);

        cout << "Please enter a name: ";
        std::cin.clear();
	    std::cin.ignore(1024, '\n');  // Discart old input
        getline(cin, name);

        cout << "Please enter an age: ";
        cin >> age;
        validateInt(age);

        if(personChoice == 1)
        {
            cout << "Please enter a rating: ";
            cin >> rating;
            validateDouble(rating, 0.0, 5.0);
        }
        else
        {
            cout << "Please enter a GPA: ";
            cin >> rating;
            validateDouble(rating, 0.0, 4.0);            
        }

        if(personChoice == 1)
        {
            Instructor* inst = new Instructor(name, age, rating);
            OSU.addPerson(inst);
        }
        else
        {
            Student* student = new Student(name, age, rating);
            OSU.addPerson(student);
        }
        
        cout << "Person successfully added! Returning to main menu." << endl;
        systemPause();
    }
    else if(choice == 2)
    {
        if(OSU.getNumPeople() == 4)
        {
            cout << "No one has been added yet!" << endl;
            systemPause();
        }
        else
        {
            OSU.saveToFile();
            cout << endl;
            systemPause();
        }
        
    }
    else if (choice == 3)
    {
        OSU.loadFile();
        cout << endl;
        systemPause();
    }
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

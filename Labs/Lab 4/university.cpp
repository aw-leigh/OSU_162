/*********************************************************************
** Author:      Andrew Wilson
** Date:        Feb 1, 2019
** Description: Implementation file for University class.
*********************************************************************/
#include <iostream>
#include <fstream>
#include "university.hpp"
#include "appendCSV.hpp"
#include "student.hpp"
#include "instructor.hpp"

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
        std::cout << "Its address is " << buildingArray[i]->getAddress() << std::endl << std::endl;
    }
}
void University::printPeopleFull()  //prints the information on all people
{
    for(int i = 0; i < personArray.size(); i++)
    {
        std::cout << personArray[i]->getName() << " is " << personArray[i]->getAge() << " years old. " << std::endl;
        personArray[i]->showScore();
        std::cout << std::endl << std::endl;
    }
}
void University::printPeopleNames()  //prints the information on all people
{
    for(int i = 0; i < personArray.size(); i++)
    {
        std::cout << i+1 << ". " << personArray[i]->getName() << std::endl;
    }
}
int University::getNumPeople()  //returns the size of the people array
{
    return personArray.size();
}
void University::makePersonWork(int num) //makes a person work
{
    personArray[num-1]->doWork();
}
void University::printUniversityName()  //prints the information on all people
{
    std::cout << this->name << std::endl;
}
void University::saveToFile()  //saves newly added people to CSV
{
    std::ofstream outputFile;
    std::string outputFileName;

    std::cout << "Please enter name of file to output (.csv): ";
    std::cin >> outputFileName;
    appendCSV(outputFileName);  //searches a string for ".", and if not found appends ".csv". See appendCSV.cpp

    outputFile.open(outputFileName);

    for(int i = 4; i < personArray.size(); i++)  //starts at 4 because there are 4 people initially hardcoded
    {
        outputFile  << personArray[i]->getName() << ',' 
                    << personArray[i]->getAge() << ',' 
                    << personArray[i]->getScore() << ','
                    << personArray[i]->isStudent();

        if(i < personArray.size() - 1)  //this adds a newline after every person except for the last one, which prevents creating empty lines
        {
            outputFile << '\n';
        }
    }
    outputFile.close();
    std::cout << std::endl <<  "Saved to " << outputFileName << "!";
}
void University::loadFile()  //loads people from CSV
{
    std::ifstream inputFile;
    std::string inputFileName;
    std::string name, ageTemp, ratingTemp, isStudentTemp;
    int age;
    double rating;
    bool isStudent;

    std::cout << "Please enter name of file to open (.csv): ";
    std::cin >> inputFileName;
    appendCSV(inputFileName);  //searches a string for ".", and if not found appends ".csv". See appendCSV.cpp

    inputFile.open(inputFileName);
    if (!inputFile)  //Displays an error and exits program if the file isn't openable.
    {
        std::cout << "Could not access file, check filename and try again" << std::endl;
    }
    else
    {
        while(inputFile.good()) //read through to the end of the file
        {
            getline(inputFile, name, ',');  //name = name from file
            getline(inputFile, ageTemp, ',');  //reads age as a string
            age = stoi(ageTemp);  //converts string to int
            getline(inputFile, ratingTemp, ',');  //reads rating as a string
            rating = stod(ratingTemp);  //converts string to double
            getline(inputFile, isStudentTemp, '\n');  //reads isStudent as a string
            isStudent = stoi(isStudentTemp);  //converts string to int (which is also a bool)

            if(isStudent)
            {
                Student* student = new Student(name, age, rating);
                personArray.push_back(student);
            }
            else
            {
                Instructor* inst = new Instructor(name, age, rating);
                personArray.push_back(inst);
            }
        }
        std::cout << std::endl <<  "Loaded from " << inputFileName << "!";
    }
    inputFile.close();

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
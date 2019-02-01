/*********************************************************************
** Author:      Andrew Wilson
** Date:        Feb 1, 2019
** Description: Implementation file for Student class.
*********************************************************************/
#include <iostream>
#include "student.hpp"


Student::Student(std::string name, int age, double GPA)  //constructor
{
    this->name = name;
    this->age = age;
    this->GPA = GPA;
}  
void Student::doWork()  //generates a random number between 1-50 and outputs work message
{
    std::cout << this->name << " did " << ((rand() % 50) + 1) << " hours of homework.";
}
void Student::showScore()
{
    std::cout << "This student's GPA is " << std::fixed << std::showpoint << std::setprecision(1) << this->GPA;
}
int Student::getScore()
{
    return this->GPA;
}
bool Student::isStudent()
{
    return true;
}
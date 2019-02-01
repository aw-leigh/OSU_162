/*********************************************************************
** Author:      Andrew Wilson
** Date:        Feb 1, 2019
** Description: Implementation file for Instructor class.
*********************************************************************/
#include <iostream>
#include "instructor.hpp"


Instructor::Instructor(std::string name, int age, double rating)  //constructor
{
    this->name = name;
    this->age = age;
    this->rating = rating;
}  
void Instructor::doWork()  //generates a random number between 1-50 and outputs work message
{
    std::cout << this->name << " graded papers for " << ((rand() % 50) + 1) << " hours.";
}
void Instructor::showScore()
{
    std::cout << "This instructor's rating is " << std::fixed << std::showpoint << std::setprecision(1) << this->rating;
}
int Instructor::getScore()
{
    return this->rating;
}
bool Instructor::isStudent()
{
    return false;
}
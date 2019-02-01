/*********************************************************************
** Author:      Andrew Wilson
** Date:        Feb 1, 2019
** Description: Header file for Student class.
*********************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "person.hpp"

class Student : public Person
{   protected:
        double GPA;  //stores GPA (between 0.0-4.0)
    public:
        virtual void doWork();  //generates a random number and outputs work message
        virtual void showScore();  //outputs rating message
        Student(); //unused default constructor
        Student(std::string name, int age, double GPA);  //constructor
};

#endif //Student
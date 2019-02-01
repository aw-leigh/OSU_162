/*********************************************************************
** Author:      Andrew Wilson
** Date:        Feb 1, 2019
** Description: Header file for Person class.
*********************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <stdlib.h> //rand
#include <iomanip> //setprecision

class Person
{   protected:
        std::string name;  //stores the university name
        int age;  //stores age
    public:
        virtual void doWork() = 0;  //generates a random number and outputs work message
        virtual void showScore() = 0;  //outputs rating message
        virtual int getScore() = 0;  //returns rating/GPA
        virtual bool isStudent() = 0; //returns true for student, false for not student. Used for save/load.
        virtual std::string getName();
        virtual int getAge();
        virtual ~Person();
        Person();  //unused default constructor
        Person(std::string name, int age);  //constructor
};

#endif //Person
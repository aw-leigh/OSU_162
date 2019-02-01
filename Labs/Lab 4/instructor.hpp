/*********************************************************************
** Author:      Andrew Wilson
** Date:        Feb 1, 2019
** Description: Header file for Instructor class.
*********************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "person.hpp"

class Instructor : public Person
{   protected:
        double rating;  //stores rating (between 0.0-5.0)
    public:
        virtual void doWork();  //generates a random number and outputs work message
        virtual void showScore();  //outputs rating message
        Instructor(); //unused default constructor
        Instructor(std::string name, int age, double rating);  //constructor
        int getRating();  //returns rating
};

#endif //Instructor
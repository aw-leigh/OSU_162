/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 25, 2019
** Description: Header file for Turtle class
*********************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

class Animal;

class Turtle : public Animal
{
    private:
    public:
        Turtle();  //default constructor. Makes a baby by default.
        Turtle(bool isAdult);  //constructor that takes a bool, and makes adults (true) or babies (false)
};

#endif //Turtle
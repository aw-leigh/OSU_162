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
        static const int cost = 100;  //stores animal purchase price
        static const int litterSize = 10;  //stores animal litter size
        static const int baseFoodCost = 5;  //stores base food cost
        static const int payoff = 5;  //stores per-day profit from animal
    public:
        Turtle();  //default constructor. Makes a baby by default.
        Turtle(bool isAdult);  //constructor that takes a bool, and makes adults (true) or babies (false)
};

#endif //Turtle
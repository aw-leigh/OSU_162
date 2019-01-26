/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 25, 2019
** Description: Header file for Penguin class
*********************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

class Animal;

class Penguin : public Animal
{
    private:
        static const int cost = 1000;  //stores animal purchase price
        static const int litterSize = 5;  //stores animal litter size
        static const int baseFoodCost = 10;  //stores base food cost
        static const int payoff = 100;  //stores per-day profit from animal
    public:
        Penguin();  //default constructor. Makes a baby by default.
        Penguin(bool isAdult);  //constructor that takes a bool, and makes adults (true) or babies (false)
};

#endif //Penguin
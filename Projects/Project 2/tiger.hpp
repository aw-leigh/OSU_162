/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 25, 2019
** Description: Header file for Tiger class
*********************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

class Animal;

class Tiger : public Animal
{
    private:
        static const int cost = 10000;  //stores animal purchase price
        static const int litterSize = 1;  //stores animal litter size
        static const int baseFoodCost = 50;  //stores base food cost
        static const int payoff = 2000;  //stores per-day profit from animal
    public:
        Tiger();  //default constructor. Makes a baby by default.
        Tiger(bool isAdult);  //constructor that takes a bool, and makes adults (true) or babies (false)
        int getPayoff();
};

#endif //Tiger
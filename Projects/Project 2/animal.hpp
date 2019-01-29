/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 20, 2019
** Description: Header file for Animal class
*********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{   protected:  
        int age;  //stores animal's age in days
        int cost;  //junk value, to be overridden by each animal
        int litterSize;  //junk value, to be overridden by each animal
        int baseFoodCost;  //junk value, to be overridden by each animal
        int payoff;  //junk value, to be overridden by each animal
    public:
        Animal();  //default constructor
        virtual int getAge();  //returns animal age
        virtual int getCost();  //returns cost
        virtual int getLitterSize();  //returns litter size
        virtual int getBaseFoodCost();  //returns base food cost
        virtual int getPayoff(); //returns payoff
        void incrementAge();  //adds 1 to animal age
};

#endif //Animal


/*
Age
    Adult if age >= 3 days
    Baby if age < 3 days

Cost
    Tiger cost $10,000
    Penguin cost $1,000
    Turtle cost $100

Number of Babies
    Tigers have 1 baby
    Penguins have 5 babies
    Turtles have 10 babies

Base Food Cost
    You can get this base food cost from the user or set it as a constant. Example base food cost per animal per day: $10.
    Tigers have a feeding cost of 5 times the base cost
    Penguins have a feeding cost that is the same as the base cost
    Turtles have a feeding cost that is 50% the base cost

Payoff
    A tiger’s payoff per day is 20% of their cost per animal. (not counting bonus)
    A penguin’s payoff per day is 10% of their cost per animal
    A turtle’s payoff per day is 5% of their cost per animal
*/
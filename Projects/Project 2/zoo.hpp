/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 25, 2019
** Description: Header file for Zoo class
*********************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"

class Zoo
{   private:
        int playerCash;  //stores player's money
        int baseFoodCost;  //will store user entered base food cost; not implemented yet
        int dayCounter;  //tracks game duration
        Tiger** tigerArray;  //pointer to array of tigers
        int tigerArraySize;  //tracks size of tiger array
        int tigerCount;  //tracks number of tigers in zoo
        Penguin** penguinArray;  //pointer to array of penguins
        int penguinArraySize;  //tracks size of penguin array
        int penguinCount;  //tracks number of penguins in zoo
        Turtle** turtleArray;  //pointer to turtle array
        int turtleArrazySize;  //tracks size of turtle array
        int tutrleCount;  //tracks number of turtles in zoo
    public:
        Zoo();  //default constructor, not used
        Zoo(int startingCash, int numTigers, int numPenguins, int numTurtles);  //constructor to be used to set up game
        ~Zoo();  //destructor that deallocates memory
        void advanceDay();  //ages animals, calculates profit, 
        void randomEvent();  //causes a random event, used in advanceDay()
        void growArray(Animal * arrayIn, int arraySize); //doubles array length, per specifications
        int getPlayerCash();  //returns player's money total
        int getBaseFoodCost();  //returns base food cost. Not yet implemented
        bool hasAdults(Animal * arrayIn, int arraySize);  //searches animal arrays for adults, returns true if there are adults
};

#endif //Zoo




/*
 the zoo class should have a dynamic array for each type of animal. 
    Each dynamic array should have a capacity of 10 animals to start with. 
    If more animals are added, you should resize the dynamic array by 
    doubling the starting capacity to hold more animals.
*/
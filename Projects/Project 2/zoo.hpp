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
        int turtleArraySize;  //tracks size of turtle array
        int turtleCount;  //tracks number of turtles in zoo
    public:
        Zoo();  //default constructor, not used
        Zoo(int startingCash, int numTigers, int numPenguins, int numTurtles);  //constructor to be used to set up game
        ~Zoo();  //destructor that deallocates memory
        void advanceDay();  //ages animals, calculates profit, 
        void randomEvent(int & eventBonus);  //causes a random event, used in advanceDay()
        //there must be a way to do these 3 in one function but I can't figure it out
        void growArray(Tiger** &oldArray, int &arraySize); //doubles array length, per specifications
        void growArray(Penguin** &oldArray, int &arraySize); //doubles array length, per specifications
        void growArray(Turtle** &oldArray, int &arraySize); //doubles array length, per specifications
        void purchaseAnimal();  //shows purchase animal menu at the end of the day
        int getPlayerCash();  //returns player's money total
        int getBaseFoodCost();  //returns base food cost. Not yet implemented
        //takes 3 pointers to arrays and 3 array lengths, returns calcualtes fed cost. Order is tiger, penguin, turtle
        int calcFeedCost(Tiger** array1, int tigerCount, Penguin** array2, int penguinCount, Turtle** array3, int turtleCount);
        //takes 3 pointers to arrays and 3 array lengths, returns calcualtes animal revenue. Order is tiger, penguin, turtle
        int calcDailyRevenue(Tiger** array1, int tigerCount, Penguin** array2, int penguinCount, Turtle** array3, int turtleCount);  
        bool hasAdults(Animal * arrayIn, int arraySize);  //searches animal arrays for adults, returns true if there are adults
};

#endif //Zoo




/*
 the zoo class should have a dynamic array for each type of animal. 
    Each dynamic array should have a capacity of 10 animals to start with. 
    If more animals are added, you should resize the dynamic array by 
    doubling the starting capacity to hold more animals.
*/
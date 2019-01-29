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
        int baseFoodCost;  //stores base food cost
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
        void growArray(Tiger** &oldArray, int &arraySize); //doubles array length, per specifications
        void growArray(Penguin** &oldArray, int &arraySize); //doubles array length, per specifications
        void growArray(Turtle** &oldArray, int &arraySize); //doubles array length, per specifications
        void purchaseAnimalMenu();  //shows purchase animal menu at the end of the day
        void payForAnimals(int numTigers, int numPenguins, int numTurtles);  //takes 3 ints for the number of animals to be purchased, and deducts price from player cash
        void animalBirth();  //gives birth to animals
        int getPlayerCash();  //returns player's money total
        int getBaseFoodCost();  //returns base food cost.
        //takes 3 pointers to arrays and 3 array lengths, returns calcualtes fed cost. Order is tiger, penguin, turtle
        int calcFeedCost(Tiger** array1, int tigerCount, Penguin** array2, int penguinCount, Turtle** array3, int turtleCount);
        //takes 3 pointers to arrays and 3 array lengths, returns calcualtes animal revenue. Order is tiger, penguin, turtle
        int calcDailyRevenue(Tiger** array1, int tigerCount, Penguin** array2, int penguinCount, Turtle** array3, int turtleCount);  
        void animalDies();  //kills random animal
        bool hasAdults(Tiger** arrayIn, int arraySize);  //searches tiger arrays for adults, returns true if there is at least 1 adult
        bool hasAdults(Penguin** arrayIn, int arraySize);  //searches penguin arrays for adults, returns true if there is at least 1 adult
        bool hasAdults(Turtle** arrayIn, int arraySize);  //searches turtle arrays for adults, returns true if there is at least 1 adult
};

#endif //Zoo
/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 25, 2019
** Description: Implementation file for Zoo class
*********************************************************************/
#include <iostream>
#include "zoo.hpp"
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"

Zoo::Zoo()  //default constructor, not used
{
    ;  //this should not ever actually be used
}
Zoo::Zoo(int startingCash, int numTigers, int numPenguins, int numTurtles)  //constructor to be used to set up game
{
    playerCash = startingCash;  //sets starting money
    baseFoodCost = 5;  //sets base food cost; not currently implemented
    dayCounter = 0;  //initializes the game at day 0
    tigerArraySize = 10;  //initializes all animal arrays at size 10
    penguinArraySize = 10;
    turtleArrazySize = 10;

    tigerCount = numTigers;  //sets initial animal count
    penguinCount = numPenguins;
    tutrleCount = numTurtles;

    tigerArray = new Tiger*[10];  //creates an array of pointers to tiger objects
    penguinArray = new Penguin*[10];
    turtleArray = new Turtle*[10];

    for(int i = 0; i < 10; i++) //ensures the arrays are initially pointing at null
    {
        tigerArray[i] = nullptr;
        penguinArray[i] = nullptr;
        turtleArray[i] = nullptr;
    }

    for(int j = 0; j < numTigers; j++)
    {
        Tiger* tiger = new Tiger();  //create tiger object
        tigerArray[j] = tiger;  //set the address of this object into the array
    }
    for(int k = 0; k < numPenguins; k++)
    {
        Penguin* penguin = new Penguin();  //create penguin object
        penguinArray[k] = penguin;  //set the address of this object into the array
    }
    for(int n = 0; n < numTurtles; n++)
    {
        Turtle* turtle = new Turtle();  //create turtle object
        turtleArray[n] = turtle;  //set the address of this object into the array
    }
    
}
Zoo::~Zoo()  //destructor that deallocates memory
{
    //there is definitely a memory leak here, need to delete like in lab 1
    delete [] tigerArray;
    delete [] penguinArray;
    delete [] turtleArray;
}
void Zoo::advanceDay()  //ages animals, calculates profit, 
{

}
void Zoo::randomEvent()  //causes a random event, used in advanceDay()
{

}
void Zoo::growArray(Animal * arrayIn, int arraySize) //doubles array length, per specifications
{
    ;
}
int Zoo::getPlayerCash()  //returns player's money total
{
    return playerCash;
}
int Zoo::getBaseFoodCost()  //returns base food cost. Not yet implemented
{
    return baseFoodCost;
}
bool Zoo::hasAdults(Animal * arrayIn, int arraySize)  //searches animal arrays for adults, returns true if there are adults
{
    ;
}

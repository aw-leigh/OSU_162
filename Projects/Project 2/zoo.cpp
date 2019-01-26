/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 25, 2019
** Description: Implementation file for Zoo class
*********************************************************************/
#include <iostream>
#include <iomanip> //setw
#include "zoo.hpp"
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "validation.hpp"

Zoo::Zoo()  //default constructor, not used
{
    ;  //this should not ever actually be used
}
Zoo::Zoo(int startingCash, int numTigersStart, int numPenguinsStart, int numTurtlesStart)  //constructor to be used to set up game
{
    playerCash = startingCash;  //sets starting money
    baseFoodCost = 5;  //sets base food cost; not currently implemented
    dayCounter = 0;  //initializes the game at day 0

    tigerArraySize = 10;  //initializes all animal arrays at size 10, per specs
    penguinArraySize = 10;
    turtleArraySize = 10;

    tigerCount = numTigersStart;  //sets initial animal count
    penguinCount = numPenguinsStart;
    turtleCount = numTurtlesStart;

    tigerArray = new Tiger*[10];  //creates an array of pointers to tiger objects
    penguinArray = new Penguin*[10];
    turtleArray = new Turtle*[10];

    for(int i = 0; i < 10; i++){ //ensures the arrays are initially pointing at null
        tigerArray[i] = nullptr;
        penguinArray[i] = nullptr;
        turtleArray[i] = nullptr;
    }

    for(int j = 0; j < numTigersStart; j++){
        Tiger* tiger = new Tiger();  //create tiger object
        tigerArray[j] = tiger;  //set the address of this object into the array
    }
    for(int k = 0; k < numPenguinsStart; k++){
        Penguin* penguin = new Penguin();  //create penguin object
        penguinArray[k] = penguin;  //set the address of this object into the array
    }
    for(int n = 0; n < numTurtlesStart; n++){
        Turtle* turtle = new Turtle();  //create turtle object
        turtleArray[n] = turtle;  //set the address of this object into the array
    }
    
    while(playerCash > 0){ //player cash cannot be initialized to 0, so while loop works here
        advanceDay();
    }
}

void Zoo::advanceDay()  //ages animals, calculates profit, 
{
    int todaysRevenue, todaysFeedCost = 0;
    
    clearScreen();
    dayCounter++;

    //for testing
    std::cout << "Day " << dayCounter  << std::endl;
    std::cout << "Starting cash: $" << playerCash  << std::endl;
    std::cout << "Starting animal count:" << std::endl;
    std::cout << std::setw(22) << "Tigers" << std::setw(12) << "Penguins" << std::setw(12) << "Turtles" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Number: " << std::setw(14) << tigerCount << std::setw(12) << penguinCount << std::setw(12) << turtleCount << std::endl << std::endl;

    //increase all animals' age by 1
    for(int i = 0; i < tigerCount; i++){    
        tigerArray[i]->incrementAge();
    }
    for(int k = 0; k < penguinCount; k++){
        penguinArray[k]->incrementAge();
    }
    for(int n = 0; n < turtleCount; n++){
        turtleArray[n]->incrementAge();
    }

    //calculate feeding cost for each animal
    todaysFeedCost = calcFeedCost(tigerArray, tigerCount, penguinArray, penguinCount, turtleArray, turtleCount);
    std::cout << "Today's feed cost is: $" << todaysFeedCost << std::endl;

    //random event
    std::cout << "Random event happens here"  << std::endl;

    //calculate revenue
    todaysRevenue = calcDailyRevenue(tigerArray, tigerCount, penguinArray, penguinCount, turtleArray, turtleCount);

    std::cout << "Today's revenue is: $" << todaysRevenue << std::endl;

    //update player cash
    std::cout << "Today's profit is: $" << (todaysRevenue - todaysFeedCost) << std::endl << std::endl;
    playerCash += (todaysRevenue - todaysFeedCost);
    std::cout << "You have $" << playerCash << " left in the bank." << std::endl << std::endl;


    //ask player to buy adult animal
    purchaseAnimal();

    
    //check if money is 0, if so game over
    //prompt to keep playing or end the game
        //if yes, do nothing (loop)
        //if quit, display goodbye message and money = 0 (because of loop in main)
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cin.get();
}
void Zoo::randomEvent()  //causes a random event, used in advanceDay()
{

}
void Zoo::growArray(Tiger** &oldArray, int &arraySize) //doubles array length, per specifications
{
    Tiger** newArray = new Tiger*[arraySize*2];  //creates an array twice the length of the original

    for(int i = 0; i < arraySize; i++){
        newArray[i] = oldArray[i];  //copies an element into the first half of the new array
    }
    delete []oldArray;    //frees memory from original array
    oldArray = newArray;  //makes oldArray point to the newArray data
    arraySize *= 2;
}
void Zoo::growArray(Penguin** &oldArray, int &arraySize) //doubles array length, per specifications
{
    Penguin** newArray = new Penguin*[arraySize*2];  //creates an array twice the length of the original

    for(int i = 0; i < arraySize; i++){
        newArray[i] = oldArray[i];  //copies an element into the first half of the new array
    }
    delete []oldArray;    //frees memory from original array
    oldArray = newArray;  //makes oldArray point to the newArray data
    arraySize *= 2;
}
void Zoo::growArray(Turtle** &oldArray, int &arraySize) //doubles array length, per specifications
{
    Turtle** newArray = new Turtle*[arraySize*2];  //creates an array twice the length of the original

    for(int i = 0; i < arraySize; i++){
        newArray[i] = oldArray[i];  //copies an element into the first half of the new array
    }
    delete []oldArray;    //frees memory from original array
    oldArray = newArray;  //makes oldArray point to the newArray data
    arraySize *= 2;
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
int Zoo::calcFeedCost(Tiger** array1, int array1size, Penguin** array2, int array2size, Turtle** array3, int array3size)
{
    int feedCost = 0;
    if(array1size > 0){  //check if there are tigers, because if there aren't then we're deferencing nullptr
        feedCost += (array1[0]->getBaseFoodCost()*tigerCount);
    }
    if(array2size > 0){
        feedCost += (array2[0]->getBaseFoodCost()*penguinCount);
    }
    if(array3size > 0){
        feedCost += (array3[0]->getBaseFoodCost()*turtleCount);
    }
    return feedCost;
}
int Zoo::calcDailyRevenue(Tiger** array1, int array1size, Penguin** array2, int array2size, Turtle** array3, int array3size)
{
    int revenue = 0;
    if(array1size > 0){  //check if there are tigers, because if there aren't then we're deferencing nullptr
        revenue += (array1[0]->getPayoff()*tigerCount);
    }
    if(array2size > 0){
        revenue += (array2[0]->getPayoff()*penguinCount);
    }
    if(array3size > 0){
        revenue += (array3[0]->getPayoff()*turtleCount);
    }
    return revenue;
}
void Zoo::purchaseAnimal()
{
    int purchaseChoice = 0;
    std::cout << std::setw(22) << "Tiger" << std::setw(12) << "Penguin" << std::setw(12) << "Turtle" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Cost: " << std::setw(16) << "$10,000" << std::setw(12) << "$1,000" << std::setw(12) << "$100" << std::endl << std::endl;

    std::cout << "Would you like to buy an adult animal? (1 = Yes  2 = No): ";
    std::cin >> purchaseChoice;
    validateRangedInt(purchaseChoice, 1, 2);

    if(purchaseChoice == 1)
    {
        purchaseChoice = 0;
        std::cout << "Which animal will you buy? (1 = Tiger  2 = Penguin  3 = Turtle): ";
        std::cin >> purchaseChoice;
        validateRangedInt(purchaseChoice, 1, 3);

        if(purchaseChoice == 1)
        {
            if(tigerCount >= tigerArraySize)
            {
                growArray(tigerArray, tigerArraySize);
            }
            Tiger* tiger = new Tiger(true);  //create tiger object. True flag makes an adult.
            tigerArray[tigerCount] = tiger;  //new tiger gets added to the array. Array is 0 indexed, so new tiger goes to tigerCount
                                             //e.g. there are currenty two tigers in indices 0 and 1, so new one goes at index 2 
            tigerCount++;
            std::cout << "You have purchased a tiger!" << std::endl;
        }
        else if(purchaseChoice == 2)
        {
            if(penguinCount >= penguinArraySize)
            {
                growArray(penguinArray, penguinArraySize);
            }
            Penguin* penguin = new Penguin(true);  //create penguin object. True flag makes an adult.
            penguinArray[penguinCount] = penguin;  //new penguin gets added to the array. Array is 0 indexed, so new penguin goes to penguinCount
                                             //e.g. there are currenty two penguins in indices 0 and 1, so new one goes at index 2 
            penguinCount++;
            std::cout << "You have purchased a penguin!" << std::endl;
        }
        else
        {
            if(turtleCount >= turtleArraySize)
            {
                growArray(turtleArray, turtleArraySize);
            }
            Turtle* turtle = new Turtle(true);  //create turtle object. True flag makes an adult.
            turtleArray[turtleCount] = turtle;  //new turtle gets added to the array. Array is 0 indexed, so new turtle goes to turtleCount
                                                //e.g. there are currenty two turtles in indices 0 and 1, so new one goes at index 2
            turtleCount++;      
            std::cout << "You have purchased a turtle!" << std::endl;      
        }
        
    }
    else
    {
        std::cout << "No animals purchased today." << std::endl;
    }
}
Zoo::~Zoo()  //destructor that deallocates memory
{
    for (int i = 0; i < tigerCount; i++){ //deletes each individual animal, then the array
        delete [] tigerArray[i];
    }
    delete [] tigerArray;

    for (int i = 0; i < penguinCount; i++){
        delete [] penguinArray[i];
    }
    delete [] penguinArray;

    for (int i = 0; i < turtleCount; i++){
        delete [] turtleArray[i];
    }
    delete [] turtleArray;

}
/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 25, 2019
** Description: Implementation file for Zoo class
*********************************************************************/
#include <iostream>
#include <iomanip> //setw
#include <stdlib.h> //rand
#include <time.h>  //time
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
    srand (time(NULL));  //initialize random seed
    
    playerCash = startingCash;  //sets starting money
    payForAnimals(numTigersStart, numPenguinsStart, numTurtlesStart);  //subtracts the cost of starting animals
    baseFoodCost = 40;  //sets base food cost
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
    int todaysRevenue, todaysFeedCost, eventBonus, keepPlaying = 0;
    
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
    std::cout << "Today's feed cost is: $" << todaysFeedCost << std::endl << std::endl;

    //random event
    randomEvent(eventBonus);

    //calculate revenue
    todaysRevenue = eventBonus + calcDailyRevenue(tigerArray, tigerCount, penguinArray, penguinCount, turtleArray, turtleCount);
    //std::cout << "Today's revenue is: $" << todaysRevenue << std::endl;

    //update player cash
    std::cout << std::endl << "Today's profit is: $" << (todaysRevenue - todaysFeedCost) << std::endl << std::endl;
    playerCash += (todaysRevenue - todaysFeedCost);
    std::cout << "You have $" << playerCash << " left in the bank." << std::endl << std::endl;

    std::cout << "Current animal count:" << std::endl;
    std::cout << std::setw(22) << "Tigers" << std::setw(12) << "Penguins" << std::setw(12) << "Turtles" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Number: " << std::setw(14) << tigerCount << std::setw(12) << penguinCount << std::setw(12) << turtleCount << std::endl << std::endl;

    //ask player to buy adult animal
    purchaseAnimalMenu();
    
    //check if money is 0, if so game over
    if(playerCash <= 0){
        clearScreen();
        std::cout << "You're bankrupt! Game Over!" << std::endl << std::endl;
    }
    else{
        std::cout << "Keep playing? (1 = Yes  2 = No): ";
        std::cin >> keepPlaying;
        validateRangedInt(keepPlaying, 1, 2);
        if(keepPlaying == 2)
        {
            playerCash = 0;
            clearScreen();
        }
        else
        {
            std::cout << "Press Enter to advance a day...";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cin.get();
        }
    }
}
void Zoo::randomEvent(int & eventBonus)  //causes a random event
{
    int randomNumber = (rand() % 10) + 1;  //random number from 1-10

    if(randomNumber <= 4)  //40% chance of nothing
    {
        std::cout << "Nothing special happened today." << std::endl;
    }
    else if(randomNumber == 5 || randomNumber == 6 || randomNumber == 8)  //30% chance of death
    {
        animalDies();
    }
    else if(randomNumber == 7)  //10% chance of bonus money
    {
        int bonus = ((rand() % 251) + 250);  //random number from 250-500
        std::cout << "Today was particularly busy! You got an extra $" << bonus << " for each of your tigers!" << std::endl;
        eventBonus = (bonus * tigerCount);
    }
    else //20% chance of birth
    {
        animalBirth();
    }
    
}
void Zoo::animalDies()
{
    bool isKilled = false;
    int animalType = 0;

    if(tigerCount + penguinCount + turtleCount != 0)
    {
        while(!isKilled)
        {
            animalType = (rand() % 3) + 1;  //random number from 1-3, used to determine which animal dies

            if(animalType == 1 && tigerCount > 0)  //if random number is 1 and there are tigers, kill a tiger
            {
                tigerCount--;                     //array is 0 indexed, so if there were 10 tigers initially, 
                delete tigerArray[tigerCount];    //we decrement the count to delete the last one (the one at index 9)
                tigerArray[tigerCount] = nullptr;
                isKilled = true;
                std::cout << "One of your tigers has died :(" << std::endl;
            }
            else if(animalType == 2 && penguinCount > 0)  //if random number is 2 and there are penguins, kill a penguin
            {
                penguinCount--;                     //array is 0 indexed, so if there were 10 penguins initially, 
                delete penguinArray[penguinCount];    //we decrement the count to delete the last one (the one at index 9)
                penguinArray[penguinCount] = nullptr;
                isKilled = true;
                std::cout << "One of your penguins has died :(" << std::endl;
            }
            else if(animalType == 3 && turtleCount > 0)  //if random number is 3 and there are turtles, kill a turtle
            {
                turtleCount--;                     //array is 0 indexed, so if there were 10 penguins initially, 
                delete turtleArray[turtleCount];    //we decrement the count to delete the last one (the one at index 9)
                turtleArray[turtleCount] = nullptr;
                isKilled = true;
                std::cout << "One of your turtles has died :(" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "All of your animals are already dead!" << std::endl;
    }
    
}
void Zoo::animalBirth()
{
    bool isBorn = false;
    int animalType = 0;

    if(!hasAdults(tigerArray, tigerCount) && !hasAdults(penguinArray, penguinCount) && 
        !hasAdults(turtleArray, turtleCount))  //check if there are any adult animals
    {
        std::cout << "There are no adult animals in your zoo!" << std::endl;
        isBorn = true;  //if there are no adults, skip the below loop and exit the function
    }

    while(!isBorn)
    {
        animalType = (rand() % 3) + 1;  //random number from 1-3, used to determine which animal dies

        if(animalType == 1 && tigerCount > hasAdults(tigerArray, tigerCount))  //if random number is 1 and there is an adult tiger, new tiger
        {
            if(tigerCount >= tigerArraySize)
            {
                growArray(tigerArray, tigerArraySize);
            }
            Tiger* tiger = new Tiger(true);  //create tiger object. True flag makes an adult.
            tigerArray[tigerCount] = tiger;  //new tiger gets added to the array. Array is 0 indexed, so new tiger goes to tigerCount
                                            //e.g. there are currenty two tigers in indices 0 and 1, so new one goes at index 2 
            tigerCount++;
            isBorn = true;
            std::cout << "A baby tiger was born! :)" << std::endl;
        }
        else if(animalType == 2 && hasAdults(penguinArray, penguinCount))  //if random number is 2 and there is an adult penguin, new penguins
        {
            if(penguinCount+5 >= penguinArraySize)
            {
                growArray(penguinArray, penguinArraySize);
            }
            
            for(int i = 0; i < 5; i++){
                Penguin* penguin = new Penguin();  //create penguin object
                penguinArray[penguinCount] = penguin;  //set the address of this object into first unoccupied slot in the array
                penguinCount++;  //increment penguin counter
            }
            isBorn = true;
            std::cout << "Five baby penguins were born! :)" << std::endl;
        }
        else if(animalType == 3 && hasAdults(turtleArray, turtleCount))  //if random number is 3 and there is an adult turtle, new turtles
        {
            if(turtleCount+10 >= turtleArraySize)
            {
                growArray(turtleArray, turtleArraySize);
            }
            for(int i = 0; i < 10; i++){
                Turtle* turtle = new Turtle();  //create penguin object
                turtleArray[turtleCount] = turtle;  //set the address of this object into first unoccupied slot in the array
                turtleCount++;  //increment turtle counter
            }
            isBorn = true;
            std::cout << "Ten baby turtles were born! :)" << std::endl;
        }
    }
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
int Zoo::getBaseFoodCost()  //returns base food cost
{
    return baseFoodCost;
}
bool Zoo::hasAdults(Tiger** arrayIn, int arraySize)  //searches tiger array for adults, returns true if there is at least 1 adult
{
    bool hasAdults = false;
    if(arraySize > 0) //make sure there is at least 1 animal
    {
        for(int i = 0; i < arraySize; i++)
        {
            if(arrayIn[i]->getAge() >= 3){
                hasAdults = true;
                i = arraySize;  //break out of the loop
            }
        }
    }
    return hasAdults;
}
bool Zoo::hasAdults(Penguin** arrayIn, int arraySize)  //searches penguin array for adults, returns true if there is at least 1 adult
{
    bool hasAdults = false;
    if(arraySize > 0)
    {
        for(int i = 0; i < arraySize; i++)
        {
            if(arrayIn[i]->getAge() >= 3){
                hasAdults = true;
                i = arraySize;  //break out of the loop
            }
        }
    }
    return hasAdults;
}
bool Zoo::hasAdults(Turtle** arrayIn, int arraySize)  //searches tutle array for adults, returns true if there is at least 1 adult
{
    bool hasAdults = false;
    if(arraySize > 0)
    {
        for(int i = 0; i < arraySize; i++)
        {
            if(arrayIn[i]->getAge() >= 3){
                hasAdults = true;
                i = arraySize;  //break out of the loop
            }
        }
    }
    return hasAdults;
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
        revenue += (array1[0]->getPayoff() * tigerCount);
    }
    if(array2size > 0){
        revenue += (array2[0]->getPayoff() * penguinCount);
    }
    if(array3size > 0){
        revenue += (array3[0]->getPayoff() * turtleCount);
    }
    return revenue;
}
void Zoo::purchaseAnimalMenu()
{
    int purchaseChoice = 0;
    bool transactionFinished = false;

    std::cout << "Would you like to buy an adult animal? (1 = Yes  2 = No): ";
    std::cin >> purchaseChoice;
    validateRangedInt(purchaseChoice, 1, 2);

    if(purchaseChoice == 1)
    {
        std::cout << std::endl << std::setw(22) << "Tiger" << std::setw(12) << "Penguin" << std::setw(12) << "Turtle" << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << "Cost: " << std::setw(16) << "$10,000" << std::setw(12) << "$1,000" << std::setw(12) << "$100" << std::endl << std::endl;
                
        while(!transactionFinished)
        {
            purchaseChoice = 0;
            std::cout << "Which animal will you buy? (1 = Tiger  2 = Penguin  3 = Turtle  4 = Cancel): ";
            std::cin >> purchaseChoice;
            validateRangedInt(purchaseChoice, 1, 4);

            if(purchaseChoice == 1)
            {
                if(playerCash < 10000)
                {
                    std::cout << "Not enough money!" << std::endl;
                }
                else
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
                    payForAnimals(1, 0, 0);  //deduct cost of 1 tiger from playerCash
                    transactionFinished = true;
                }
            }
            else if(purchaseChoice == 2)
            {
                if(playerCash < 1000)
                {
                    std::cout << "Not enough money!" << std::endl;
                }
                else
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
                    payForAnimals(0, 1, 0);  //deduct cost of 1 penguin from playerCash
                    transactionFinished = true;
                }
            }
            else if(purchaseChoice == 3)
            {
                if(playerCash < 100)
                {
                    std::cout << "Not enough money!" << std::endl;
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
                    payForAnimals(0, 0, 1);  //deduct cost of 1 turtle from playerCash
                    transactionFinished = true; 
                }     
            }
            else
            {
                transactionFinished = true;
            }
            
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

void Zoo::payForAnimals(int numTigers, int numPenguins, int numTurtles)
{
    playerCash -= ((numTigers * 10000) + (numPenguins * 1000) + (numTurtles * 100));
}
/*********************************************************************
** Author:      Andrew Wilson
** Date:        Jan 20, 2019
** Description: Header file for Die class
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die
{   protected:
        int numSides;  //stores the number of sides
        bool isLoaded;  //stores whether the die is loaded or not
    public:
        Die();  //default constructor we will not use, setsNumsides to 1337
        Die(int numSides);  //constructor
        int getSides(); //returns the number of sides of the player's die
        bool getLoaded();  //returns true if die is loaded, false if not loaded
        int rollDie();  //returns a random number between 1 and numSides
};

class LoadedDie : public Die
{
    public:
        LoadedDie(int numSides);  //constructor
        int rollDie();  //returns a random number between 2 and numSides
};

#endif //Die
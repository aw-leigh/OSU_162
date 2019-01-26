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
    public:
        Penguin();  //default constructor. Makes a baby by default.
        Penguin(bool isAdult);  //constructor that takes a bool, and makes adults (true) or babies (false)
};

#endif //Penguin
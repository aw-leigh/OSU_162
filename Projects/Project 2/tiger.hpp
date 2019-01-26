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
    public:
        Tiger();  //default constructor. Makes a baby by default.
        Tiger(bool isAdult);  //constructor that takes a bool, and makes adults (true) or babies (false)
};

#endif //Tiger
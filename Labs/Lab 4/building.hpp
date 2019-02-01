/*********************************************************************
** Author:      Andrew Wilson
** Date:        Feb 1, 2019
** Description: Header file for Building class.
*********************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>

class Building
{   private:
        std::string name;  //stores the university name
        std::string address;  //stores address
        int size;  //stores size in sqft
    public:
        Building() {};  //unused default constructor
        ~Building() {};
        Building(std::string name, std::string address, int size);  //constructor
        std::string getName();
        std::string getAddress();
        int getSize();

};

#endif //Building
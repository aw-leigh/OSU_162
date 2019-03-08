/***************************************************************
** Program name: Final.cpp
** Author:       Andrew Wilson
** Date:         Mar 11, 2019
** Description:  This is the item specification file for the final project
**               Items are held by terrain or the player. 
***************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include "terrain.hpp"
class Terrain; //forward declaration

class Item
{
    protected:
        std::string name;
        Terrain * space = nullptr;
    public:
        Item();
        Item(Terrain * space);
        virtual ~Item() {};
        virtual std::string getName();
        virtual void addToInventory(Item *) {};
};

#endif
/***************************************************************
** Program name: Final.cpp
** Author:       Andrew Wilson
** Date:         Mar 11, 2019
** Description:  This is the "player" item specification file for the final project
**               Inheirits from item class.
**
**               Name: Player
**               Initially hidden: no
**               Has a std::list of Object pointers as inventory
***************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "item.hpp"
#include <list>

class Player : public Item
{
    protected:
        std::list<Item *> inventory;
    public:
        Player();
        Player(Terrain * space);
        virtual ~Player();
        void addToInventory(Item *);
};

#endif  //Player
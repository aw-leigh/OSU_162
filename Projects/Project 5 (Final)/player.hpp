/***************************************************************
** Program name: Final.cpp
** Author:       Andrew Wilson
** Date:         Mar 11, 2019
** Description:  This is the "player" item specification file for the final project
**               Inheirits from item class 
**
**               Name: Player
**               Initially hidden: no
***************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "item.hpp"

class Player : public Item
{
    protected:

    public:
        Player();
        Player(Terrain * space);
        virtual ~Player();
};

#endif  //Player
/***************************************************************
** Program name: Final.cpp
** Author:       Andrew Wilson
** Date:         Mar 11, 2019
** Description:  This is the "player" item specification file for the final project
**               Inheirits from ite, class 
**
**               Travel time: ~
**               Initially hidden: no
**               Interaction: none
***************************************************************/

#include "item.hpp"
#include "player.hpp"

//Default constructor.
Player::Player()
{
    this->name = "Player";
    this->HP = 15;
}

Player::Player(Terrain * space)
{
    this->name = "Player";
    this->HP = 15;
}

Player::~Player() {}

void Player::addToInventory(Item * item) 
{
    this->inventory.push_back(item);
}

void Player::setHP(int damage) 
{
    this->HP -= damage;
}

int Player::getHP()
{
    return this->HP;
}

int Player::countRocketParts()
{
    int counter = 0;
    
    //look through player's inventory for "Rocket part"s.
    for(auto i : inventory)
    {
        if(i->getName() == "Rocket part")
        {
            counter++;
        }
    }
    return counter;
}
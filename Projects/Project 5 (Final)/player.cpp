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
}

Player::Player(Terrain * space)
{
    this->name = "Player";
}

Player::~Player() {}

void Player::addToInventory(Item * item) 
{
    this->inventory.push_back(item);
}

/*
void Player::updateFOW(Terrain*** &gameBoard)
{
    for(int i = -1; i < 2; i++)
    {
        for(int j = -1; j < 2; j++)
        {
            gameBoard[this->row + i][this->col + j]->setFOW(false);
        }
    }
}
*/
/***************************************************************
** Program name: Character.hpp 
** Author:       Andrew Wilson 
** Date:         February 11, 2019
** Description:  This is the Character class specification file.
**               Barbarian, Vampire, Blue Men, Medusa, and Harry Potter inherit from Character.
**               A Character has a strengthPoint and armor value, and have attack and defence functions.
***************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <stdlib.h> //rand
#include <time.h>  //time
#include <string>
#include <iostream>

class Character
{
    protected:
        int armor;
        int strengthPoints;
        int maxSP;
        bool canRevive = false;

    public:
        Character();
        Character(const Character& oldCharacter); // copy constructor 
        virtual ~Character();
        virtual int attack() = 0;
        virtual int defend(int attack) = 0;
        virtual std::string name() const = 0;
        virtual int getArmor();
        virtual int getSP();
        virtual bool getCanRevive();
        virtual void setCanRevive(bool revive);
        virtual void setSP(int SP);
        virtual int heal();   
};

#endif //character

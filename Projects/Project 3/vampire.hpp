/***************************************************************
** Program name: Vampire.hpp 
** Author:       Andrew Wilson 
** Date:         February 11, 2019
** Description:  This is the Vampire class specification file.
**               Inherits from Character.
**               A vampire starts with 18 SP and has a 1d12 attack, 1d6 defend,
**               and a Charm ability to avoid damage 50% of the time
***************************************************************/

#include "character.hpp"

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

class Vampire : public Character
{
    public:
        Vampire();
        virtual ~Vampire();
        virtual int attack();
        virtual int defend(int attack);
        virtual std::string name() const;
};

#endif //Vampire

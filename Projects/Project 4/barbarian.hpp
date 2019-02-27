/***************************************************************
** Program name: Character.hpp 
** Author:       Andrew Wilson 
** Date:         February 11, 2019
** Description:  This is the Barbarian class specification file.
**               Inherits from Character.
**               A barbarian starts with 12 SP and has a 2d6 attack and defend
***************************************************************/

#include "character.hpp"

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

class Barbarian : public Character
{
    public:
        Barbarian();
        virtual ~Barbarian();
        virtual int attack();
        virtual int defend(int attack);
        virtual std::string name() const;
};

#endif //Barbarian

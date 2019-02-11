/***************************************************************
** Program name: Medusa.hpp 
** Author:       Andrew Wilson 
** Date:         February 11, 2019
** Description:  This is the Medusa class specification file.
**               Inherits from Character.
**               A medusa starts with 12 SP and has a 2d6 attack and defend
***************************************************************/

#include "character.hpp"

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

class Medusa : public Character
{
    public:
        Medusa();
        virtual ~Medusa();
        virtual int attack();
        virtual int defend();
        virtual std::string name() const;
};

#endif //Medusa
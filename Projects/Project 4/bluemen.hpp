/***************************************************************
** Program name: Character.hpp 
** Author:       Andrew Wilson 
** Date:         February 11, 2019
** Description:  This is the BlueMen class specification file.
**               Inherits from Character.
**               A barbarian starts with 12 SP and has a 2d6 attack and defend
***************************************************************/

#include "character.hpp"

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class BlueMen : public Character
{
    public:
        BlueMen();
        virtual ~BlueMen();
        virtual BlueMen* clone() const;
        virtual int attack();
        virtual int defend(int attack);
        virtual std::string name() const;
};

#endif //BlueMen

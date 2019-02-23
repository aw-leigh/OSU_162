/***************************************************************
** Program name: harrypotter.hpp 
** Author:       Andrew Wilson 
** Date:         February 11, 2019
** Description:  This is the HarryPotter class specification file.
**               Inherits from Character.
**               A HarryPotter starts with 12 SP and has a 2d6 attack and defend
***************************************************************/

#include "character.hpp"

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

class HarryPotter : public Character
{
    public:
        HarryPotter();
        virtual ~HarryPotter();
        virtual HarryPotter* clone() const;
        virtual int attack();
        virtual int defend(int attack);
        virtual std::string name() const;
        virtual int heal();   
};

#endif //HarryPotter
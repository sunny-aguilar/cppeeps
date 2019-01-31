/*********************************************************************
** Program name:    Critter.hpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Critter class description here
*********************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

#include "Doodlebug.hpp"
#include "Ant.hpp"

class Critter
{
protected:

public:
    Critter();
    virtual  ~Critter();
    virtual void move();
    virtual void breed();
};

#endif //CRITTER_HPP
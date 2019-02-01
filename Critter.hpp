/*********************************************************************
** Program name:    Critter.hpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Critter class description here. Critter is an
**                  abstract base class
*********************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <iostream>
using std::cout;
using std::endl;

class Critter
{
protected:
    std::string critterType;
    int stepsSurvived;

public:
    Critter();
    virtual  ~Critter();
    virtual void move() = 0;
    virtual void breed() = 0;
};

#endif //CRITTER_HPP
/*********************************************************************
** Program name:    Critter.hpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Critter class description here
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
    virtual void move();
    virtual void breed();
};

#endif //CRITTER_HPP
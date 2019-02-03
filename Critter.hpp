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
#include <string>
using std::string;
using std::cout;
using std::endl;

// enum Direction {NORTH = 1, EAST, SOUTH, WEST};

class Critter
{
protected:
    // Direction direction;
    std::string critterType;
    int stepsSurvived;
    int row;
    int col;

public:
    Critter();
    Critter(string type, int row, int col);
    virtual  ~Critter();
    virtual string getCritterType() = 0;
    virtual void move() = 0;
    virtual void breed() = 0;
};

#endif //CRITTER_HPP
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
    int readyToBreed;
    bool critterMoved;
    int row;
    int col;

public:
    Critter();
    Critter(string type, int row, int col);
    virtual  ~Critter();
    virtual int getRow() = 0;
    virtual int getCol() = 0;
    virtual void setRow(int row) = 0;
    virtual void setCol(int col) = 0;
    virtual void setStepsSurvived() = 0;
    virtual int getStepsSurvived() = 0;
    virtual string getCritterType() = 0;
    virtual void move(Critter ***grid) = 0;
    virtual void setCritterMoved(bool moved) = 0;
    virtual bool getCritterMoved() = 0;
    virtual void breed(Critter ***grid, int row, int col) = 0;
};

#endif //CRITTER_HPP
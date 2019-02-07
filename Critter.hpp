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

#include "utils.hpp"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

enum Direction {UP = 1, RIGHT, DOWN, LEFT};

class Critter
{
protected:
    Direction direction;
    std::string critterType;
    int stepsSurvived;
    int critterBred;
    int readyToBreed;
    bool critterMoved;
    int row;
    int col;
    void makeStepTo(int newRow, int newCol, Critter ***&grid);

public:
    Critter();
    Critter(string type, int row, int col);
    virtual  ~Critter();
    int getRow();
    int getCol();
    void setRow(int row);
    void setCol(int col);
    bool getCritterMoved();
    void setCritterMoved(bool moved);
    string getCritterType();

    virtual void setStepsSurvived() = 0;
    virtual int getStepsSurvived() = 0;
    virtual void move(Critter ***&grid, int ROW, int COL) = 0;
    virtual void breed(Critter ***&grid, int row, int col) = 0;
};

#endif //CRITTER_HPP
/*********************************************************************
** Program name:    Doodlebug.hpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Doodlebug class description here
*********************************************************************/
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug : public Critter
{
private:
    int stepsStarved;
protected:

public:
    Doodlebug();
    Doodlebug(int row, int col);
    ~Doodlebug();
    void setStepsSurvived() override;
    int getStepsSurvived() override;
    void eat(Critter ***&grid);
    void move(Critter ***&grid, int gridROW, int gridCOL) override;
    void breed(Critter ***&grid, int row, int col) override;
    void checkAdjacentCells(Critter ***&grid, int gridROW, int gridCOL);
};

#endif // DOODLEBUG_HPP
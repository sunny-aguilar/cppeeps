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
    void checkAdjacentCells(Critter ***&grid, int gridROW, int gridCOL);
    void eat(Critter ***&grid);

protected:

public:
    Doodlebug();
    Doodlebug(int row, int col);
    ~Doodlebug();
    void setStepsSurvived() override;
    int getStepsSurvived() override;
    void resetStepsSurvived();
    bool isStarved() override;
    void move(Critter ***&grid, int gridROW, int gridCOL) override;
    void breed(Critter ***&grid, int row, int col) override;
};

#endif // DOODLEBUG_HPP
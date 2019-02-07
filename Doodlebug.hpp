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
    void makeStepTo(int newRow, int newCol, Critter ***&grid);

protected:

public:
    Doodlebug();
    Doodlebug(int row, int col);
    ~Doodlebug();
    void setStepsSurvived() override;
    int getStepsSurvived() override;
    string getCritterType() override;
    void eat(Critter *ant);
    void move(Critter ***&grid, int ROW, int COL) override;
    void setCritterMoved(bool moved) override;
    bool getCritterMoved() override;
    void breed(Critter ***&grid, int row, int col) override;
};

#endif // DOODLEBUG_HPP
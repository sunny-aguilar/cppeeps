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


protected:

public:
    Doodlebug();
    Doodlebug(int row, int col);
    ~Doodlebug();
    int getRow() override;
    int getCol() override;
    void setRow(int row) override;
    void setCol(int col) override;
    string getCritterType() override;
    void eat(Critter *ant);
    void move(Critter ***grid) override;
    void setCritterMoved(bool moved) override;
    bool getCritterMoved() override;
    void breed() override;
};

#endif // DOODLEBUG_HPP
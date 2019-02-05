/*********************************************************************
** Program name:    Ant.hpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Ant class description here
*********************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant : public Critter
{
private:

protected:

public:
    Ant();
    Ant(int row, int col);
    ~Ant();
    int getRow() override;
    int getCol() override;
    void setRow(int row) override;
    void setCol(int col) override;
    void setStepsSurvived() override;
    int getStepsSurvived() override;
    string getCritterType() override;
    void move(Critter ***grid, int ROW, int COL) override;
    void setCritterMoved(bool moved) override;
    bool getCritterMoved() override;
    void breed(Critter ***grid, int row, int col) override;
};

#endif //ANT_HPP
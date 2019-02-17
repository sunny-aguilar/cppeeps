/*********************************************************************
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Header file for ant subclass
*********************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include "Critter.hpp"

class Ant : public Critter
{
  public:
    Ant();
    Ant(int row, int col);
    ~Ant();
    void setStepsSurvived() override;
    int getStepsSurvived() override;
    int move(Critter ***&grid, int ROW, int COL) override;
    int breed(Critter ***&grid, int row, int col) override;
};

#endif

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
    string getCritterType() override;
    void move() override;
    void setCritterMoved(bool moved) override;
    bool getCritterMoved() override;
    void breed() override;
};

#endif //ANT_HPP
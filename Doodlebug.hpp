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
    int eat(Critter ***&grid); // <-- CHANGED void to int
	int numberDoodlebugs;
	
protected:

public:
    Doodlebug();
    Doodlebug(int row, int col);
    ~Doodlebug();
    void setStepsSurvived() override;
    int getStepsSurvived() override;
    bool isStarved() override;
    int move(Critter ***&grid, int gridROW, int gridCOL) override; // CHANGED void to int
    int breed(Critter ***&grid, int row, int col) override;
    bool isSpaceAvailable(int*);
	int getDoodleCt(); // <-- ADDED
	void setDoodleCt(int); // <-- ADDED 
};

#endif // DOODLEBUG_HPP

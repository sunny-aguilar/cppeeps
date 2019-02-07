/*********************************************************************
** Program name:    Critter.hpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Critter class description here
*********************************************************************/
#include "Critter.hpp"

#include <iostream>

/*********************************************************************
** Description:     no-args default constructor
*********************************************************************/
Critter::Critter() {}

/*********************************************************************
** Description:     two-arg default constructor
*********************************************************************/
Critter::Critter(string type, int row, int col) :
	critterType{type},
	stepsSurvived{0},
	critterBred{false},
	readyToBreed{false},
	critterMoved{false},
	row{row},
	col{col} {}

/***************************************************************************
** Description:     destructor
***************************************************************************/

Critter::~Critter() {}

int Critter::getRow() { return row; }
int Critter::getCol() { return col; }
bool Critter::getCritterMoved() { return critterMoved; }

void Critter::setRow(int row) { this->row = row; }
void Critter::setCol(int col) { this->col = col; }
void Critter::setCritterMoved(bool moved) { this->critterMoved = moved; }

/***************************************************************************
** Description:     destructor
***************************************************************************/
void Critter::makeStepTo(int newRow, int newCol, Critter ***&grid) {
	// check if the cell to move is occupied.
	if (grid[newRow][newCol] != nullptr) { return ;}

	// check if critter has already moved during time step
	if (getCritterMoved()) { return ;}

	// TODO: REMOVE BEFORE SUBMITTING
	// cout << "critter moved\n"
	//   << "from [" << getRow() << "][" << getCol() << "]\n"
	// 	<< "to [" << newRow << "][" << newCol << "]\n"
	// 	<< "survived : " << getStepsSurvived() << "\n\n";

	// move critter on the grid
	grid[newRow][newCol] = grid[getRow()][getCol()];
	grid[getRow()][getCol()] = nullptr;

	// set critter moved bool in critter
	setRow(newRow);
	setCol(newCol);
	setCritterMoved(true);
	setStepsSurvived();
}

/*********************************************************************
** Description:     description
*********************************************************************/
std::string Critter::getCritterType() {
	return this->critterType;
}
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
	col{col},
	newRow{row},
	newCol{col} {}

/***************************************************************************
** Description:     destructor
***************************************************************************/
Critter::~Critter() {}

/***************************************************************************
** Description:     getters
***************************************************************************/
int Critter::getRow() { return row; }
int Critter::getCol() { return col; }
int Critter::getNewRow() { return newRow; }
int Critter::getNewCol() { return newCol; }
bool Critter::getCritterMoved() { return critterMoved; }
std::string Critter::getCritterType() { return this->critterType; }
bool Critter::isStarved() { return false; }

/***************************************************************************
** Description:     setters
***************************************************************************/
void Critter::setRow(int row) { this->row = row; }
void Critter::setCol(int col) { this->col = col; }
void Critter::setNewRow(int newRow) { this->newRow = newRow; }
void Critter::setNewCol(int newCol) { this->newCol = newCol; }
void Critter::setCritterMoved(bool moved) { this->critterMoved = moved; }

/***************************************************************************
** Description: A function to move a critter from current cell to new cell.
** 							1. current cell: grid[row][col]
** 							1. new cell: grid[newRow][newCol]
** 							after move critter, set current location as null pointer,
** 							then set 'row' and 'col' value, which indication current location
** 							to 'newRow' and 'newCol' value.
***************************************************************************/
void Critter::makeStepToNewCell(Critter ***&grid) {
	// check if the cell to move is occupied.
	if (grid[newRow][newCol] != nullptr) { return ; }

	// check if critter has already moved during time step
	if (getCritterMoved()) { return ; }

	// TODO: REMOVE BEFORE SUBMITTING
	// cout << "critter moved: "
	//   << "from [" << getRow() << "][" << getCol() << "]\n"
		// << "to [" << newRow << "][" << newCol << "]\n";
	// 	<< "survived : " << getStepsSurvived() << "\n\n";

	// move critter on the grid
	grid[newRow][newCol] = grid[getRow()][getCol()];
	grid[getRow()][getCol()] = nullptr;

	// set critter's variables to new values
	// row / col / critterMoved / stepsSurvived
	setRow(newRow);
	setCol(newCol);
	setCritterMoved(true);
	setStepsSurvived();
}

/*********************************************************************
** Description: A function calculating and setting newRow and 
** 							newCol value based on the given direction parameter. 
** 							1. UP: decrease row by -1
** 							2. RIGHT: increase col by 1
** 							3. DOWN: increase row by 1
** 							4. LEFT: decrease col by -1
** 							This function handles edge case to send the critter
** 							to the other side of the board.
*********************************************************************/
void Critter::setNewRowColByDirection(int direction, int gridROW, int gridCOL) {
	// reset row/col before calculation
	newRow = row;
	newCol = col;

	// set proper newCol and newRow value based on the given direction,
	// with edge case handling.
	switch (direction) {
		case UP: // get NORTH square
			// if out of bounds NORTH wall
			if (row == 0) { newRow = gridROW - 1; }
			else { newRow = row - 1; }
			break;
		case RIGHT: // get EAST square
			// if out of bounds EAST wall
			if ( col == gridCOL - 1 ) { newCol = 0; } 
			else { newCol = col + 1; }
			break;
		case DOWN: // get SOUTH square
			// if out of bounds SOUTH wall
			if (row == gridROW - 1) { newRow = 0; }
			else { newRow = row + 1; }
			break;
		case LEFT: // get WEST square
			// if out of bounds WEST wall
			if (col == 0) { newCol = gridCOL - 1; }
			else { newCol = col - 1; }
			break;
		default:
			cout << "Unable to determine direction to move!\n";
	}
}
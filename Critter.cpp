/*********************************************************************
** Program name:    Critter.cpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Critter class description here
*********************************************************************/

#include "Critter.hpp"

/*********************************************************************
** Description: Default Constructor
*********************************************************************/
Critter::Critter() {}

/*********************************************************************
** Description: Constructor; takes in a string and two ints. Sets 
** boolean falgs to false.
*********************************************************************/
Critter::Critter(string type, int row, int col) : critterType{type},
												  stepsSurvived{0},
												  critterBred{false},
												  readyToBreed{false},
												  critterMoved{false},
												  row{row},
												  col{col},
												  newRow{row},
												  newCol{col} {}

/***************************************************************************
** Description: Destructor
***************************************************************************/
Critter::~Critter() {}

/***************************************************************************
** Description: Getter for row
***************************************************************************/
int Critter::getRow() { return row; }

/***************************************************************************
** Description: Getter for column
***************************************************************************/
int Critter::getCol() { return col; }

/***************************************************************************
** Description: Getter for new row
***************************************************************************/
int Critter::getNewRow() { return newRow; }

/***************************************************************************
** Description: Getter for new column
***************************************************************************/
int Critter::getNewCol() { return newCol; }

/***************************************************************************
** Description: Getter for conditional if critter moved.
***************************************************************************/
bool Critter::getCritterMoved() { return critterMoved; }

/***************************************************************************
** Description: Getter for critter type
***************************************************************************/
std::string Critter::getCritterType() { return this->critterType; }

/***************************************************************************
** Description: Getter for conditional if critter starved
***************************************************************************/
bool Critter::isStarved() { return false; }

/***************************************************************************
** Description: Getter for conditional if critter bred
***************************************************************************/
bool Critter::getCritterBred() { return critterBred; }

/***************************************************************************
** Description: Setter for row
***************************************************************************/
void Critter::setRow(int row) { this->row = row; }

/***************************************************************************
** Description: Setter for column
***************************************************************************/
void Critter::setCol(int col) { this->col = col; }

/***************************************************************************
** Description: Setter for new row
***************************************************************************/
void Critter::setNewRow(int newRow) { this->newRow = newRow; }

/***************************************************************************
** Description: Setter for new column
***************************************************************************/
void Critter::setNewCol(int newCol) { this->newCol = newCol; }

/***************************************************************************
** Description: Setter for conditional if critter moved
***************************************************************************/
void Critter::setCritterMoved(bool moved) { this->critterMoved = moved; }

/***************************************************************************
** Description: Setter for conditional if critter bred
***************************************************************************/
void Critter::setCritterBred(bool bred) { this->critterBred = bred; }

/***************************************************************************
** Description: Void method that changes the value of steps survived to 0
***************************************************************************/
void Critter::resetStepsSurvived() { stepsSurvived = 0; }

/***************************************************************************
** Description: A function to move a critter from current cell to new cell.
** 							1. current cell: grid[row][col]
** 							2. new cell: grid[newRow][newCol]
** 							after move critter, set current location as null pointer,
** 							then set 'row' and 'col' value, which indication current location
** 							to 'newRow' and 'newCol' value.
***************************************************************************/
void Critter::makeStepToNewCell(Critter ***&grid)
{
	// check if the cell to move is occupied.
	if (grid[newRow][newCol] != nullptr)
	{
		return;
	}

	// check if critter has already moved during time step
	if (getCritterMoved())
	{
		return;
	}

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
void Critter::setNewRowColByDirection(int direction, int gridROW, int gridCOL)
{
	// reset row/col before calculation
	newRow = row;
	newCol = col;

	// set proper newCol and newRow value based on the given direction,
	// with edge case handling.
	switch (direction)
	{
	case UP: // get NORTH square
		// only move when not out of bounds NORTH wall
		if (row > 0)
		{
			newRow = row - 1;
		}
		break;
	case RIGHT: // get EAST square
		// only move when not out of bounds EAST wall
		if (col < gridCOL - 1)
		{
			newCol = col + 1;
		}
		break;
	case DOWN: // get SOUTH square
		// only move when not out of bounds SOUTH wall
		if (row < gridROW - 1)
		{
			newRow = row + 1;
		}
		break;
	case LEFT: // get WEST square
		// only move when not out of bounds WEST wall
		if (col > 0)
		{
			newCol = col - 1;
		}
		break;
	default:
		cout << "Unable to determine direction to move!\n";
	}
}

/*********************************************************************
** Description: Method that iteratively checks adjacent sides to see
** if they're available; used to verify if bug can breed in specific state.
** Takes in an array of ints, representing the 4 cardinal points (NSEW).
** Itertes through array; if value returns true 0 (false), space is
** available and returned true. Returns false otherwise. 
*********************************************************************/
bool Critter::isSpaceAvailable(int *array)
{
	for (int i = 0; i < 4; i++)
	{
		if (array[i] == false)
		{
			return true;
		}
	}
	return false;
}

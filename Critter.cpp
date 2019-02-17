/*********************************************************************
** Program Name:    Predator vs. Prey
** Class Name:      Critter 
** Children:        Ant, Doodlebug
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Class implementation file for Critter base class.
*********************************************************************/

#include "Critter.hpp"

/*********************************************************************
** Description: Default Constructor
*********************************************************************/
Critter::Critter() {}

/*********************************************************************
** Description: Constructor; takes in a string and two ints. Sets 
**              boolean falgs to false.
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
** Name:        resetStepsSurvived
** Description: Void method that changes the value of steps survived to 0
***************************************************************************/
void Critter::resetStepsSurvived() { stepsSurvived = 0; }

/***************************************************************************
** Name:        makeStepToNewCell
** Description: Void method that takes in the dynamic 2D Critter array. 
**              Moves critter to new section (row/col) in array, and then 
**              sets its old location in said array to a nullptr.
***************************************************************************/
void Critter::makeStepToNewCell(Critter ***&grid)
{
	if (grid[newRow][newCol] != nullptr)
	{
		return;
	}

	if (getCritterMoved())
	{
		return;
	}

	grid[newRow][newCol] = grid[getRow()][getCol()];
	grid[getRow()][getCol()] = nullptr;

	setRow(newRow);
	setCol(newCol);
	setCritterMoved(true);
	setStepsSurvived();
}

/*********************************************************************
** Name:        setNewRowColByDirection
** Description: Void method that takes in three ints, representing a
**              a cardinal direction, row, and column. Sets critter's 
**              new location based on said parameters, and also prevents 
**              it from going off the board via the direction parameter.
*********************************************************************/
void Critter::setNewRowColByDirection(int direction, int gridROW, int gridCOL)
{
	newRow = row;
	newCol = col;

	switch (direction)
	{
	case UP:
		if (row > 0)
		{
			newRow = row - 1;
		}
		break;
	case RIGHT:
		if (col < gridCOL - 1)
		{
			newCol = col + 1;
		}
		break;
	case DOWN:
		if (row < gridROW - 1)
		{
			newRow = row + 1;
		}
		break;
	case LEFT:
		if (col > 0)
		{
			newCol = col - 1;
		}
		break;
	default:
		cout << UNABLE_TO_MOVE_PROMPT;
	}
}

/*********************************************************************
** Name:        isSpaceAvailable
** Description: Method that iteratively checks adjacent sides to see
**              if they're available; used to verify if bug can breed 
**              in specific state. Takes in an array of ints, representing 
**              the 4 cardinal points (NSEW). Iterates through array; 
**              if value returns true 0 (false), space is available 
**              and returned true. Returns false otherwise. 
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

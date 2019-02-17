/*********************************************************************
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
*********************************************************************/
#include "Doodlebug.hpp"

/*********************************************************************
** Description: Default Constructor
*********************************************************************/
Doodlebug::Doodlebug() : Critter() {}

/*********************************************************************
** Description: Constructor that takes in two ints (row/col);
** sets default # of steps to 0
*********************************************************************/
Doodlebug::Doodlebug(int row, int col) : Critter{"X", row, col}
{
	stepsStarved = 0;
}

/*********************************************************************
** Description: Destructor
*********************************************************************/
Doodlebug::~Doodlebug() {}

/*********************************************************************
** Description: Setter for steps survived
*********************************************************************/
void Doodlebug::setStepsSurvived()
{
	stepsSurvived++;
}

/*********************************************************************
** Description: Getter for steps survived
*********************************************************************/
int Doodlebug::getStepsSurvived()
{
	return stepsSurvived;
}

/*********************************************************************
** Description: Getter for conditional of whether said bug is starving.
*********************************************************************/
bool Doodlebug::isStarved()
{
	return stepsStarved >= 3;
}

/*********************************************************************
** Description: Takes in a dynamically allocated 2D array of Critters,
** Looks at the destination (cell @ row/col) it should move to. If
** it is already occupied by an Ant, said ant is removed and replaced
** by said bug. Returns an int.
*********************************************************************/
int Doodlebug::eat(Critter ***&grid)
{
	if (grid[newRow][newCol] == nullptr)
	{
		return 0;
	}
	int antEaten = 0;
	if (grid[newRow][newCol]->getCritterType() == "O")
	{
		delete grid[newRow][newCol];
		grid[newRow][newCol] = nullptr;
		stepsStarved = 0;
		antEaten--;
	}
	return antEaten;
}

/*********************************************************************
** Description: Takes in the 2D dynamic array of Critters and two 
** ints (row/col). Iterates through the "board" to see what available 
** moves can be made, randomly determines what direction it shoukd move
** to. If selected direction is already occupied, said object does not move.
** Returns an int.
*********************************************************************/
int Doodlebug::move(Critter ***&grid, int gridROW, int gridCOL)
{
	if (this->getCritterMoved())
	{
		return 0;
	}

	checkAdjacentCells(grid, gridROW, gridCOL);
	stepsStarved++;
	int antEaten = eat(grid);
	makeStepToNewCell(grid);
	return antEaten;
}

/*********************************************************************
** Description: Void methiod that takes in the 2D dynamic array of Critters
** and two ints (row/col). Tries to move to an adjacent cell containing an 
** ant; if it can, sets object's new row/col values and exits. Else,
** if sets such values to the randomly generated direction.
*********************************************************************/
void Doodlebug::checkAdjacentCells(Critter ***&grid, int gridROW, int gridCOL)
{
	int selectionRecord[4] = {0, 0, 0, 0};

	do
	{
		int direction = generateRandomNumber(4);

		if (!selectionRecord[direction - 1])
		{
			setNewRowColByDirection(direction, gridROW, gridCOL);

			if (grid[newRow][newCol] != nullptr)
			{
				if (grid[newRow][newCol]->getCritterType() == "O")
				{
					return;
				}
			}
			selectionRecord[direction - 1] = 1;
		}
	} while (!(selectionRecord[0] && selectionRecord[1] && selectionRecord[2] && selectionRecord[3]));
}

/*********************************************************************
** Description: Takes in a dynamically allocated 2D array of doodlebugs,
** and two ints (row/col). Iteratively checks a randomly selected
** adjacent cell. If it's empty, a new bug is created. Returns
** the # of bugs created.
*********************************************************************/
int Doodlebug::breed(Critter ***&grid, int gridROW, int gridCOL)
{

	int directionTracker[] = {0, 0, 0, 0};
	int doodleBabyTracker = 0;
	do
	{
		int direction = generateRandomNumber(4);

		if (!directionTracker[direction - 1])
		{
			setNewRowColByDirection(direction, gridROW, gridCOL);

			if (grid[newRow][newCol] == nullptr)
			{
				if (stepsSurvived == 8)
				{
					if (getCritterBred() == false)
					{
						grid[newRow][newCol] = new Doodlebug(newRow, newCol);
						grid[row][col]->setCritterBred(true);
						doodleBabyTracker++;
						resetStepsSurvived();
					}
				}
			}
			directionTracker[direction - 1] = 1;
		}
	} while (grid[row][col]->getCritterBred() == false && isSpaceAvailable(directionTracker));

	grid[row][col]->setCritterBred(false);
	return doodleBabyTracker;
}
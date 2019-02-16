/*********************************************************************
** Program name:    Ant.cpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Ant class description here
*********************************************************************/
#include "Ant.hpp"

/*********************************************************************
** Description: Default Constructor
*********************************************************************/
Ant::Ant() : Critter() {}

/*********************************************************************
** Description: Constructor; takes in two ints.
*********************************************************************/
Ant::Ant(int row, int col) : Critter{"O", row, col} {}

/*********************************************************************
** Description: Destructor
*********************************************************************/
Ant::~Ant() {}

/*********************************************************************
** Description: Setter for steps survived
*********************************************************************/
void Ant::setStepsSurvived()
{
	stepsSurvived++;
}

/*********************************************************************
** Description: Getter for steps surivived
*********************************************************************/
int Ant::getStepsSurvived()
{
	return stepsSurvived;
}

/*********************************************************************
** Description: Takes in a dynamically allocated array of Critters and
** two ints (row/col). If specific critter has moved, return 0. Else,
** a random direction is generated, the bug's target destination is 
** updated, and then moves to said destination. Returns 0.
*********************************************************************/
int Ant::move(Critter ***&grid, int gridROW, int gridCOL)
{
	if (this->getCritterMoved())
	{
		return 0;
	}

	// for every time step, the ant randomly moves up, down,
	// left, right. If the neighboring cell in the selected direction
	// left, right. If the neighboring cell in the selected direction
	// is occupied, or would move the ant off the grid, then the
	// ant stays in the current cell

	// generate a random direction to move critter
	int direction = generateRandomNumber(1, 4);

	setNewRowColByDirection(direction, gridROW, gridCOL);
	makeStepToNewCell(grid);
	return 0;
}

/*********************************************************************
** Description: Takes in a dynamically allocated 2D array of doodlebugs,
** and two ints (row/col). Iteratively checks a randomly selected
** adjacent cell. If it's empty, a new bug is created. Returns
** the # of bugs created.
*********************************************************************/
int Ant::breed(Critter ***&grid, int gridROW, int gridCOL)
{
	// if an ant survives for three time steps, at the end of the time
	// steps (after moving) the ant will breed by creating a new ant
	// in an adjacent cell that is empty randomly

	// array to track adjacent cell searched for breeding
	int directionTracker[] = {0, 0, 0, 0};
	int antBabyTracker = 0;
	//cout << "Ant steps survived " << stepsSurvived << endl;
	do
	{
		// generate a random number 1-4
		int direction = generateRandomNumber(4);

		// if adjacent cell has not been selected before
		if (!directionTracker[direction - 1])
		{
			// get random direction
			setNewRowColByDirection(direction, gridROW, gridCOL);

			// if the cell is empty, breed in that cell
			if (grid[newRow][newCol] == nullptr)
			{
				// if the ant has survived 8 steps, then breed
				if (stepsSurvived == 3)
				{
					// it ant has not already bred, then breed
					if (!getCritterBred())
					{
						// create new ant
						grid[newRow][newCol] = new Ant(newRow, newCol);
						// mark parent ant as already bred
						grid[row][col]->setCritterBred(true);
						// increment baby tracker
						antBabyTracker++;
						// resets steps survived by parent ant
						resetStepsSurvived();
					}
				}
			}
			// update location searched
			directionTracker[direction - 1] = 1;
		}
		// keep looping until all adjacent sides have been checked and ant has not bred
	} while (!grid[row][col]->getCritterBred() && isSpaceAvailable(directionTracker));
	// reset critter bred flag on parent
	grid[row][col]->setCritterBred(false);
	return antBabyTracker;
}

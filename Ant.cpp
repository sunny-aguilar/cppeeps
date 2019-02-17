/*********************************************************************
** Program Name: 	Predator vs. Prey
** Class Name:		Ant
** Parent:		Critter
** Author:         	Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  	Sandro Aguilar, Jeesoo Ryoo
** Date:            	02/17/2019
** Description:     	Class implementation file for Ant class.
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
** Name: 	move
** Description: Takes in a dynamically allocated array of Critters and
** 		two ints (row/col). If specific critter has moved, 
**		return 0. Else, a random direction is generated, 
**		the bug's target destination is updated, and then moves 
**		to said destination. Returns 0.
*********************************************************************/
int Ant::move(Critter ***&grid, int gridROW, int gridCOL)
{
	if (this->getCritterMoved())
	{
		return 0;
	}

	int direction = generateRandomNumber(1, 4);

	setNewRowColByDirection(direction, gridROW, gridCOL);
	makeStepToNewCell(grid);
	return 0;
}

/*********************************************************************
** Name: 	breed
** Description: Takes in a dynamically allocated 2D array of doodlebugs,
** 		and two ints (row/col). Iteratively checks a randomly 
**		selected adjacent cell. If it's empty, a new bug is 
**		created. Returns the # of bugs created. 
**		Ant breeds after surviving three iterations.
*********************************************************************/
int Ant::breed(Critter ***&grid, int gridROW, int gridCOL)
{
	int directionTracker[] = {0, 0, 0, 0};
	int antBabyTracker = 0;

	do
	{
		int direction = generateRandomNumber(4);

		if (!directionTracker[direction - 1])
		{
			setNewRowColByDirection(direction, gridROW, gridCOL);

			if (grid[newRow][newCol] == nullptr)
			{
				if (stepsSurvived == 3)
				{
					if (!getCritterBred())
					{
						grid[newRow][newCol] = new Ant(newRow, newCol);
						grid[row][col]->setCritterBred(true);
						antBabyTracker++;
						resetStepsSurvived();
					}
				}
			}
			directionTracker[direction - 1] = 1;
		}
	} while (!grid[row][col]->getCritterBred() && isSpaceAvailable(directionTracker));

	grid[row][col]->setCritterBred(false);
	return antBabyTracker;
}

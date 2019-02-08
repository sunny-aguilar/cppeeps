/*********************************************************************
** Program name:    Doodlebug.hpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Doodlebug class description here
*********************************************************************/
#include "Doodlebug.hpp"

/*********************************************************************
** Description:     no-args default constructor
*********************************************************************/
Doodlebug::Doodlebug() : Critter() {}

/*********************************************************************
** Description:     two-arg default constructor with base class
** 					initialization list
*********************************************************************/
Doodlebug::Doodlebug(int row, int col) : Critter{"X", row, col}
{
	// this is being used for debugging - DELETE AFTER DEBUGGED
	stepsStarved = 0;
	static int num = 1;
	cout << "Doodlebug #" << num << " created on Board[" << row << "][" << col << "]" << endl;
	num++;
}

/*********************************************************************
** Description:     destructor
*********************************************************************/
Doodlebug::~Doodlebug() {}

/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::setStepsSurvived() {
	stepsSurvived++;
}

void Doodlebug::resetStepsSurvived() {
	stepsSurvived = 0;
}

/*********************************************************************
** Description:     description
*********************************************************************/
int Doodlebug::getStepsSurvived() {
	return stepsSurvived;
}

/*********************************************************************
** Description:     description
*********************************************************************/
bool Doodlebug::isStarved() {
	return stepsStarved >= 3;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::eat(Critter ***&grid) {
	if (grid[newRow][newCol] == nullptr) { return ; }

	if (grid[newRow][newCol]->getCritterType() == "O") {
		// DEBUG
		cout << "\nEAT the ant at: " << newRow << ", " << newCol  << "\n\n";
		delete grid[newRow][newCol];
		grid[newRow][newCol] = nullptr;
		stepsStarved = 0;
	}
}

/*********************************************************************
** Description:     this function takes the board pointer and total
**                  rows and columns as parameters to iterate through
**                  the board and find an open square where a critter
**                  can move to. This allows the function to
**                  select the right type of critter to move. If the
**                  space on the board is not empty, then a random
**                  number from 1-4 will be generated to select
**                  the direction to move the critter (1=UP,
**                  2=RIGHT, 3=DOWN, 4=LEFT). A switch statement is
**                  then used to move the critter in the randomly
**                  selected direction. The critters are moved around
**                  the board PACMAN style which is consistent with
**                  keeping the boards on the grid. If the selected
**                  direction is already occupied, then the critter
**                  does not move (consistent with specifications).
*********************************************************************/
void Doodlebug::move(Critter ***&grid, int gridROW, int gridCOL) {
	if (this->getCritterMoved()) { return ; }

	// for every time step, the doodlebug randomly moves up, down,
	// left, right. If the neighboring cell in the selected direction
	// is occupied, or would move the ant off the grid, then the
	// doodlebug stays in the current cell

	checkAdjacentCells(grid, gridROW, gridCOL);

	// // use switch statement to display which direction critter went
	// // DEBUGGING, DELETE THIS SWITCH STMT BEFORE SUBMITTING
	// switch (direction) {
	// 	case UP:
	// 		cout << "\nDoodlebug randomly selected to go NORTH\n";
	// 		break;
	// 	case RIGHT:
	// 		cout << "\nDoodlebug randomly selected to go EAST\n";
	// 		break;
	// 	case DOWN:
	// 		cout << "\nDoodlebug randomly selected to go SOUTH\n";
	// 		break;
	// 	case LEFT:
	// 		cout << "\nDoodlebug randomly selected to go WEST\n";
	// 		break;
	// 	default:
	// 		cout << "\nUnable to get direction to move to!\n";
	// }

	stepsStarved++;
	eat(grid);
	makeStepToNewCell(grid);

	// DEBUG
	// cout << "stepsStarved: " << stepsStarved << endl;
}
						
/*********************************************************************
** Description: A function that checks 4 adjacent cells.
** 							firstly try to move to an adjacent cell containing 
** 							an ant. If the cell contains the Ant, it sets the
** 							newRow and newCol values and terminate the function.
** 							If there are no ants in adjacent cells, it sets 
** 							newCol/newRow values to the random dirction selected
** 							in the very last order
*********************************************************************/
void Doodlebug::checkAdjacentCells(Critter ***&grid, int gridROW, int gridCOL) {
	// to track which cell has been selected randomly,
	// to avoid repeating the process.
	int selectionRecord[4] = { 0, 0, 0, 0 };

	// repeat until one animal give a birth, or all animal has been selected.
	do {
		// generate random direction
		int direction = generateRandomNumber(4);

		// if the direction has not been selected before,
		if (!selectionRecord[direction - 1]) {
			// calculate the newRow and newCol value
			setNewRowColByDirection(direction, gridROW, gridCOL);

			// if the cell contains Ant, return direction value
			if (grid[newRow][newCol] != nullptr) {
				if (grid[newRow][newCol]->getCritterType() == "O") {
					// DEBUG
					// cout << "Selected Direction selected: " << direction;
					return ;
				}
			}

			// if the cell is empty or doodlebug (X)
			// do nothing and mark at selectionRecord
			selectionRecord[direction - 1] = 1;

			// DEBUG: To check which cell has been selected so far.
			// cout << selectionRecord[0] << selectionRecord[1] << selectionRecord[2] << selectionRecord[3] << endl;
		}
	// if all 4 cells has been selected, and no cell has an ant, terminate the loop
	} while(!(selectionRecord[0] && selectionRecord[1] && selectionRecord[2] && selectionRecord[3]));
	
	// DEBUG
	// cout << "random Direction selected: " << direction;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::breed(Critter ***&grid, int gridROW, int gridCOL) {
	// if a doodlebug survives for eight time steps, at the end of the
	// time step, it will spawn off a new doodlebug in the same manner
	// as the ant (only breed into an adjacent empty cell)

	// array to track adjacent cell searched for breeding
	int directionTracker[] = {0,0,0,0};

	do {
		// generate a random number 1-4
		int direction = generateRandomNumber(4);

		// if adjacent cell has not been selected before
		if (!directionTracker[direction - 1]) {
			// get random direction
			setNewRowColByDirection(direction, gridROW, gridCOL);

			// if the cell is empty, breed in that cell
			if (grid[newRow][newCol] == nullptr) {
				// if the doodlebug has survived 8 steps, then breed
				if(stepsSurvived == 8) {
					// it doodlebug has not already bred, then breed
					if (!getCritterBred()) {
						// create new doodlebug
						grid[newRow][newCol] = new Doodlebug(newRow, newCol);
						// mark parent doodlebug as already bred
						grid[row][col]->setCritterBred(true);
						// resets steps survived by parent ant
						resetStepsSurvived();
					}
				}
			}
		// update location searched
		directionTracker[direction - 1] = 1;
		}

		// keep looping until all adjacent sides have been checked and ant has not bred
	} while ( !grid[row][col]->getCritterBred() && !(directionTracker[0] && directionTracker[1] && directionTracker[2] && directionTracker[3]) );

	// reset critter bred flag on parent
	grid[row][col]->setCritterBred(false);
}
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
	if (stepsSurvived <= 8) {
		readyToBreed = true;
	}
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
void Doodlebug::breed(Critter ***&grid, int ROW, int COL) {
	// if a doodlebug survives for eight time steps, at the end of the
	// time step, it will spawn off a new doodlebug in the same manner
	// as the ant (only bree into an adjacent empty cell)
	cout << "Steps survived " << stepsSurvived << endl;

	int select = generateRandomNumber(1,4);
	// find which spaces are empty and set to TRUE in array
	bool keepLooking = true;

	while (keepLooking) {
		// generate a random number from 1-4
		select = generateRandomNumber(1,4);
		// if all four adjacent sides are occupied, do not breed
		if ( (row > 0 && grid[row - 1][col] != nullptr) &&
			(col < COL-1 && grid[row][col + 1] != nullptr) &&
			(row < ROW-1 && grid[row + 1][col] != nullptr) &&
			(col > 0 && grid[row][col - 1] != nullptr) ) {

			// if all sides around doodlebug unavailable, do not spawn
			select = 5;
			keepLooking = false;
			cout << "All sides are full\n";
		}

		// DEBUGGING - DELETE COUT WHEN DONE
		cout << "Side selected " << select << endl;

		// if adjacent sides available, randomly select one
		// "select" variable will end while-loop and be input for
		// next switch statement below that creates a new doodlebug
		switch (select) {
			case 1:
				// NORTH
				if ((row - 1) >= 0 && grid[row - 1][col] == nullptr) {
					// DEBUGGING - DELETE COUT WHEN DONE
					cout << "NORTH selected " << select << endl;
				}
				keepLooking = false;
				break;
			case 2:
				// EAST
				if ((col + 1) < COL && grid[row][col + 1] == nullptr) {
					// DEBUGGING - DELETE COUT WHEN DONE
					cout << "EAST selected " << select << endl;
				}
				keepLooking = false;
				break;
			case 3:
				// SOUTH
				if ((row + 1) < ROW && grid[row + 1][col] == nullptr) {
					// DEBUGGING - DELETE COUT WHEN DONE
					cout << "SOUTH selected " << select << endl;
				}
				keepLooking = false;
				break;
			case 4:
				// WEST
				if ((col - 1) >= 0 && grid[row][col - 1] == nullptr) {
					// DEBUGGING - DELETE COUT WHEN DONE
					cout << "WEST selected " << select << endl;
				}
				keepLooking = false;
				break;
			default:
				cout << "Unable to determine selection!\n";
		}
	}

	// if a doodlebug has survived for 8 steps or more, than the doodlebug
	// should breed if there is space available
	// NEED TO INCORPORATE EAT FUNCTION
	if (stepsSurvived >= 8) {
		switch (select) {
			case 1:
				// breed NORTH square
				if ((row - 1) >= 0 && grid[row - 1][col] == nullptr) {
					grid[row - 1][col] = new Doodlebug(row - 1, col);
				}
				else {
					// DEBUGGING - this else stmt can be deleted
					cout << "Unable to spawn a doodlebug\n";
				}
				break;
			case 2:
				// breed EAST square
				if ((col + 1) < COL && grid[row][col + 1] == nullptr) {
					grid[row][col + 1] = new Doodlebug(row, col + 1);
				}
				else {
					// DEBUGGING - this else stmt can be deleted
					cout << "Unable to spawn a doodlebug\n";
				}
				break;
			case 3:
				// breed SOUTH square
				if ((row + 1) < ROW && grid[row + 1][col] == nullptr) {
					grid[row + 1][col] = new Doodlebug(row + 1, col);
				}
				else {
					// DEBUGGING - this else stmt can be deleted
					cout << "Unable to spawn a doodlebug\n";
				}
				break;
			case 4:
				// breed WEST square
				if ((col - 1) >= 0 && grid[row][col - 1] == nullptr) {
					grid[row][col - 1] = new Doodlebug(row, col - 1);
				}
				else {
					// DEBUGGING - this else stmt can be deleted
					cout << "Unable to spawn a doodlebug\n";
				}
				break;
			default:
				cout << "Doodlebug unable to breed, all spaces occupied!\n";
		}
	}
}
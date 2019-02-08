/*********************************************************************
** Program name:    Ant.hpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Ant class description here
*********************************************************************/
#include "Ant.hpp"

/*********************************************************************
** Description:     no-args default constructor
*********************************************************************/
Ant::Ant() : Critter() {}

/*********************************************************************
** Description:     two-arg default constructor with base class
** 					initialization list
*********************************************************************/
Ant::Ant(int row, int col) : Critter{"O", row, col} {
	// this is being used for debugging - DELETE AFTER DEBUGGED
//	static int num = 1;
//	cout << "Ant #" << num << " created on Board[" << row << "][" << col << "]" << endl;
//	num++;
}

/*********************************************************************
** Description:     destructor
*********************************************************************/
Ant::~Ant() {}

/*********************************************************************
** Description:     description
*********************************************************************/
void Ant::setStepsSurvived() {
	stepsSurvived++;
//	if (stepsSurvived <= 3) {
//		readyToBreed = true;
//	}
}

/*********************************************************************
** Description:     description
*********************************************************************/
int Ant::getStepsSurvived() {
	return stepsSurvived;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Ant::move(Critter ***&grid, int gridROW, int gridCOL) {
	if (this->getCritterMoved()) { return ; }

	// for every time step, the ant randomly moves up, down,
	// left, right. If the neighboring cell in the selected direction
	// is occupied, or would move the ant off the grid, then the
	// ant stays in the current cell

	// generate a random direction to move critter
	int direction = generateRandomNumber(1,4);

	// // use switch statement to display which direction critter went
	// // DEBUGGING, DELETE THIS SWITCH STMT BEFORE SUBMITTING
	// switch (direction) {
	// 	case UP:
	// 		cout << "\nAnt randomly selected to go NORTH\n";
	// 		break;
	// 	case RIGHT:
	// 		cout << "\nAnt randomly selected to go EAST\n";
	// 		break;
	// 	case DOWN:
	// 		cout << "\nAnt randomly selected to go SOUTH\n";
	// 		break;
	// 	case LEFT:
	// 		cout << "\nAnt randomly selected to go WEST\n";
	// 		break;
	// 	default:
	// 		cout << "\nUnable to get direction to move to!\n";
	// }

	// cout << "Random direction generated " << direction << endl;

	setNewRowColByDirection(direction, gridROW, gridCOL);
	makeStepToNewCell(grid);
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Ant::breed(Critter ***&grid, int gridROW, int gridCOL) {
	// if an ant survives for three time steps, at the end of the time
	// steps (after moving) the ant will breed by creating a new ant
	// in an adjacent cell that is empty randomly

	// array to track adjacent cell searched for breeding
	int directionTracker[] = {0,0,0,0};
	//cout << "Ant steps survived " << stepsSurvived << endl;
	do {
		// generate a random number 1-4
		int direction = generateRandomNumber(4);

		// if adjacent cell has not been selected before
		if (!directionTracker[direction - 1]) {
			// get random direction
			setNewRowColByDirection(direction, gridROW, gridCOL);

			// if the cell is empty, breed in that cell
			if (grid[newRow][newCol] == nullptr) {
				// if the ant has survived 8 steps, then breed
				if(stepsSurvived == 3) {
					// it ant has not already bred, then breed
					if (!getCritterBred()) {
						// create new ant
						grid[newRow][newCol] = new Ant(newRow, newCol);
						// mark parent ant as already bred
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
	} while( !grid[row][col]->getCritterBred() && !(directionTracker[0] && directionTracker[1] && directionTracker[2] && directionTracker[3]) );

	// reset critter bred flag on parent
	grid[row][col]->setCritterBred(false);
}
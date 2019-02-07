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
	if (stepsSurvived <= 3) {
		readyToBreed = true;
	}
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
	// for every time step, the doodlebug randomly moves up, down,
	// left, right. If the neighboring cell in the selected direction
	// is occupied, or would move the ant off the grid, then the
	// doodlebug stays in the current cell

	// generate a random direction to move critter
	int direction;
	direction = generateRandomNumber(1,4);

	// use switch statement to display which direction critter went
	// DEBUGGING, DELETE THIS SWITCH STMT BEFORE SUBMITTING
	switch (direction) {
		case UP:
			cout << "\nAnt randomly selected to go NORTH\n";
			break;
		case RIGHT:
			cout << "\nAnt randomly selected to go EAST\n";
			break;
		case DOWN:
			cout << "\nAnt randomly selected to go SOUTH\n";
			break;
		case LEFT:
			cout << "\nAnt randomly selected to go WEST\n";
			break;
		default:
			cout << "\nUnable to get direction to move to!\n";
	}

	cout << "Random direction generated " << direction << endl;

	// use switch statement to move critter based on random number generated
	// NOTES:
	// row = specific doodle row
	// gridROW = max ROW size
	switch (direction) {
		case UP: // get NORTH square
			// if out of bounds NORTH wall, stay at current location
			if (row == 0) { 
				makeStepTo(gridROW - 1, col, grid);
			} else {
				makeStepTo(row - 1, col, grid);
			}
			break;
		case RIGHT: // get EAST square
			// if out of bounds EAST wall, stay
			if ( col == gridCOL - 1 ) {
				makeStepTo(row, 0, grid);
			} else {
				makeStepTo(row, col + 1, grid);
			}
			break;
		case DOWN: // get SOUTH square
			// if out of bounds SOUTH wall
			if (row == gridROW - 1) {
				makeStepTo(0, col, grid);
			} else {
				makeStepTo(row + 1, col, grid);
			}
			break;
		case LEFT: // get WEST square
			// if out of bounds WEST wall
			if (col == 0) {
				makeStepTo(row, gridCOL - 1, grid);
			} else {
				makeStepTo(row, col - 1, grid);
			}
			break;
		default:
			cout << "Unable to determine direction to move!\n";
	}
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Ant::breed(Critter ***&grid, int row, int col) {
	// if an ant survives for three time steps, at the end of the time
	// steps (after moving) the ant will breed by creating a new ant
	// in an adjacent cell that is empty randomly


}
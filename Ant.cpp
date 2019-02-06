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
void Ant::breed(Critter ***&grid, int row, int col) {
	// if an ant survives for three time steps, at the end of the time
	// steps (after moving) the ant will breed by creating a new ant
	// in an adjacent cell that is empty randomly


}

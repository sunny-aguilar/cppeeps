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
Doodlebug::Doodlebug() {}

/*********************************************************************
** Description:     two-arg default constructor with base class
** 					initialization list
*********************************************************************/
Doodlebug::Doodlebug(int row, int col) : Critter{"X", row, col}
{
	// this is being used for debugging - DELETE AFTER DEBUGGED
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
int Doodlebug::getRow() {
	return row;
}

/*********************************************************************
** Description:     description
*********************************************************************/
int Doodlebug::getCol() {
	return col;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::setRow(int row) {
	this->row = row;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::setCol(int col) {
	this->col = col;
}

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
string Doodlebug::getCritterType() {
	return critterType;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::eat(Critter *bug) {
	if (bug->getCritterType() == "O") {
		// logic to show that ant has been eaten


	}
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::move(Critter ***grid) {
	// for every time step, the doodlebug randomly moves up, down,
	// left, right. If the neighboring cell in the selected direction
	// is occupied, or would move the ant off the grid, then the
	// doodlebug stays in the current cell
	// cout << "Doodlebug Row " << row << " Col " << col << endl;

}

/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::setCritterMoved(bool moved) {
	critterMoved = moved;
}

/*********************************************************************
** Description:     description
*********************************************************************/
bool Doodlebug::getCritterMoved() {
	return critterMoved;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::breed(Critter ***grid, int r_index, int c_index) {
	// if a doodlebug survives for eight time steps, at the end of the
	// time step, it will spawn off a new doodlebug in the same manner
	// as the ant (only bree into an adjacent empty cell)
	cout << "Steps survived " << stepsSurvived << endl;

	bool spaceAvailable[] = {false, false, false, false};
	int randomSelection;

	// find which spaces are empty and set to TRUE in array
	// NORTH
	if (grid[r_index - 1][c_index] == nullptr && (r_index - 1) >= 0) {
		spaceAvailable[0] = true;
	}
	else {
		spaceAvailable[0] = false;
	}
	// EAST
	if (grid[r_index][c_index + 1] == nullptr && (c_index + 1) < col) {
		spaceAvailable[1] = true;
	}
	else {
		spaceAvailable[1] = false;
	}
	// SOUTH
//	if (grid[r_index + 1][c_index] == nullptr && (r_index + 1) < row) {
//		spaceAvailable[2] = true;
//	}
//	else {
//		spaceAvailable[2] = false;
//	}
	// WEST
//	if (grid[r_index][c_index - 1] == nullptr && (c_index - 1) >= 0) {
//		spaceAvailable[3] = true;
//	}
//	else {
//		spaceAvailable[3] = false;
//	}

	// generate a random number from 1 - 4
	randomSelection = generateRandomNumber(1,4);


	// select a random available square (where bool in array = true)
//	int select = 0;
//	int keepSearching = true;
//	while (keepSearching) {
//		if (spaceAvailable[randomSelection] == true) {
//			select = randomSelection;
//			keepSearching = false;
//		}
//	}
//
//	if (stepsSurvived >= 8) {
//		switch (select) {
//			case 1:
//				// breed NORTH square
//				if (grid[r_index - 1][c_index] == nullptr && (r_index - 1) >= 0) {
//					grid[r_index - 1][c_index] = new Doodlebug(r_index - 1, c_index);
//				}
//				break;
//			case 2:
//				// breed EAST square
//				if (grid[r_index][c_index + 1] == nullptr && (r_index + 1) < col) {
//					grid[r_index][c_index + 1] = new Doodlebug(r_index, c_index + 1);
//				}
//				break;
//			case 3:
//				// breed SOUTH square
//				if (grid[r_index + 1][c_index] == nullptr && (r_index + 1) < row) {
//					grid[r_index +1 ][c_index] = new Doodlebug(r_index + 1, c_index);
//				}
//				break;
//			case 4:
//				// breed WEST square
//				if (grid[r_index][c_index - 1] == nullptr && (c_index - 1) >= 0) {
//					grid[r_index][c_index - 1] = new Doodlebug(r_index, c_index - 1);
//				}
//				break;
//			default:
//				cout << "Unable to determine where to breed!\n";
//		}
//	}
}
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
void Doodlebug::breed(Critter ***grid, int ROW, int COL) {
	// if a doodlebug survives for eight time steps, at the end of the
	// time step, it will spawn off a new doodlebug in the same manner
	// as the ant (only bree into an adjacent empty cell)
	cout << "Steps survived " << stepsSurvived << endl;

	int select = generateRandomNumber(1,4);
	// find which spaces are empty and set to TRUE in array
	bool keepLooking = true;

	while (keepLooking) {

		select = generateRandomNumber(1,4);

		// if all four adjacent sides are occupied, do not breed
		if ( ((row - 1) >= 0 && grid[row - 1][col] != nullptr) &&
		     ((col + 1) < COL && grid[row][col + 1] == nullptr) &&
		     ((row + 1) < ROW && grid[row + 1][col] == nullptr) &&
		     ((col - 1) >= 0 && grid[row][col - 1] == nullptr) ) {

			// if all sides around doodlebug unavailable, do not spawn
			select = 5;
		}

		cout << "Side selected " << select << endl;

		// if adjacent sides available, randomly select one
		switch (select) {
			case 1:
				// NORTH
				if ((row - 1) >= 0 && grid[row - 1][col] == nullptr) {
					keepLooking = false;
				}
				break;
			case 2:
				// EAST
				if ((col + 1) < COL && grid[row][col + 1] == nullptr) {
					keepLooking = false;
				}
				break;
			case 3:
				// SOUTH
				if ((row + 1) < ROW && grid[row + 1][col] == nullptr) {
					keepLooking = false;
				}
				break;
			case 4:
				// WEST
				if ((col - 1) >= 0 && grid[row][col - 1] == nullptr) {
					keepLooking = false;
				}
				break;
			default:
				cout << "Unable to determine selection!\n";
		}
	}


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
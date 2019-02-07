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
void Doodlebug::move(Critter ***&grid, int ROW, int COL) {
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
			cout << "Doodlebug randomly selected to go NORTH\n";
			break;
		case RIGHT:
			cout << "Doodlebug randomly selected to go EAST\n";
			break;
		case DOWN:
			cout << "Doodlebug randomly selected to go SOUTH\n";
			break;
		case LEFT:
			cout << "Doodlebug randomly selected to go WEST\n";
			break;
		default:
			cout << "Unable to get direction to move to!\n";
	}

	cout << "Random direction generated " << direction << endl;

	// use switch statement to move critter based on random number generated
	// NOTES:
	// row = specific doodle row
	// ROW = max ROW size
	switch (direction) {
		case UP: // get NORTH square
			// if out of bounds NORTH wall, stay at current location
			if (row == 0) { row = 1; }
			makeStepTo(row - 1, col, grid);
			break;
		case RIGHT: // get EAST square
			// if out of bounds EAST wall, stay
			if ( col == COL - 1 ) { col -= 1; }
			makeStepTo(row, col + 1, grid);
			break;
		case DOWN: // get SOUTH square
			// if out of bounds SOUTH wall
			if (row == ROW - 1) { row -= 1; }
			makeStepTo(row + 1, col, grid);
			break;
		case LEFT: // get WEST square
			// if out of bounds WEST wall
			if (col == 0) { col = 1; }
			makeStepTo(row, col - 1, grid);
			break;
		default:
			cout << "Unable to determine direction to move!\n";
	}
}
						
/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::makeStepTo(int newRow, int newCol, Critter ***&grid) {
	// check if the cell to move is occupied.
	cout << "(grid[newRow][newCol] == nullptr)" << (grid[newRow][newCol] == nullptr) << endl;
	if (grid[newRow][newCol] != nullptr) { return ;}

	cout << "getCritterMoved()" << getCritterMoved() << endl;

	// check if critter has already moved during time step
	if (getCritterMoved()) { return ;}

	// cout << "\nBEFORE MOVE\n";
	// cout << "OLD Row " << getRow() << " Col " << getCol() << endl;
	// cout << "NEW Row " << newRow << " Col " << newCol << endl;
	// cout << "After MOVE\n";
	// cout << "Steps moved by [" << getRow() << "][" << getCol() << "] - " << getStepsSurvived() << "\n\n";

	// move doodlebug
	grid[newRow][newCol] = grid[getRow()][getCol()];
	grid[getRow()][getCol()] = nullptr;

	// set critter moved bool in Doodlebug
	setRow(newRow);
	setCol(newCol);
	setCritterMoved(true);
	setStepsSurvived();
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
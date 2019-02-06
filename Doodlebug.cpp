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
void Doodlebug::move(Critter ***grid, int ROW, int COL) {
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
			{
				if ( (row - 1) < 0 ) {  // if out of bounds NORTH wall
					if (grid[ROW - 1][col] == nullptr) {   // go to last row
						if (getCritterMoved()) {
							// if critter already moved, do not move it again
						}
						else {
							// DEBUGGING - DELETE WHEN DONE
							//cout << "\nPACMAN NORTH move\n";
							//cout << "Doodlebug move NORTH available, " << "Move to [" << ROW - 1 << "][" << col << "]" << endl;

							// create new doodlebug
                            Critter *temp = new Doodlebug(ROW-1, col);

							// move doodlebug
							grid[ROW - 1][col] = temp;

                            // set critter moved bool in Doodlebug
                            grid[ROW - 1][col]->setCritterMoved(true);

							// DEBUGGING - DELETE WHEN DONE
							//cout << "OLD Row " << getRow() << " Col " << getCol() << endl;

							// DEBUGGING - DELETE WHEN DONE
							//cout << "NEW Row " << getRow() << " Col " << getCol() << endl;

							// update doodlebug stepsSurvived counter in doodlebug class
							setStepsSurvived();

							// DEBUGGING - DELETE WHEN DONE
							//cout << "Steps moved by [" << row << "][" << col << "] - " << getStepsSurvived() << endl;

							// set old pointer to null
                            //delete temp;
                            temp = nullptr;
							grid[row][col] = nullptr;
						}
					}
					else {
						// DEBUGGING - THIS ELSE CAN BE DELETED
						//cout << "Doodlebug move NORTH " << "[" << row << "][" << col<< "]" << " unavailable\n";
					}
				}
				else {
					if (grid[row - 1][col] == nullptr) {

						// check if critter has already moved during time step
						if (getCritterMoved()) {
							// if critter already moved, do not move it again
						}
						else {
							// DEBUGGING - DELETE WHEN DONE
                            //cout << "Normal NORTH move\n";
                            //cout << "Doodlebug move NORTH available, " << "Move to [" << row - 1 << "][" << col << "]" << endl;

                            // create new doodlebug
                            Critter *temp = new Doodlebug(row-1, col);

							// move doodlebug
							grid[row - 1][col] = temp;

                            // set critter moved bool in Doodlebug
                            grid[row - 1][col]->setCritterMoved(true);

							// DEBUGGING - DELETE WHEN DONE
							//cout << "OLD Row " << getRow() << " Col " << getCol() << endl;

							// DEBUGGING - DELETE WHEN DONE
							//cout << "NEW Row " << getRow() << " Col " << getCol() << endl;

							// update doodlebug stepsSurvived counter in doodlebug class
							setStepsSurvived();

							// DEBUGGING - DELETE WHEN DONE
							//cout << "Steps moved by [" << row-1 << "][" << col << "] - " << getStepsSurvived() << endl;

							// delete old pointer here? I don't think so
							// delete board[r_index][c_index];

							// set old pointer to null
                            temp = nullptr;
							grid[row][col] = nullptr;
						}
					}
					else {
						// DEBUGGING - THIS ELSE CAN BE DELETED
						//cout << "Doodlebug move NORTH " << "[" << row << "][" << col << "]" << " unavailable\n";
					}
				}
			}
			break;
		case RIGHT: // get EAST square
			{
				if ( (col + 1) >= COL ) {  // if out of bounds EAST wall
					if (grid[row][0] == nullptr) {   // go to first col

						// check if critter has already moved during time step
						if (getCritterMoved()) {
							// if critter already moved, do not move it again
						}
						else {
							// DEBUGGING - DELETE WHEN DONE
							//cout << "Doodlebug move EAST available, " << "Move to [" << row << "][" << 0 << "]" << endl;

                            // create new doodlebug
                            Critter *temp = new Doodlebug(row, 0);

							// move doodlebug
							grid[row][0] = temp;

                            // set critter moved bool in Doodlebug to true
                            grid[row][0]->setCritterMoved(true);

							// DEBUGGING - DELETE WHEN DONE
							//cout << "OLD Row " << getRow() << " Col " << getCol() << endl;

							// DEBUGGING - DELETE WHEN DONE
							//cout << "NEW Row " << getRow() << " Col " << getCol() << endl;

							// update doodlebug stepsSurvived counter in doodlebug class
							setStepsSurvived();

							// DEBUGGING - DELETE WHEN DONE
							//cout << "Steps moved by [" << row << "][" << 0 << "] - " << getStepsSurvived() << endl;

							// set old pointer to null
							temp = nullptr;
							grid[row][col] = nullptr;
						}
					}
					else {
						// DEBUGGING - THIS ELSE CAN BE DELETED
						//cout << "Doodlebug move EAST " << "[" << row << "][" << col << "]" << " unavailable\n";
					}
				}
				else {
					if (grid[row][col + 1] == nullptr) {

						// check if critter has already moved during time step
						if (getCritterMoved()) {
							// if critter already moved, do not move it again
						}
						else {
							// DEBUGGING - DELETE WHEN DONE
							//cout <<  "Doodlebug move EAST available, " << "Move to [" << row << "][" << col + 1 << "]" << endl;

                            // create new doodlebug
                            Critter *temp = new Doodlebug(row, col + 1);

							// move doodlebug
							grid[row][col + 1] = temp;

                            // set critter moved bool in Doodlebug
                            grid[row][col + 1]->setCritterMoved(true);

							// DEBUGGING - DELETE WHEN DONE
							//cout << "OLD Row " << getRow() << " Col " << getCol() << endl;

							// DEBUGGING - DELETE WHEN DONE
							//cout << "NEW Row " << getRow() << " Col " << getCol() << endl;

							// update doodlebug stepsSurvived counter in doodlebug class
							setStepsSurvived();

							// DEBUGGING - DELETE WHEN DONE
							//cout << "Steps moved by [" << row << "][" << col+1 << "] - " << getStepsSurvived() << endl;

							// set old pointer to null
							temp = nullptr;
							grid[row][col] = nullptr;
						}
					}
					else {
						// DEBUGGING - THIS ELSE CAN BE DELETED
						//cout << "Doodlebug move EAST " << "[" << row << "][" << col << "]" << " unavailable\n";
					}
				}
			}
			break;
		case DOWN: // get SOUTH square
			{
			    if (row + 1 >= ROW) {  // if out of bounds SOUTH wall
			        if (grid[0][col] == nullptr) { // go to first row

			            // check if critter has already moved during time step
			            if (getCritterMoved()) {
			                // if critter already moved, do not move it again
			            }
			            else {
			                // DEBUGGING - DELETE WHEN DONE
			                //cout <<  "Doodlebug move NORTH available, " << "Move to [" << 0 << "][" << col << "]" << endl;

			                // create new doodlebug
			                Critter *temp = new Doodlebug(0, col);

			                // move doodlebug
			                grid[0][col] = temp;

                            // set critter moved bool in Doodlebug
			                grid[0][col]->setCritterMoved(true);

			                // DEBUGGING - DELETE WHEN DONE
			                //cout << "OLD Row " << getRow() << " Col " << getCol() << endl;
			                //cout << "NEW Row " << grid[0][col]->getRow() << " Col " << grid[0][col]->getCol() << endl;

			                // update doodlebug stepsSurvived counter in doodlebug class
			                setStepsSurvived();

			                // DEBUGGING - DELETE WHEN DONE
			                //cout << "Steps moved " << grid[0][col]->getStepsSurvived() << endl;

			                // set old pointer to null
			                temp = nullptr;
			                grid[row][col] = nullptr;
			            }
			        }
			        else {
			            // DEBUGGING - THIS ELSE CAN BE DELETED
			            //cout << "Doodlebug move SOUTH " << "[" << row << "][" << col << "]" << " unavailable\n";
			        }
			    }
			    else {
			        if (grid[row + 1][col] == nullptr) {

			            // check if critter has already moved during time step
			            if (getCritterMoved()) {
			                // if critter already moved, do not move it again
			            }
			            else {
			                // DEBUGGING - DELETE WHEN DONE
			                //cout << "Doodlebug move SOUTH available, " << "Move to [" << row + 1 << "][" << col << "]" << endl;

			                // create new doodlebug
			                Critter *temp = new Doodlebug(row + 1, col);

			                // move doodlebug
			                grid[row + 1][col] = temp;

                            // set critter moved bool in Doodlebug (must set bool before moving)
			                grid[row + 1][col]->setCritterMoved(true);

			                // DEBUGGING - DELETE WHEN DONE
			                //cout << "OLD Row " << getRow() << " Col " << getCol() << endl;
			                //cout << "NEW Row " << grid[row + 1][col]->getRow() << " Col " << grid[row + 1][col]->getCol() << endl;

			                // update doodlebug stepsSurvived counter in doodlebug class
			                setStepsSurvived();

			                // DEBUGGING - DELETE WHEN DONE
			                //cout << "Steps moved " << grid[row + 1][col]->getStepsSurvived() << endl;

			                // set old pointer to null
			                temp = nullptr;
			                grid[row][col] = nullptr;
			            }
			        }
			        else {
			            // DEBUGGING - THIS ELSE CAN BE DELETED
			            //cout << "Doodlebug move SOUTH " << "[" << row << "][" << col << "]" << " unavailable\n";
			        }
			    }
			}
			break;
		case LEFT: // get WEST square
			{
			    if ( (col - 1) < 0 ) {  // if out of bounds WEST wall
			        if (grid[row][COL - 1] == nullptr) {   // go to last col

			            if (getCritterMoved()) {
			                // if critter already moved, do not move it again
			            }
			            else {
			                // DEBUGGING - DELETE WHEN DONE
			                //cout << "Doodlebug move WEST available, " << "Move to [" << row << "][" << col - 1 << "]" << endl;

			                // create new doodlebug
			                Critter *temp = new Doodlebug(row, COL - 1);

			                // move doodlebug to last column
			                grid[row][COL - 1] = temp;

			                // set critter moved bool in Doodlebug to true
			                grid[row][COL - 1]->setCritterMoved(true);

			                // DEBUGGING - DELETE WHEN DONE
			                //cout << "OLD Row " << getRow() << " Col " << getCol() << endl;
			                //cout << "NEW Row " << grid[row][col - 1]->getRow() << " Col " << grid[row][col - 1]->getCol() << endl;

			                // update doodlebug stepsSurvived counter in doodlebug class
			                setStepsSurvived();

			                // DEBUGGING - DELETE WHEN DONE
			                //cout << "Steps moved " << grid[row][col - 1]->getStepsSurvived() << endl;

			                // set old pointer to null
			                temp = nullptr;
			                grid[row][col] = nullptr;
			            }
			        }
			        else {
			            // DEBUGGING - THIS ELSE CAN BE DELETED
			            //cout << "Doodlebug move WEST " << "[" << row << "][" << col << "]" << " unavailable\n";
			        }
			    }
			    else {
			        if (grid[row][col - 1] == nullptr) {

			            // check if critter has already moved during time step
			            if (getCritterMoved()) {
			                // if critter already moved, do not move it again
			            }
			            else {
			                // DEBUGGING - DELETE WHEN DONE
			                //cout << "Doodlebug move WEST available, " << "Move to [" << row << "][" << col - 1 << "]" << endl;

			                // create new doodlebug
			                Critter *temp = new Doodlebug(row, col - 1);

			                // move doodlebug
			                grid[row][col - 1] = temp;

			                // set critter moved bool in Doodlebug (must set bool before moving)
			                grid[row][col - 1]->setCritterMoved(true);

			                // DEBUGGING - DELETE WHEN DONE
			                //cout << "OLD Row " << getRow() << " Col " << getCol() << endl;
			                //cout << "NEW Row " << grid[row][col - 1]->getRow() << " Col " << grid[row][col - 1]->getCol() << endl;

			                // update doodlebug stepsSurvived counter in doodlebug class
			                setStepsSurvived();

			                // DEBUGGING - DELETE WHEN DONE
			                //cout << "Steps moved " << grid[row][col - 1]->getStepsSurvived() << endl;

			                // set old pointer to null
			                temp = nullptr;
			                grid[row][col] = nullptr;
			            }
			        }
			        else {
			            // DEBUGGING - DELETE WHEN DONE
			            //cout << "Doodlebug move WEST " << "[" << row << "][" << col << "]" << " unavailable\n";
			        }
			    }
			}
			break;
		default:
			cout << "Unable to determine direction to move!\n";
	}
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
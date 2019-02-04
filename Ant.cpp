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
Ant::Ant() {}

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
int Ant::getRow() {
	return row;
}

/*********************************************************************
** Description:     description
*********************************************************************/
int Ant::getCol() {
	return col;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Ant::setRow(int row) {
	this->row = row;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Ant::setCol(int col) {
	this->col = col;
}

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
string Ant::getCritterType() {
	return critterType;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Ant::move(Critter ***grid) {
    // for every time step, the ant randomly moves up, down,
	// left, right. If the neighboring cell in the selected direction
	// is occupied, or would move the ant off the grid, then the ant
	// stays in the current cell
	// cout << "Ant Row " << row << " Col " << col << endl;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Ant::setCritterMoved(bool moved) {
	critterMoved = moved;
}

/*********************************************************************
** Description:     description
*********************************************************************/
bool Ant::getCritterMoved() {
	return critterMoved;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Ant::breed() {
	// if an ant survives for three time steps, at the end of the time
	// steps (after moving) the ant will breed by creating a new ant
	// in an adjacent cell that is empty randomly
}
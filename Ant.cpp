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
Ant::Ant(int row, int col) : Critter{"O", row, col}
{
	// this is being used for debugging
	static int num = 1;
	cout << "Ant #" << num << " created on Board[" << row << "][" << col << "]" << endl;
	num++;
}

/*********************************************************************
** Description:     destructor
*********************************************************************/
Ant::~Ant() {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
string Ant::getCritterType() {
	return critterType;
}

/*********************************************************************
** Description:     destructor
*********************************************************************/
void Ant::move() {

}

/*********************************************************************
** Description:     destructor
*********************************************************************/
void Ant::breed() {

}
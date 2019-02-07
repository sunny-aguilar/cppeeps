/*********************************************************************
** Program name:    Critter.hpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Critter class description here
*********************************************************************/
#include "Critter.hpp"

#include <iostream>

/*********************************************************************
** Description:     no-args default constructor
*********************************************************************/
Critter::Critter() {}

/*********************************************************************
** Description:     two-arg default constructor
*********************************************************************/
Critter::Critter(string type, int row, int col) :
	critterType{type},
	stepsSurvived{0},
	critterBred{false},
	readyToBreed{false},
	critterMoved{false},
	row{row},
	col{col} {}

/***************************************************************************
** Description:     destructor
***************************************************************************/

Critter::~Critter() {

}

int Critter::getRow() { return row; }
int Critter::getCol() { return col; }
void Critter::setRow(int row) { this->row = row; }
void Critter::setCol(int col) { this->col = col; }

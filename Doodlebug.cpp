/*********************************************************************
** Program name:    Doodlebug.hpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Doodlebug class description here
*********************************************************************/
#include "Doodlebug.hpp"

/*********************************************************************
** Description:     no-args default constructor with base class
** 					initialization list
*********************************************************************/
Doodlebug::Doodlebug() : Critter{}
{
	// this is being used for debugging
	static int num = 1;
	cout << "Doodlebug #" << num << " created!" << endl;
	num++;
}

/*********************************************************************
** Description:     destructor
*********************************************************************/
Doodlebug::~Doodlebug() {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
void Doodlebug::move() {

}

/*********************************************************************
** Description:     destructor
*********************************************************************/
void Doodlebug::breed() {

}
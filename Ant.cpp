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
Ant::Ant()
{
	// this is being used for debugging
	static int num = 1;
	cout << "Ant #" << num << " created!" << endl;
	num++;
}

/*********************************************************************
** Description:     destructor
*********************************************************************/
Ant::~Ant() {}
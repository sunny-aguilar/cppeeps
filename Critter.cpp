/*********************************************************************
** Program name:    Critter.hpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Critter class description here
*********************************************************************/
#include "Critter.hpp"

/*********************************************************************
** Description:     no-args default constructor
*********************************************************************/
Critter::Critter() {}

/*********************************************************************
** Description:     two-arg default constructor
*********************************************************************/
Critter::Critter(int row, int col) : row{row}, col{col} {}

/***************************************************************************
** Description:     destructor
***************************************************************************/

Critter::~Critter()
{

}


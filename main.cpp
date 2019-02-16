/*********************************************************************
** Program name:    main.cpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Util functions can be used in multiple places
*********************************************************************/
#include <iostream>

#include "Game.hpp"
using std::cout;
using std::cin;
using std::endl;

int main() {
    Game game;                  // create game object
    game.playGame();            // start simulation
    return 0;
}
/*********************************************************************
** Program name:    main.cpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Util functions can be used in multiple places
*********************************************************************/
#include <iostream>

#include "Game.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"

using std::cout;
using std::endl;

int main() {
    auto seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);                // random number generator
    Game game;
    game.playGame();

    Ant ant;
    Doodlebug doodlebug;
    return 0;
}
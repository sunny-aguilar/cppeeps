/*********************************************************************
** Program name: 		Game.hpp
** Author: 				Kuljot Biring, Rachel Schlick, Ryan Gross,
** 						Sandro Aguilar, Jeesoo Ryoo
** Date: 				02/17/2019
** Description: 		Game class description here
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "Menu.hpp"
#include "utils.hpp"
#include "Critter.hpp"
#include <ctime>

class Game {
private:
    Menu menu;
    Critter **board;
    Critter critter;
    bool playAgain;
    int rows;
    int col;
    int doodlebugQty;
    int antQty;
    int maxCritters;
    int steps;

public:
    Game();
    ~Game();
    void playGame();
    void setCritters();
    void initializeCritters();
    void moveCritters();
    bool goAgain();
};

#endif //GAME_HPP
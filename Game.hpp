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
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include "utils.hpp"
#include <ctime>

enum Move {NONE, NORTH, EAST, SOUTH, WEST};

class Game {
private:
    Menu menu;
    Critter ***board;
    Move move;
    bool playAgain;
    int row;
    int col;
    int doodlebugQty;
    int antQty;
    int totalCritters;
    int maxCritters;
    int steps;

public:
    Game();
    ~Game();
    void playGame();
    void setCritters();
    void initializeCritters();
    void nonrandomPlacement();
    void critterRandomPlacement();
    void critterActivities(int cstep);
    void eatAnts();
    void moveDoodlebugs();
    void moveAnts();
    void moveCritters(string critterType);
    void spawnDoodlebugs();
    void spawnAnts();
    void displayBoard(int cStep = 0);
    bool goAgain();
};

#endif //GAME_HPP
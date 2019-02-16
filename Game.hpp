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
    bool playAgain;
    int row;
    int col;
    int doodlebugQty;
    int antQty;
    int totalCritters;
    int maxCritters;
    int steps;

    // TODO: REMOVE THIS VARIABLE BEFORE SUBMIT
    int isDebugMode;

public:
    Game();
    ~Game();
    void playGame();
    void setCritters(int);
    void initializeCritters();
    void critterRandomPlacement();
    void critterActivities(int cstep);
    int moveDoodlebugs();
    int starvedDoodlebugs(); 
    void moveAnts();
    int moveCritters(string critterType);
    int spawnDoodlebugs();
    int spawnAnts();
    void displayBoard(int cStep = 0, int antsEaten = 0, int newDoodles = 0, int newAnts = 0, int starvedDoodles = 0); // <-- CHANGED
    bool goAgain();
	int getDoodleQty(); // <-- ADDED
	void setDoodleQty(int); // <-- ADDED
	int getAntQty(); // <--ADDED 
	void setAntQty(int); // <-- ADDED
};

#endif //GAME_HPP

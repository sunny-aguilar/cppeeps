/*********************************************************************
** Author: 				Kuljot Biring, Rachel Schlick, Ryan Gross,
** 						Sandro Aguilar, Jeesoo Ryoo
** Date: 				02/17/2019
** Description: 		Header file for game class
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "Menu.hpp"
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include "utils.hpp"
#include <ctime>

enum Move
{
    NONE,
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Game
{
  private:
    const std::string INVALID_SELECTION_PROMPT = "Unable to determine selection";
    const std::string KEEP_PLAYING_PROMPT = "Unable to determine whether to keep playing!\n";
    const std::string EXCEEDS_GRID_SIZE_PROMPT = "\nERROR! - YOU CAN ONLY ENTER A MAX OF ";
    const std::string ANTS_DOODLEBUGS_PROMPT = " ANTS AND DOODLEBUGS!";
    const std::string ANTS_ENTERED_PROMPT = " - Ants entered ";
    const std::string DOODLEBUGS_ENTERED_PROMPT = " - Doodlebugs entered";
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
    int getDoodleQty();
    void setDoodleQty(int);
    int getAntQty();
    void setAntQty(int);
};
#endif

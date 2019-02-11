/*********************************************************************
** Program name: 		Menu.hpp
** Author: 				Kuljot Biring, Rachel Schlick, Ryan Gross,
** 						Sandro Aguilar, Jeesoo Ryoo
** Date: 				02/17/2019
** Description:         Menu class description here
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::string;
using std::setw;

class Menu
{
private:
    bool numVerify;
    string userInput;
    int startQuitChoice;
    int selection;
    int boardSize;
    int numAnts;
    int numDoodleBugs;
    int critterSteps;
    int continueStopChoice;

public:
    Menu();
    int inputValidator(int min, int max);
    void startMenu();
    void setStartQuitChoice(int startQuitChoice);
    int getStartQuitChoice();
    void boardSizeMenu(int row, int col);
    void setBoardSize(int boardSize);
    int getBoardSize();
    void numAntsMenu(int min, int max);
    void setNumAnts(int numAnts);
    int getNumAnts();
    void numDoodleBugsMenu(int min, int max);
    void menuRandomPlacement();
    void setNumDoodleBugs(int numDoodleBugs);
    int getNumDoodleBugs();
    void critterStepsPrompt();
    void setCritterSteps(int critterSteps);
    int getCritterSteps();
    void menuDisplayBoard(int col=0, int cStep=0, int doodleCt=0, int antCt=0, int antsEaten=0, int newDoodles=0, int newAnts=0, int starvedDoodles=0);
    void menuPlayAgain();
    void menuExitGameMessage();
    void setContinueStopChoice(int continueStopChoice);
    int getContinueStopChoice();

    // TODO: REMOVE DEBUG MODE BEFORE SUBMIT
    void menuDebugMode();
};

#endif //MENU_HPP

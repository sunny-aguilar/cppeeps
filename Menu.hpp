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
    void boardSizeMenu();
    void setBoardSize(int boardSize);
    int getBoardSize();
    void numAntsMenu();
    void setNumAnts(int numAnts);
    int getNumAnts();
    void numDoodleBugsMenu();
    void setNumDoodleBugs(int numDoodleBugs);
    int getNumDoodleBugs();
    void critterStepsPrompt();
    void setCritterSteps(int critterSteps);
    int getCritterSteps();
    void menuDisplayBoard(int col);
    void menuPlayAgain();
    void menuExitGameMessage();
    void setContinueStopChoice(int continueStopChoice);
    int getContinueStopChoice();
};

#endif //MENU_HPP

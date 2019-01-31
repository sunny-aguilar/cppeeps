/*********************************************************************
** Program name: 		Menu.hpp
** Author: 				Kuljot Biring, Rachel Schlick, Ryan Gross,
** 						Sandro Aguilar, Jeesoo Ryoo
** Date: 				02/17/2019
** Description: 		Util functions can be used in multiple places
*********************************************************************/
#ifndef GROUPPROJECT_MENU_HPP
#define GROUPPROJECT_MENU_HPP

#include <string>

using std::string;

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
    void startQuitMenu();
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
    void continueStopMenu();
    void setContinueStopChoice(int continueStopChoice);
    int getContinueStopChoice();

};


#endif //GROUPPROJECT_MENU_HPP

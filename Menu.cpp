/*********************************************************************
** Program name:    Menu.cpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Meny class description here
*********************************************************************/
#include "Menu.hpp"
// this is how the menus are displayed and input is validated
// startQuitMenu(); <-- menu prompts user
// setStartQuitChoice(inputValidator(1,2)) <-- returns a validated value

/***************************************************************************
** Description:     default constructor using initialization list
***************************************************************************/
Menu::Menu() :
    numVerify{true},
    userInput{},
    startQuitChoice{0},
    selection{0},
    boardSize{0},
    numAnts{0},
    numDoodleBugs{0},
    critterSteps{0},
    continueStopChoice{0} {
}

/***************************************************************************
** Description:     prompt user to start or quit game
***************************************************************************/
void Menu::startMenu()
{
    cout << "\nWELCOME TO THE PREDATOR-PREY SIMULATION\n\n";
    cout << "Please enter a choice listed below\n";
    cout << "1. Play Game\n";
    cout << "2. Exit Game\n";
    cout << ">> ";
}

/***************************************************************************
** Description:     mutator function set play or quit choice option
***************************************************************************/
void Menu::setStartQuitChoice(int startQuitChoice)
{
    this->startQuitChoice = startQuitChoice;
}

/***************************************************************************
** Description:   accessor function get play or quit choice option
***************************************************************************/
int Menu::getStartQuitChoice()
{
    return startQuitChoice;
}

/***************************************************************************
** Description:     prompt user to for board size
***************************************************************************/
void Menu::boardSizeMenu()
{
    cout << "\nBOARD SIZE\n";
    cout << "Please enter the size of the game board \n";
    cout << "Enter the length and width of the board from 20 - 100 only\n";
    cout << ">> ";
}

/***************************************************************************
** Description:     mutator function set length and width of board
***************************************************************************/
void Menu::setBoardSize(int boardSize)
{
    this->boardSize = boardSize;
}

/***************************************************************************
** Description:   accessor function get size of board
***************************************************************************/
int Menu::getBoardSize()
{
    return boardSize;
}

/***************************************************************************
** Description:     EXTRA CREDIT: prompt user for number of ants
***************************************************************************/
void Menu::numAntsMenu()
{
    cout << "\nANTS\n";
    cout << "Enter the number of ants you would like to have\n";
    cout << "Enter the number of ants from  100 - 500 only\n";
    cout << ">> ";
}

/***************************************************************************
** Description:     EXTRA CREDIT: mutator function set length number of ants
***************************************************************************/
void Menu::setNumAnts(int numAnts)
{
    this->numAnts = numAnts;
}

/***************************************************************************
** Description:   EXTRA CREDIT: accessor function get number of ants
***************************************************************************/
int Menu::getNumAnts()
{
    return numAnts;
}

/***************************************************************************
** Description:     EXTRA CREDIT: prompt user for number of doodlebugs
***************************************************************************/
void Menu::numDoodleBugsMenu()
{
    cout << "\nDOODLEBUGS\n";
    cout << "Enter the number of doodlebugs you would like to have\n";
    cout << "Enter the number of ants from  5 - 100 only\n";
    cout << ">> ";
}

/***************************************************************************
** Description:  description
***************************************************************************/
void Menu::menuRandomPlacement() {
    cout << "\nAnts and Doodlebugs have been randomly placed on the board\n";
}

/***************************************************************************
** Description:  EXTRA CREDIT: mutator function set length number of doodlebugs
***************************************************************************/
void Menu::setNumDoodleBugs(int numDoodleBugs)
{
    this->numDoodleBugs = numDoodleBugs;
}

/***************************************************************************
** Description:  EXTRA CREDIT: accessor function get number of doodlebugs
***************************************************************************/
int Menu::getNumDoodleBugs()
{
    return numDoodleBugs;
}

/*********************************************************************
** Description:  Ant steps prompt for total board movement
*********************************************************************/
void Menu::critterStepsPrompt()
{
    cout << "\nSTEPS\n";
    cout << "Enter the total number of steps the ant should walk from 1 through 20000 only" << endl;
}

/***************************************************************************
** Description:  EXTRA CREDIT: mutator function set length number of doodlebugs
***************************************************************************/
void Menu::setCritterSteps(int critterSteps)
{
    this->critterSteps = critterSteps;
}

/*********************************************************************
** Description:     get total ant steps on the board
*********************************************************************/
int Menu::getCritterSteps()
{
    return critterSteps;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Menu::menuDisplayBoard(int col) {
    cout << "\nDISPLAYING BOARD ";
    for (int count = 0; count < col; count++) {
        cout << "* ";
    }
    cout << endl;
}

/***************************************************************************
** Description:   prompt user to continue or quit game
***************************************************************************/
void Menu::menuPlayAgain()
{
    cout << "\nWould you like to run the simulation again using using"
            "a different number of steps?\n";
    cout << "Please enter a choice listed below\n";
    cout << "1. Changes Step count and rerun Simulation\n";
    cout << "2. Quit Simulation\n";
}

/***************************************************************************
** Description:   prompt user to continue or quit game
***************************************************************************/
void Menu::menuExitGameMessage() {
    cout << "\nNow exiting the predator-prey simulation" << endl;
}

/***************************************************************************
** Description:   mutator function set continue or quit choice option
***************************************************************************/
void Menu::setContinueStopChoice(int continueStopChoice)
{
    this->continueStopChoice = continueStopChoice;
}

/***************************************************************************
** Description:   accessor function get continue or quit choice option
***************************************************************************/
int Menu::getContinueStopChoice()
{
    return continueStopChoice;
}

/****************************************************************************
** Description: generic input validation that checks if the input is
** numerical. If not the bool flag is set to false. Otherwise a stringstream
** object is created and that is inserted into an integer variable. The
** function then checks if the flag was true and if the input is within
** the min and max ranges passed to it. The do while checks if these
** three conditions are violated and if so jumps back to the top of the
** loop resetting the bool flag to true.
****************************************************************************/
int Menu::inputValidator(int min, int max)
{
    do
    {
        numVerify = true; // reset bool value when loop repeats
        cin.clear();      // clear buffer
//        cout << "Please enter a number from " << min << " to " << max << endl;
        getline(cin, userInput);

        for (unsigned int numCheck = 0; numCheck < userInput.length(); numCheck++)
        {
            if (!isdigit(userInput[numCheck]))  // if entry is not a number
            {
                numVerify = false;  // set boolean to false
            }
        }

        if (numVerify)  // if boolean value still true
        {
            stringstream sstream(userInput);   // create string stream object
            sstream >> selection;  // put string into integer
        }
        // if number is out of range of acceptable values
        if(!numVerify || selection < min || selection > max)
        {
            cout << "Invalid entry! You must choose number from " << min << " to " << max << endl << endl;
        }

    } while (!numVerify || selection < min || selection > max);

    return selection;
}
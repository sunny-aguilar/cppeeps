//
// Created by Kuljot Singh Biring on 2019-01-30.
//

#include "Menu.hpp"

#include <iostream>
#include <sstream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::stringstream;


/***************************************************************************
** Description:     prompt user to start or quit game
***************************************************************************/

void Menu::startQuitMenu()
{
    cout << "Welcome to Predator-Prey Game \n";
    cout << "Please enter a choice listed below\n";
    cout << "1. Play Game\n";
    cout << "2. Exit Game\n";
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
        cout << "Please enter a number from " << min << " to " << max << endl;
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
            stringstream stringstream(userInput);   // create string stream object
            stringstream >> selection;  // put string into integer
        }
        // if number is out of range of acceptable values
        if(!numVerify || selection < min || selection > max)
        {
            cout << "Invalid entry! You must choose number from " << min << " to " << max << endl << endl;
        }

    } while (!numVerify || selection < min || selection > max);

    return selection;
}
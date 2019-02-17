/*********************************************************************
** Program Name:    Predator vs. Prey
** Class Name:      Menu
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Class implementation file for Menu class.
*********************************************************************/
#include "Menu.hpp"

/***************************************************************************
** Description: Default Constructor; sets default values for number 
**              verification, user input, and user selection.
***************************************************************************/
Menu::Menu() : numVerify{true},
               userInput{},
               selection{0}
{
}

/***************************************************************************
** Name:        startMenu
** Description: Void method that prompts user to start or exit game.
***************************************************************************/
void Menu::startMenu()
{
    printWelcomeScreen();
    cout << USER_CHOICE_PROMPT;
    cout << RUN_PROMPT;
    cout << EXIT_PROMPT;
    cout << ">> ";
}

/***************************************************************************
** Name:        boardRowSizeMenu
** Description: Void method that prompts user for # of board rows.
***************************************************************************/
void Menu::boardRowSizeMenu(int min, int max)
{
    cout << EC_ROW_SIZE_PROMPT;
    cout << ROW_RANGE_PROMPT;
    cout << BOARD_LENGTH_PROMPT << min << " - " << max << " only\n";
    cout << ">> ";
}

/***************************************************************************
** Name:        boardColSizeMenu
** Description: Void method that prompts user for # of board columns.
***************************************************************************/
void Menu::boardColSizeMenu(int min, int max)
{
    cout << EC_COL_SIZE_PROMPT;
    cout << COL_RANGE_PROMPT;
    cout << BOARD_WIDTH_PROMPT << min << " - " << max << " only\n";
    cout << ">> ";
}

/***************************************************************************
** Name:        numAntsMenu
** Description: Void method that prompts user for # of ants.
***************************************************************************/
void Menu::numAntsMenu(int min, int max)
{
    cout << EC_NUM_OF_ANTS_PROMPT;
    cout << ANT_USER_INPUT_PROMPT;
    cout << ANT_RANGE_PROMPT << min << " - " << max << " only\n";
    cout << ">> ";
}

/***************************************************************************
** Name:        numDoodlebugsMenu
** Description: Void method that prompts user for # of doodlebugs.
***************************************************************************/
void Menu::numDoodleBugsMenu(int min, int max)
{
    cout << EC_NUM_OF_DOODLEBUGS_PROMPT;
    cout << DOODLEBUG_USER_INPUT_PROMPT;
    cout << DOODLEBUG_RANGE_PROMPT << min << " - " << max << " only\n";
    cout << ">> ";
}

/***************************************************************************
** Name:        menuRandomPlacement
** Description: Void method that outputs that critters have been placed
**              to console.
***************************************************************************/
void Menu::menuRandomPlacement()
{
    cout << CRITTER_PLACEMENT_NOTIFICATION;
}

/*********************************************************************
** Name:        critterStepsPrompt
** Description: Void method that prompts user for # of steps ants 
**              should take.
*********************************************************************/
void Menu::critterStepsPrompt()
{
    cout << EC_ANT_STEPS_PROMPT;
    cout << ANT_STEPS_USER_INPUT_PROMPT << endl;
}

/*********************************************************************
** Name:        menuDisplayBoard
** Description: Void method that displays the current board state
**              along w/ stats for current step, # of critters eaten, 
**              bred, etc.
*********************************************************************/
void Menu::menuDisplayBoard(int col, int cStep, int doodleCt, int antCt, int antsEaten, int newDoodles, int newAnts, int starvedDoodles)
{
    int displayWidth = 30;
    for (int count = 0; count < displayWidth; count++)
    {
        cout << "__";
    }
    cout << endl;
    cout << std::right << "\n"
         << setw(40) << CURRENT_STATS_NOTIFICATION << endl;
    for (int count = 0; count < displayWidth; count++)
    {
        cout << "__";
    }
    cout << "\n"
         << endl;
    cout << std::left << setw(30) << CURRENT_STEPS_TAKEN_NOTIFICATION << cStep << endl;
    cout << std::left << setw(30) << ANT_AMT_NOTIFICATION << antCt << endl;
    cout << std::left << setw(30) << DOODLEBUG_AMT_NOTIFICATION << doodleCt << endl;
    cout << std::left << setw(30) << ANTS_EATEN_NOTIFICATION << antsEaten << endl;
    cout << std::left << setw(30) << ANTS_BRED_NOTIFICATION << newAnts << endl;
    cout << std::left << setw(30) << DOODLEBUGS_BRED_NOTIFICATION << newDoodles << endl;
    cout << std::left << setw(30) << DOODLEBUGS_STARVED_NOTIFICATION << starvedDoodles << endl;
    cout << endl;
    for (int count = 0; count < displayWidth; count++)
    {
        cout << "__";
    }
    cout << endl;
}

/***************************************************************************
** Name:        menuPlayAgain
** Description: Void method used to ask user if he/she wants to
**              play another round or quit the game.
***************************************************************************/
void Menu::menuPlayAgain()
{
    cout << GAME_RERUN_PROMPT;
    cout << ENTER_CHOICE_PROMPT;
    cout << RERUN_SELECTION;
    cout << QUIT_SELECTION;
}

/***************************************************************************
** Name:        menuExitGameMessage
** Description: Void method used to notify user of game termination.
***************************************************************************/
void Menu::menuExitGameMessage()
{
    cout << EXITING_PROMPT << endl;
}

/****************************************************************************
** Name:        inputValidator
** Description: Input validation method that takes in two ints (min/max range).
**              Iterative loops until value is entered that is within range. 
**              Returns an int.
****************************************************************************/
int Menu::inputValidator(int min, int max)
{
    do
    {
        numVerify = true;

        getline(cin, userInput);

        for (unsigned int numCheck = 0; numCheck < userInput.length(); numCheck++)
        {
            if (!isdigit(userInput[numCheck]))
            {
                numVerify = false;
            }
        }
        if (userInput.length() == 0)
        {
            numVerify = false;
        }

        if (numVerify)
        {
            stringstream sstream(userInput);
            sstream >> selection;
        }

        if (!numVerify || selection < min || selection > max)
        {
            cout << INVALID_ENTRY_PROMPT << min << " to " << max << ": ";
        }

    } while (!numVerify || selection < min || selection > max);
    cin.clear();

    return selection;
}

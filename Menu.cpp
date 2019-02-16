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
    selection{0} {
}

/***************************************************************************
** Description:     prompt user to start or quit game
***************************************************************************/
void Menu::startMenu()
{
    cout << "\n\n\n"
    << "###################################################################################################\n"
    << "#                                                                                                 #\n"
    << "#      WELCOME TO THE PREDATOR-PREY SIMULATION !!                                                 #\n"
    << "#      By:   Sandro Aguilar, Kuljot Biring,                                                       #\n"
    << "#            Ryan Gross, Jeesoo Ryoo, Rachel Schlick                                              #\n"
    << "#                                                                                                 #\n"
    << "#                                                                            ,_   _,              #\n"
    << "#      ________               _________        _____                          '._.'               #\n"
    << "#      ___  __ \\_____________ ______  /______ ___  /_______ ________     '-,   (_)   ,-'          #\n"
    << "#      __  /_/ /__  ___/_  _ \\_  __  / _  __ `/_  __/_  __ \\__  ___/       '._ .:. _.'            #\n"
    << "#      _  ____/ _  /    /  __// /_/ /  / /_/ / / /_  / /_/ /_  /            _ '|Y|' _             #\n"
    << "#      /_/      /_/     \\___/ \\__,_/   \\__,_/  \\__/  \\____/ /_/           ,` `>\\ /<` `,           #\n"
    << "#                                                                        ` ,-`  I  `-, `          #\n"
    << "#      \\       /                             _   __ ____                   |   /=\\   |            #\n"
    << "#       \\     /                             | | / // __/                 ,-'   |=|   '-,          #\n"
    << "#        \\.-./                              | |/ /_\\ \\                         )-(                #\n"
    << "#        (o\\^/o)  _   _   _     __          |___//___/                         \\_/                #\n"
    << "#         ./ \\.\\ ( )-( )-( ) .-'  '-.                      ________                               #\n"
    << "#          {-} \\(//  ||   \\\\/ (   )) '-.                   ___  __ \\_____________ _____  __       #\n"
    << "#            //-__||__.-\\\\.      _.-'                      __  /_/ /__  ___/_  _ \\__  / / /       #\n"
    << "#            (/    ()     \\)'-._.-'                        _  ____/ _  /    /  __/_  /_/ /        #\n"
    << "#           ||    ||      \\\\                               /_/      /_/     \\___/ _\\__, /         #\n"
    << "#           ('    ('       ')                                                     /____/          #\n"
    << "#                                                                                                 #\n"
    << "#                                                                                                 #\n"
    << "#      [Extra Credit]                                                                             #\n"
    << "#      * The size of the grid rows and columns                                                    #\n"
    << "#      * The number of ants                                                                       #\n"
    << "#      * The number of doodlebugs                                                                 #\n"
    << "#                                                                                                 #\n"
    << "###################################################################################################\n\n";
    cout << "Please enter a choice listed below\n";
    cout << "1. Run Simulation\n";
    cout << "2. Exit Simulation\n";
    cout << ">> ";
}

/***************************************************************************
** Description:     prompt user to for row size
***************************************************************************/
void Menu::boardRowSizeMenu(int min, int max)
{
    cout << "\n[Extra Credit] ROW SIZE\n";
    cout << "Please enter the number of rows for the game board \n";
    cout << "Enter the length of the board from " << min << " - " << max << " only\n";
    cout << ">> ";
}

/***************************************************************************
** Description:     prompt user to for column size
***************************************************************************/
void Menu::boardColSizeMenu(int min, int max)
{
    cout << "\n[Extra Credit] COLUMN SIZE\n";
    cout << "Please enter the number of columns for the game board \n";
    cout << "Enter the width of the board from " << min << " - " << max << " only\n";
    cout << ">> ";
}

/***************************************************************************
** Description:     EXTRA CREDIT: prompt user for number of ants
***************************************************************************/
void Menu::numAntsMenu(int min, int max)
{
    cout << "\n[Extra Credit] ANTS\n";
    cout << "Enter the number of ants you would like to have\n";
    cout << "Enter the number of ants from " << min << " - " << max << " only\n";
    cout << ">> ";
}

/***************************************************************************
** Description:     EXTRA CREDIT: prompt user for number of doodlebugs
***************************************************************************/
void Menu::numDoodleBugsMenu(int min, int max)
{
    cout << "\n[Extra Credit] DOODLEBUGS\n";
    cout << "Enter the number of doodlebugs you would like to have\n";
    cout << "Enter the number of doodlebugs from " << min << " - " << max << " only\n";
    cout << ">> ";
}

/***************************************************************************
** Description:  description
***************************************************************************/
void Menu::menuRandomPlacement() {
    cout << "\nAnts and Doodlebugs have been randomly placed on the board\n";
}

/*********************************************************************
** Description:  Ant steps prompt for total board movement
*********************************************************************/
void Menu::critterStepsPrompt()
{
    cout << "\nSTEPS\n";
    cout << "Enter the total number of steps the ant should walk from 1 through 20000 only" << endl;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Menu::menuDisplayBoard(int col, int cStep, int doodleCt, int antCt, int antsEaten, int newDoodles, int newAnts, int starvedDoodles) {
    cout << "\nCURRENT STATS" << endl;
    for (int count = 0; count < col; count++) {
        cout << "* ";
    }
    cout << endl;
    cout << std::left << setw(30) << "Current steps taken: " << cStep << endl;
	cout << std::left << setw(30) << "Ants on board: " << antCt << endl;
	cout << std::left << setw(30) <<"Doodlebugs on board: " << doodleCt << endl;
	cout << std::left << setw(30) <<"Ants eaten this step: " << antsEaten << endl;
	cout << std::left << setw(30) <<"Ants bred this step: " << newAnts << endl;
	cout << std::left << setw(30) <<"Doodlebugs bred this step: " << newDoodles << endl;
	cout << std::left << setw(30) <<"Doodlebugs starved this step: " << starvedDoodles << endl;
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
    cout << "\nWould you like to run the simulation again using "
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

        getline(cin, userInput);

        for (unsigned int numCheck = 0; numCheck < userInput.length(); numCheck++)
        {
            if (!isdigit(userInput[numCheck]))  // if entry is not a number
            {
                numVerify = false;  // set boolean to false
            }
        }
        if (userInput.length() == 0)
        {
            numVerify = false; // do not accept no entry
        }

        if (numVerify)  // if boolean value still true
        {
            stringstream sstream(userInput);   // create string stream object
            sstream >> selection;  // put string into integer
        }
        // if number is out of range of acceptable values
        if(!numVerify || selection < min || selection > max)
        {
            cout << "Invalid entry! You must choose number from " << min << " to " << max << ": ";
        }

    } while (!numVerify || selection < min || selection > max);
    cin.clear();      // clear buffer
    
    return selection;
}
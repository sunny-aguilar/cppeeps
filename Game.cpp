/*********************************************************************
** Program name: 		Game.cpp
** Author: 				Kuljot Biring, Rachel Schlick, Ryan Gross,
** 						Sandro Aguilar, Jeesoo Ryoo
** Date: 				02/17/2019
** Description: 		Game class description here
*********************************************************************/
#include "Game.hpp"

/***************************************************************************
** Description:     default constructor using initialization list
***************************************************************************/
Game::Game() :
    board{nullptr},
    playAgain{true},
    rows{0},
    col{0},
    doodlebugQty{0},
    antQty{0},
    steps{0} {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
Game::~Game() {}

/*********************************************************************
** Description:     description here
*********************************************************************/
void Game::playGame() {
    // display start menu
    menu.startMenu();
    switch (menu.inputValidator(1,2)) {
        case 1:
            do {
                // set game parameters
                // set board rows and columns
                menu.boardSizeMenu();
                rows = col = menu.inputValidator(20, 100);
                maxCritters = rows * col;

                // make sure that total critters entered
                // by user does not exceed board space
                setCritters();

                // board set-up
                initializeCritters();

                // set total steps to simulate
                menu.critterStepsPrompt();
                steps = menu.inputValidator(1,20000);

                // move critters
                moveCritters();

                // run simulation again
                playAgain = goAgain();
            } while (playAgain);
            break;
        case 2:
            {
                // display thanks for playing menu
                menu.menuExitGameMessage();
                playAgain = false;
            }
            break;
        default:
            cout << "Unable to determine selection" << endl;
    }
}

/*********************************************************************
** Description:     description here
*********************************************************************/
void Game::setCritters() {
    bool askAgain = true;
    do {
        // set total ants
        menu.numAntsMenu();
        antQty = menu.inputValidator(100, 1000);

        // set total doodlebugs
        menu.numDoodleBugsMenu();
        doodlebugQty = menu.inputValidator(5, 500);

        // add total critters entered by user
        int totalUserCritters = doodlebugQty + antQty;

        // compare max critters allowed with total critters
        // entered by user; ask user to pick less critters
        // if too many are chosen
        if (totalUserCritters > maxCritters) {
            cout << "\nERROR! - YOU CAN ONLY ENTER A MAX OF " << maxCritters
                 << " ANTS AND DOODLEBUGS!" << endl;
            cout << setw(4) << antQty << " - Ants entered " << endl;
            cout << setw(4) << doodlebugQty << " - Doodlebugs entered" << endl;
            askAgain = true;
        }
        else if (totalUserCritters <= maxCritters) {
            askAgain = false;
        }
    } while (askAgain);
}

/*********************************************************************
** Description:     dynamically create a board using the rows and col
**                  private variables for the dimensions
*********************************************************************/
void Game::initializeCritters() {
    // create the rows
    board = new Critter *[rows];

    // create the columns per row
    for (int index = 0; index < rows; index++) {
        board[index] = new Critter[col];
    }

    // add the doodlebugs and ants to the array



}

/*********************************************************************
** Description:     description here
*********************************************************************/
void Game::moveCritters() {
    int stepsTaken = 0;
    do {
        stepsTaken++;
        cout << "Total steps taken " << stepsTaken << endl;

        // move ants

        // spawn ants

        // move doodlebugs

        // eat ants

        // spawn doodlebugs


    } while (stepsTaken < steps);
}

/*********************************************************************
** Description:     description
*********************************************************************/
bool Game::goAgain() {
    menu.menuPlayAgain();
    int selection = menu.inputValidator(1,2);
    switch (selection) {
        case 1:
            return true;
            break;
        case 2:
            return false;
            break;
        default:
            cout << "Unable to determine whether to keep playing!\n";
    }
    // unused return value
    return false;
}



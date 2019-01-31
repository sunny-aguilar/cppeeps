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
Game::Game() : playAgain{true}, rows{0}, col{0}, steps{0} {}

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
            {
                cout << "Enter game params" << endl;
                // set game parameters
                // set board rows and columns
                menu.boardSizeMenu();
                rows = col = menu.inputValidator(20, 100);

                // set total ants

                
                // set total doodlebugs


                // set total steps to simulate
                menu.critterStepsPrompt();
                steps = menu.inputValidator(1,20000);

                // start predator-prey simulation
                while (!startSteps()) {
                    // while startDay() returns true, simulation continues
                    // if startDay() returns false, simulation ends
                }
            }
            break;
        case 2:
            {
                // display thanks for playing menu

            }
            break;
        default:
            cout << "Unable to determine selection" << endl;
    }
}

/*********************************************************************
** Description:     description here
*********************************************************************/
bool Game::startSteps() {
    do {
        cout << "Working on steps\n";

        // move ants

        // move doodle bugs



        playAgain = goAgain();
    } while (playAgain);

    // if player quits, game ends
    if (!playAgain) {
        return true;
    }
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
}



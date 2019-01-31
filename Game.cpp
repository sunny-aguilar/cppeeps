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
Game::Game() : playAgain{true} {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
Game::~Game() {}

/*********************************************************************
** Description:     description here
*********************************************************************/
void Game::playGame() {
    cout << "predator-prey simulation" << endl;

    while (!startSteps()) {
        // while startDay() returns true, simulation continues
        // if startDay() returns false, simulation ends
        cout << "Starting Steps\n";
    }

}

/*********************************************************************
** Description:     description here
*********************************************************************/
bool Game::startSteps() {
    do {
        cout << "Working on steps\n";
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



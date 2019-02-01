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
    row{0},
    col{0},
    doodlebugQty{0},
    antQty{0},
    totalCritters{0},
    steps{0} {}

/*********************************************************************
** Description:     destructor frees heap memory
*********************************************************************/
Game::~Game() {
    for (int r_index = 0; r_index < row; r_index++) {
        for (int c_index = 0; c_index < col; c_index++) {
            if (board[r_index][c_index] != nullptr) {
                delete board[r_index][c_index];
            }
        }
        delete [] board[r_index];
    }
    delete [] board;
}

/*********************************************************************
** Description:     description here
*********************************************************************/
void Game::playGame() {
    // display start menu
    menu.startMenu();
    switch (menu.inputValidator(1,2)) {
        case 1:

                // set game parameters
                // set board rows and columns
                menu.boardSizeMenu();
                row = col = menu.inputValidator(20, 100);
                maxCritters = row * col;
            do {
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
        totalCritters = totalUserCritters;

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
    board = new Critter **[row];

    // create the columns per row
    for (int index = 0; index < row; index++) {
        board[index] = new Critter *[col];
    }

    // set the pointers equal to null
    for (int r_index = 0; r_index < row; r_index++) {
        for (int c_index = 0; c_index < col; c_index++) {
            board[r_index][c_index] = nullptr;
        }
    }

    // this functions adds the critters to the board in a non-random
    // fashion (only temporary, must place them randomly)
    critterRandomPlacement();
    // nonrandomPlacement();

    // display the board
    displayBoard();
}

/*********************************************************************
** Description:     this function creates ants and doodle bug
**                  instances and adds them to the board in a
**                  a non-random fashion
*********************************************************************/
void Game::nonrandomPlacement() {
    // add the doodlebugs and ants to the array
    // NOTE! - need to place them randomly on board
    int rows = 0;
    int cols = 0;
    int antsAdded = 0;
    int doodlesAdded = 0;

    for (rows; rows < row; rows++) {
        for (cols = 0; cols < col; cols++) {
            // create a ant and pass in row and col location
            board[rows][cols] = new Ant(rows, cols);
            antsAdded++;
            if (antsAdded == antQty) { break; }
        }
        if (antsAdded == antQty) { break; }
    }
    cout << "Row value " << rows << endl;
    cout << "Col value " << cols << endl;
    rows++;

    for (rows; rows < row; rows++) {
        for (cols = 0; cols < col; cols++) {
            // create a doodlebug and pass in row and col location
            board[rows][cols] = new Doodlebug(rows, cols);
            doodlesAdded++;
            if (doodlesAdded == doodlebugQty) { break; }
        }
        if (doodlesAdded == doodlebugQty) { break; }
    }
}

/*********************************************************************
** Description:     creates doodlebugs and ants and randomly places
**                  them on the board
*********************************************************************/
void Game::critterRandomPlacement() {
    menu.menuRandomPlacement();

    int r_index = 0;
    int c_index = 0;

    for (int ant = 0; ant < antQty; ant++) {
        do {
            // create random row and col num using util.cpp
            r_index = generateRandomNumber(0, row-1);
            c_index = generateRandomNumber(0, col-1);
        } while (board[r_index][c_index] != nullptr);
        board[r_index][c_index] = new Ant(r_index, c_index);
    }

    for (int doodlebug = 0; doodlebug < doodlebugQty; doodlebug++) {
        do {
            // create random row and col num using util.cpp
            r_index = generateRandomNumber(0, row-1);
            c_index = generateRandomNumber(0, col-1);
        } while (board[r_index][c_index] != nullptr);
        board[r_index][c_index] = new Doodlebug(r_index, c_index);
    }
}

/*********************************************************************
** Description:     description here
*********************************************************************/
void Game::moveCritters() {
    int stepsTaken = 0;
    do {
        stepsTaken++;
        cout << "Total steps taken " << stepsTaken << endl;

        // eat ants


        // move doodlebugs


        // spawn doodlebugs


        // move ants


        // spawn ants



    } while (stepsTaken < steps);
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Game::displayBoard() {
    menu.menuDisplayBoard(col);

    // built top wall
    for (int index = 0; index < row; index++) {
        cout << "__";
    }
    cout << endl;

    // build board
    for (int r_index = 0; r_index < row; r_index++) {
        cout << "|"; // build left wall
        for (int c_index = 0; c_index < col; c_index++) {
            if (board[r_index][c_index] != nullptr) {
                if (board[r_index][c_index]->getCritterType() == "X") {
                    cout << "X|";
                }
                else if (board[r_index][c_index]->getCritterType() == "O") {
                    cout << "O|";
                }
            }
            else {
                cout << " |"; // build right wall
            }
        }
        cout << endl;
    }

    // build bottom wall
    for (int index = 0; index < row; index++) {
        cout << "--";
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
    // unused return value
    return false;
}



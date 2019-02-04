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

            // make sure that total critters entered
            // by user does not exceed board space
            setCritters();

            // board set-up
            initializeCritters();

            // repeat simulation; only change steps
            do {
                // set total steps to simulate
                menu.critterStepsPrompt();
                steps = menu.inputValidator(1,20000);

                // perform critter activities (move, eat, spawn)
                critterActivities();

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

    // display the initial board
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
void Game::critterActivities() {
    int stepsTaken = 0;
    do {
        stepsTaken++;
        cout << "Total steps taken " << stepsTaken << endl;

        // eat ants


        // move doodlebugs
        moveDoodlebugs();

        // spawn doodlebugs
        spawnDoodlebugs();

        // move ants
        moveAnts();

        // spawn ants
        spawnAnts();

        // display updated board
        displayBoard();


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
** Description:     description here
*********************************************************************/
void Game::eatAnts() {
    cout << "Doodlebugs are eating the ants" << endl;
}

/*********************************************************************
** Description:     this function iterates through the board to find
**                  all of the doodlebugs. Implement PACMAN style.
*********************************************************************/
void Game::moveDoodlebugs() {
    cout << "Moving doodlebugs" << endl;
    moveCritters("X");
}

/*********************************************************************
** Description:     this function iterates through the board to find
**                  all of the ants.
*********************************************************************/
void Game::moveAnts() {
    cout << "Moving ants" << endl;
    moveCritters("O");
//    for (int r_index = 0; r_index < row; r_index++) {
//        for (int c_index = 0; c_index < col; c_index++) {
//            if (board[r_index][c_index] != nullptr) {
//                if (board[r_index][c_index]->getCritterType() == "O") {
//                    board[r_index][c_index]->move();
//                }
//            }
//        }
//    }
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Game::moveCritters(string critterType) {
    string critter;
    if (critterType == "X") {
        critter = "Doodlebug";
    }
    else if (critterType == "O") {
        critter = "Ant";
    }


    int direction;
    direction = generateRandomNumber(1,4);
    switch (direction) {
        case 1:
            cout << critter << " randomly selected to go NORTH\n";
            break;
        case 2:
            cout << critter << " randomly selected to go EAST\n";
            break;
        case 3:
            cout << critter << " randomly selected to go SOUTH\n";
            break;
        case 4:
            cout << critter << " randomly selected to go WEST\n";
            break;
        default:
            cout << "Unable to get direction to move to!\n";
    }

    // move doodlebug
    for (int r_index = 0; r_index < row; r_index++) {
        for (int c_index = 0; c_index < col; c_index++) {
            if (board[r_index][c_index] != nullptr) {
                if (board[r_index][c_index]->getCritterType() == critterType) {

                    // check adjacent squares and randomly pick one
                    // movePickRandomSpace();

                    // use switch statement to select which direction to go
                    switch (direction) {
                        case 1: // get NORTH square
                        {
                            if ( (r_index - 1) < 0 ) {  // if out of bounds NORTH wall
                                if (board[row - 1][c_index] == nullptr) {   // go to last row
                                    //cout << "Move NORTH available, " << "Move to [" << row - 1 << "][" << c_index << "]" << endl;

                                    // check if critter has already moved during time step
                                    if (board[r_index][c_index]->getCritterMoved()) {
                                        // if critter already moved, do not move it again
                                    }
                                    else {
                                        // set critter moved bool in Doodlebug to true
                                        board[r_index][c_index]->setCritterMoved(true);

                                        // move doodlebug
                                        board[row-1][c_index] = board[r_index][c_index];

                                        // set old pointer to null
                                        board[r_index][c_index] = nullptr;
                                    }
                                }
                                else {
                                    //cout << "Move NORTH" << "[" << r_index << "][" << c_index<< "]" << " unavailable\n";
                                }
                            }
                            else {
                                if (board[r_index - 1][c_index] == nullptr) {
                                    //cout << "Move NORTH available, " << "Move to [" << r_index - 1 << "][" << c_index << "]" << endl;

                                    // check if critter has already moved during time step
                                    if (board[r_index][c_index]->getCritterMoved()) {
                                        // if critter already moved, do not move it again
                                    }
                                    else {
                                        // set critter moved bool in Doodlebug (must set bool before moving)
                                        board[r_index][c_index]->setCritterMoved(true);

                                        // move doodlebug
                                        board[r_index - 1][c_index] = board[r_index][c_index];

                                        // delete old pointer
                                        // delete board[r_index][c_index];

                                        // set old pointer to null
                                        board[r_index][c_index] = nullptr;
                                    }
                                }
                                else {
                                    //cout << "Move NORTH" << "[" << r_index << "][" << c_index<< "]" << " unavailable\n";
                                }
                            }
                        }
                            break;
                        case 2: // get EAST square
                        {
                            if ( (c_index + 1) >= col ) {  // if out of bounds EAST wall
                                if (board[r_index][0] == nullptr) {   // go to first col
                                    //cout << "Move EAST available, " << "Move to [" << r_index << "][" << 0 << "]" << endl;

                                    // check if critter has already moved during time step
                                    if (board[r_index][c_index]->getCritterMoved()) {
                                        // if critter already moved, do not move it again
                                    }
                                    else {
                                        // set critter moved bool in Doodlebug to true
                                        board[r_index][c_index]->setCritterMoved(true);

                                        // move doodlebug
                                        board[r_index][0] = board[r_index][c_index];

                                        // set old pointer to null
                                        board[r_index][c_index] = nullptr;
                                    }
                                }
                                else {
                                    //cout << "Move EAST" << "[" << r_index << "][" << c_index<< "]" << " unavailable\n";
                                }
                            }
                            else {
                                if (board[r_index][c_index + 1] == nullptr) {

                                    //cout << "Move EAST available, " << "Move to [" << r_index << "][" << c_index + 1 << "]" << endl;

                                    // check if critter has already moved during time step
                                    if (board[r_index][c_index]->getCritterMoved()) {
                                        // if critter already moved, do not move it again
                                    }
                                    else {
                                        // set critter moved bool in Doodlebug (must set bool before moving)
                                        board[r_index][c_index]->setCritterMoved(true);

                                        // move doodlebug
                                        board[r_index][c_index+1] = board[r_index][c_index];

                                        // set old pointer to null
                                        board[r_index][c_index] = nullptr;
                                    }
                                }
                                else {
                                    //cout << "Move EAST" << "[" << r_index << "][" << c_index<< "]" << " unavailable\n";
                                }
                            }
                        }
                            break;
                        case 3: // get SOUTH square
                        {
                            if (r_index + 1 >= row) {  // if out of bounds SOUTH wall
                                if (board[0][c_index] == nullptr) { // go to first row
                                    //cout << "Move NORTH available, " << "Move to [" << 0 << "][" << c_index << "]" << endl;

                                    // check if critter has already moved during time step
                                    if (board[r_index][c_index]->getCritterMoved()) {
                                        // if critter already moved, do not move it again
                                    }
                                    else {
                                        // set critter moved bool in Doodlebug to true
                                        board[r_index][c_index]->setCritterMoved(true);

                                        // move doodlebug
                                        board[0][c_index] = board[r_index][c_index];

                                        // set old pointer to null
                                        board[r_index][c_index] = nullptr;
                                    }
                                }
                                else {
                                    //cout << "Move SOUTH" << "[" << r_index << "][" << c_index<< "]" << " unavailable\n";
                                }
                            }
                            else {
                                if (board[r_index + 1][c_index] == nullptr) {
                                    //cout << "Move SOUTH available, " << "Move to [" << r_index + 1 << "][" << c_index << "]" << endl;

                                    // check if critter has already moved during time step
                                    if (board[r_index][c_index]->getCritterMoved()) {
                                        // if critter already moved, do not move it again
                                    }
                                    else {
                                        // set critter moved bool in Doodlebug (must set bool before moving)
                                        board[r_index][c_index]->setCritterMoved(true);

                                        // move doodlebug
                                        board[r_index + 1][c_index] = board[r_index][c_index];

                                        // set old pointer to null
                                        board[r_index][c_index] = nullptr;
                                    }
                                }
                                else {
                                    //cout << "Move SOUTH" << "[" << r_index << "][" << c_index<< "]" << " unavailable\n";
                                }
                            }
                        }
                            break;
                        case 4: // get WEST square
                        {
                            if ( (c_index - 1) < 0 ) {  // if out of bounds WEST wall
                                if (board[r_index][col - 1] == nullptr) {   // go to last col
                                    //cout << "Move WEST available, " << "Move to [" << r_index << "][" << col - 1 << "]" << endl;

                                    // check if critter has already moved during time step
                                    if (board[r_index][c_index]->getCritterMoved()) {
                                        // if critter already moved, do not move it again
                                    }
                                    else {
                                        // set critter moved bool in Doodlebug to true
                                        board[r_index][c_index]->setCritterMoved(true);

                                        // move doodlebug to last column
                                        board[r_index][col - 1] = board[r_index][c_index];

                                        // set old pointer to null
                                        board[r_index][c_index] = nullptr;
                                    }
                                }
                                else {
                                    //cout << "Move WEST" << "[" << r_index << "][" << c_index<< "]" << " unavailable\n";
                                }
                            }
                            else {
                                if (board[r_index][c_index - 1] == nullptr) {
                                    //cout << "Move WEST available, " << "Move to [" << r_index << "][" << c_index - 1 << "]" << endl;

                                    // check if critter has already moved during time step
                                    if (board[r_index][c_index]->getCritterMoved()) {
                                        // if critter already moved, do not move it again
                                    }
                                    else {
                                        // set critter moved bool in Doodlebug (must set bool before moving)
                                        board[r_index][c_index]->setCritterMoved(true);

                                        // move doodlebug
                                        board[r_index][c_index - 1] = board[r_index][c_index];

                                        // set old pointer to null
                                        board[r_index][c_index] = nullptr;
                                    }
                                }
                                else {
                                    //cout << "Move WEST" << "[" << r_index << "][" << c_index<< "]" << " unavailable\n";
                                }
                            }
                        }
                            break;
                        default:
                            cout << "Unable to determine direction to move!\n";
                    }

                    // call doodlebug move function
                    //board[r_index][c_index]->move();
                }
            }
        }
    }

    // reset all doodlebug move bool to false (otherwise you may move bugs more than once each time step)
    for (int r_index = 0; r_index < row; r_index++) {
        for (int c_index = 0; c_index < col; c_index++) {
            if (board[r_index][c_index] != nullptr) {
                if (board[r_index][c_index]->getCritterType() == "X") {
                    board[r_index][c_index]->setCritterMoved(false);
                }
            }
        }
    }

}

/*********************************************************************
** Description:     description
*********************************************************************/
void Game::spawnDoodlebugs() {
    cout << "Spawning doodlebugs" << endl;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Game::spawnAnts() {
    cout << "Spawning ants" << endl;
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



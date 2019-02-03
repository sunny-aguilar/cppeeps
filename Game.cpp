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
//    int direction;
//    cout << "Enter direction to travel\n";
//    cout << ">> ";
//    cin >> direction;
    for (int r_index = 0; r_index < row; r_index++) {
        for (int c_index = 0; c_index < col; c_index++) {
            if (board[r_index][c_index] != nullptr) {
                if (board[r_index][c_index]->getCritterType() == "X") {
                    // use switch statement to select which direction to go
//                    switch (direction) {
//                        case 1:
//                            {
//                                // get NORTH square
//                                if ( (r_index - 1) < 0 ) {  // if out of bounds NORTH wall
//                                    if (board[row - 1][c_index] == nullptr) {   // go to last row
//                                        cout << "Move NORTH available, " << "Move to [" << row-1 << "][" << c_index << "]" << endl;
//                                    }
//                                    else {
//                                        cout << "Move NORTH unavailable\n";
//                                    }
//                                }
//                                else {
//                                    if (board[r_index-1][c_index] == nullptr) {
//                                        cout << "Move NORTH available\n";
//                                        cout << "Move NORTH available, " << "Move to [" << r_index-1 << "][" << c_index << "]" << endl;
//
//                                        // move doodlebug
//                                        board[r_index-1][c_index] = board[r_index][c_index];
//
//                                        // delete old pointer
//                                        // delete board[r_index][c_index];
//
//                                        // set old pointer to null
//                                        board[r_index][c_index] = nullptr;
//                                    }
//                                    else {
//                                        cout << "Move NORTH unavailable\n";
//                                    }
//                                }
//                            }
//                            break;
//                        case 2:
//                            {
//                                // get EAST square
//                                if ( (c_index + 1) > col ) {  // if out of bounds EAST wall
//                                    if (board[r_index][0] == nullptr) {   // go to first col
//                                        cout << "Move EAST available, " << "Move to [" << r_index << "][" << 0 << "]" << endl;
//                                    }
//                                    else {
//                                        cout << "Move EAST unavailable\n";
//                                    }
//                                }
//                                else {
//                                    if (board[r_index][c_index + 1] == nullptr) {
//                                        cout << "Move EAST available\n";
//                                        cout << "Move EAST available, " << "Move to [" << r_index << "][" << c_index+1 << "]" << endl;
//
//                                        // move doodlebug
//                                        board[r_index][c_index+1] = board[r_index][c_index];
//
//                                        // set old pointer to null
//                                        board[r_index][c_index] = nullptr;
//                                    }
//                                    else {
//                                        cout << "Move EAST unavailable\n";
//                                    }
//                                }
//                            }
//                            break;
//                        case 3:
//                            {
//
//                            }
//                            break;
//                        case 4:
//                            {
//
//                            }
//                            break;
//                        default:
//                            cout << "Unable to determine direction to move!\n";
//                    }


                    // get surrounding spaces to see if available


                    // get NORTH square
//                    if ( (r_index - 1) < 0 ) {  // if out of bounds NORTH wall
//                        if (board[row - 1][c_index] == nullptr) {   // go to last row
//                            cout << "Move NORTH available, " << "Move to [" << row - 1 << "][" << c_index << "]" << endl;
//
//                            // move doodlebug
//                            board[r_index-1][c_index] = board[r_index][c_index];
//
//                            // set old pointer to null
//                            board[r_index][c_index] = nullptr;
//                        }
//                        else {
//                            cout << "Move NORTH unavailable\n";
//                        }
//                    }
//                    else {
//                        if (board[r_index-1][c_index] == nullptr) {
//                            cout << "Move NORTH available, " << "Move to [" << r_index - 1 << "][" << c_index << "]" << endl;
//
//                            // move doodlebug
//                            board[r_index-1][c_index] = board[r_index][c_index];
//
//                            // delete old pointer
//                            // delete board[r_index][c_index];
//
//                            // set old pointer to null
//                            board[r_index][c_index] = nullptr;
//                        }
//                        else {
//                            cout << "Move NORTH unavailable\n";
//                        }
//                    }


                    // get EAST square
//                    if ( (c_index + 1) >= col ) {  // if out of bounds EAST wall
//                        if (board[r_index][0] == nullptr) {   // go to first col
//                            cout << "Move EAST available, " << "Move to [" << r_index << "][" << 0 << "]" << endl;
//
//                            // move doodlebug
//                            board[r_index][c_index+1] = board[r_index][c_index];
//
//                            // set old pointer to null
//                            board[r_index][c_index] = nullptr;
//                        }
//                        else {
//                            cout << "Move EAST unavailable\n";
//                        }
//                    }
//                    else {
//                        if (board[r_index][c_index + 1] == nullptr) {
//
//                            cout << "Move EAST available, " << "Move to [" << r_index << "][" << c_index + 1 << "]" << endl;
//
//                            // move doodlebug
//                            board[r_index][c_index+1] = board[r_index][c_index];
//
//                            // set old pointer to null
//                            board[r_index][c_index] = nullptr;
//                        }
//                        else {
//                            cout << "Move EAST unavailable\n";
//                        }
//                    }



                    // get SOUTH square


                    // get WEST square
                    if ( (c_index - 1) < 0 ) {  // if out of bounds WEST wall
                        if (board[r_index][col - 1] == nullptr) {   // go to last col
                            cout << "Move WEST available, " << "Move to [" << r_index << "][" << col - 1 << "]" << endl;

                            // move doodlebug
                            board[r_index][col - 1] = board[r_index][c_index];

                            // set old pointer to null
                            board[r_index][c_index] = nullptr;
                        }
                        else {
                            cout << "Move WEST unavailable\n";
                        }
                    }
                    else {
                        if (board[r_index][c_index - 1] == nullptr) {
                            cout << "Move WEST available, " << "Move to [" << r_index << "][" << c_index - 1 << "]" << endl;

                            // move doodlebug
                            board[r_index][c_index - 1] = board[r_index][c_index];

                            // set old pointer to null
                            board[r_index][c_index] = nullptr;
                        }
                        else {
                            cout << "Move WEST unavailable\n";
                        }
                    }


                    // call doodlebug move function
                    //board[r_index][c_index]->move();
                }
            }
        }
    }
}

/*********************************************************************
** Description:     this function iterates through the board to find
**                  all of the ants.
*********************************************************************/
void Game::moveAnts() {
    cout << "Moving ants" << endl;
    for (int r_index = 0; r_index < row; r_index++) {
        for (int c_index = 0; c_index < col; c_index++) {
            if (board[r_index][c_index] != nullptr) {
                if (board[r_index][c_index]->getCritterType() == "O") {
                    board[r_index][c_index]->move();
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



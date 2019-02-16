/*********************************************************************
** Program name: 		Game.cpp
** Author: 			Kuljot Biring, Rachel Schlick, Ryan Gross,
** 				Sandro Aguilar, Jeesoo Ryoo
** Date: 			02/17/2019
** Description: 		Game class description here
*********************************************************************/
#include "Game.hpp"
// TODO REMOVE THIS BEFORE SUBMIT
#include <chrono>
#include <thread>

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
    // set game variables
    const int MIN_SIZE = 5;
    const int MAX_SIZE = 100;
    const int MIN_STEPS = 1;
    const int MAX_STEPS = 20000;

    // TODO: REMOVE THIS FUNCTION BEFORE SUBMIT
    // menuDebugMode:
    // prompt to press enter before displaying board in each step. 
    menu.menuDebugMode();
    isDebugMode = menu.inputValidator(1, 3);

    // display start menu
    menu.startMenu();
    switch (menu.inputValidator(1,2)) {
        case 1:
            // set game parameters
            // set board rows and columns
            menu.boardRowSizeMenu(MIN_SIZE, MAX_SIZE);
            row = menu.inputValidator(MIN_SIZE, MAX_SIZE);
            menu.boardColSizeMenu(MIN_SIZE, MAX_SIZE);
            col = menu.inputValidator(MIN_SIZE, MAX_SIZE);
            maxCritters = row * col;

            // make sure that total critters entered
            // by user does not exceed board space
            setCritters(maxCritters);

            // board set-up
            initializeCritters();

            // repeat simulation; only change steps
            do {
                // set total steps to simulate
                menu.critterStepsPrompt();
                steps = menu.inputValidator(MIN_STEPS, MAX_STEPS);

                // perform critter activities (move, eat, spawn)
                int currentStep = 0;
                critterActivities(currentStep);

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
void Game::setCritters(int maxBugs) {
    // set critter qty variables
    const int MIN_DOODLES = 1;
    const int MIN_ANTS = 1;
	int max_ants = maxBugs - 1; // set limit based on user input
	int max_doodles; // dependent on user input
	
    bool askAgain = true;
    do {
        // set total ants
        menu.numAntsMenu(MIN_ANTS, max_ants);
        antQty = menu.inputValidator(MIN_ANTS, max_ants);
		
		max_doodles = maxBugs - antQty; // total limit cannot exceed maximum amount of cells on grid
        // set total doodlebugs
        menu.numDoodleBugsMenu(MIN_DOODLES, max_doodles);
        doodlebugQty = menu.inputValidator(MIN_DOODLES, max_doodles);

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
	
    //nonrandomPlacement();
    critterRandomPlacement();

    // display the initial board
    displayBoard();
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
void Game::critterActivities(int cStep) {
    do {
        // increase step count
        cStep++;

        // move doodlebugs
        int antsEaten = moveDoodlebugs();

        // starve doodlebugs
        int starvedDoodles = starvedDoodlebugs();

        // spawn doodlebugs
        int newDoodles = spawnDoodlebugs();

        // move ants
        moveAnts();

        // spawn ants
        int newAnts = spawnAnts();
		
        // display updated board (new arguments for menu.displayboard)
        displayBoard(cStep, antsEaten, newDoodles, newAnts, starvedDoodles);


    } while (cStep < steps);
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Game::displayBoard(int cStep, int antsEaten, int newDoodles, int newAnts, int starvedDoodles) {
    // <-- ADDED parameters to pass through to menu.displayboard

    // built top wall
    for (int index = 0; index < col; index++) {
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
    for (int index = 0; index < col; index++) {
        cout << "--";
    }
    cout << "\n" << endl;
	
	// Get updated stats for the menu board
	int doodleCt = getDoodleQty();
	int antCt = getAntQty();
	menu.menuDisplayBoard(col, cStep, doodleCt, antCt, antsEaten, newDoodles, newAnts, starvedDoodles);

    // TODO: REMOVE THIS CODE BEFORE SUBMIT
    cout << std::flush;
    if (isDebugMode == 1) {
        cout << "Press enter to continue\n";
        cin.ignore();
    } else if (isDebugMode == 2) {
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

/*********************************************************************
** Description:  Doodlebug accessors and mutators
*********************************************************************/
int Game::getDoodleQty() { return doodlebugQty; } // ADDED

void Game::setDoodleQty(int doodleChange) {
	doodlebugQty = doodlebugQty + doodleChange;
}

/*********************************************************************
** Description:  Ant accumulators and mutators
*********************************************************************/
int Game::getAntQty() { return antQty; } // ADDED

void Game::setAntQty(int antChange) {
	antQty = antQty + antChange;
}

/*********************************************************************
** Description:     this function calls a function and passes it an
**                  argument to indicate that all the doodlebugs
**                  should be moved.
*********************************************************************/
int Game::moveDoodlebugs() { // <-- CHANGED void to int for tracking ants eaten
    int antChange = moveCritters("X");
	setAntQty(antChange); // should be negative- decrease ant population
	cout << "The number of ants eaten is: " << antChange << endl; // for testing
	return abs(antChange); // report as a non-negative number
}

/*********************************************************************
** Description:     this function removes a doodlebug that didn't eat
**                  more than 3 times.
*********************************************************************/
int Game::starvedDoodlebugs() { // CHANGED void to int to return num starved
    // iterate though board and select "Doodlebugs" and move them
	int starvedDoodles = 0;
    for (int r_index = 0; r_index < row; r_index++) {
        for (int c_index = 0; c_index < col; c_index++) {
            if (board[r_index][c_index] != nullptr && board[r_index][c_index]->getCritterType() == "X") {
                if (board[r_index][c_index]->isStarved()) {
                    cout << "Doodlebug starved at: " << r_index << ", " << c_index << endl;
                    delete board[r_index][c_index];
                    board[r_index][c_index] = nullptr;
					setDoodleQty(-1); // <-- ADDED remove one doodlebug from total
					starvedDoodles++; // <-- ADDED
                }
            }
        }
    }
	return starvedDoodles; // <-- ADDED

}

/*********************************************************************
** Description:     this function calls a function and passes it an
**                  argument to indicate that all the ants should be
**                  moved.
*********************************************************************/
void Game::moveAnts() {
    int doodleChange = moveCritters("O");
	setDoodleQty(doodleChange); // should be zero
	cout << "The number of doodles changed in ant move is: " << doodleChange << endl; // test print to ensure no non-zero values
}

/*********************************************************************
** Description:     this function takes the type of critter to move
**                  as a string parameter. This allows the function
**                  to select the right type of critter to move. "X"
**                  will move the doodlebugs and "O" will move the
**                  ants. Two for-loops are used to iterate through
**                  the board. If the space on the board is not empty,
**                  then a random number from 1-4 will be generated to
**                  select the direction to move the critter (1=NORTH,
**                  2=EAST, 3=SOUTH, 4=WEST). A switch statement is
**                  then used to move the critter in the randomly
**                  selected direction. The critters are moved around
**                  the board PACMAN style which is consistent with
**                  keeping the boards on the grid. If the selected
**                  direction is already occupied, then the critter
**                  does not move (consistent with specifications).
*********************************************************************/
int Game::moveCritters(string critterType) { // <--CHANGED void to int
	int critterChange = 0; // added to track ants eaten
    // iterate though board and select "Doodlebugs" and move them
    for (int r_index = 0; r_index < row; r_index++) {
        for (int c_index = 0; c_index < col; c_index++) {
            if (board[r_index][c_index] != nullptr && board[r_index][c_index]->getCritterType() == critterType) {
                critterChange += (board[r_index][c_index]->move(board, row, col));
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
                if (board[r_index][c_index]->getCritterType() == "O") {
                    board[r_index][c_index]->setCritterMoved(false);
                }
            }
        }
    }
	return critterChange; // <--ADDED
}

/*********************************************************************
** Description:     description
*********************************************************************/
int Game::spawnDoodlebugs() { // <-- CHANGED from void to int
    cout << "Spawning doodlebugs" << endl;
	int newDoodles = 0;
    for (int r_index = 0; r_index < row; r_index++) {
        for (int c_index = 0; c_index < col; c_index++) {
            if (board[r_index][c_index] != nullptr && board[r_index][c_index]->getCritterType() == "X") {

                // should return an integer to add to count of baby doodles
				newDoodles += (board[r_index][c_index]->breed(board, row, col));
            }
        }
    }
	setDoodleQty(newDoodles); // <-- ADDED to track total
	return newDoodles; // <-- ADDED to track breed this step
}

/*********************************************************************
** Description:     description
*********************************************************************/
int Game::spawnAnts() { // <-- CHANGED from void to int
	int newAnts = 0;
    for (int r_index = 0; r_index < row; r_index++) {
        for (int c_index = 0; c_index < col; c_index++) {
            if (board[r_index][c_index] != nullptr && board[r_index][c_index]->getCritterType() == "O") {

                newAnts += (board[r_index][c_index]->breed(board, row, col));

            }
        }
    }
	setAntQty(newAnts); // <-- ADDED to track total 
	return newAnts; // <--ADDED to track new ants each step
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

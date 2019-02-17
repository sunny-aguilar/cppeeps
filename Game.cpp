/*********************************************************************
** Author:       Kuljot Biring, Rachel Schlick, Ryan Gross,
**               Sandro Aguilar, Jeesoo Ryoo
** Date:         02/17/2019
*********************************************************************/
#include "Game.hpp"

/***************************************************************************
** Description: Default constructor; initializes according to design spec.
***************************************************************************/
Game::Game() : board{nullptr},
               playAgain{true},
               row{0},
               col{0},
               doodlebugQty{0},
               antQty{0},
               totalCritters{0},
               steps{0} {}

/*********************************************************************
** Description: Destructor; frees heap memory.
*********************************************************************/
Game::~Game()
{
    for (int r_index = 0; r_index < row; r_index++)
    {
        for (int c_index = 0; c_index < col; c_index++)
        {
            if (board[r_index][c_index] != nullptr)
            {
                delete board[r_index][c_index];
            }
        }
        delete[] board[r_index];
    }
    delete[] board;
}

/*********************************************************************
** Description: Void method that sets up the dynamic 2D array
** ("game board"), and then runs an instance of the game. Iterates 
** until user requests to terminate it.
*********************************************************************/
void Game::playGame()
{
    const int MIN_SIZE = 5;
    const int MAX_SIZE = 100;
    const int MIN_STEPS = 1;
    const int MAX_STEPS = 20000;

    menu.startMenu();
    switch (menu.inputValidator(1, 2))
    {
    case 1:
        menu.boardRowSizeMenu(MIN_SIZE, MAX_SIZE);
        row = menu.inputValidator(MIN_SIZE, MAX_SIZE);
        menu.boardColSizeMenu(MIN_SIZE, MAX_SIZE);
        col = menu.inputValidator(MIN_SIZE, MAX_SIZE);
        maxCritters = row * col;
        setCritters(maxCritters);
        initializeCritters();

        do
        {
            menu.critterStepsPrompt();
            steps = menu.inputValidator(MIN_STEPS, MAX_STEPS);
            int currentStep = 0;
            critterActivities(currentStep);
            playAgain = goAgain();
        } while (playAgain);
        break;
    case 2:
    {
        menu.menuExitGameMessage();
        playAgain = false;
        break;
    }
    break;
    default:
        cout << INVALID_SELECTION_PROMPT << endl;
    }
}

/*********************************************************************
** Description: Void method that sets the amount of Critters on the 
** board as per user input, specifying how many Doodlebugs and Ants.
** Notifies user if input exceeds amount of available spaces in board.
*********************************************************************/
void Game::setCritters(int maxBugs)
{
    const int MIN_DOODLES = 1;
    const int MIN_ANTS = 1;
    int max_ants = maxBugs - 1;
    int max_doodles;

    bool askAgain = true;
    do
    {
        menu.numAntsMenu(MIN_ANTS, max_ants);
        antQty = menu.inputValidator(MIN_ANTS, max_ants);
        max_doodles = maxBugs - antQty;
        menu.numDoodleBugsMenu(MIN_DOODLES, max_doodles);
        doodlebugQty = menu.inputValidator(MIN_DOODLES, max_doodles);

        int totalUserCritters = doodlebugQty + antQty;
        totalCritters = totalUserCritters;

        if (totalUserCritters > maxCritters)
        {
            cout << INVALID_SELECTION_PROMPT << maxCritters
                 << ANTS_DOODLEBUGS_PROMPT << endl;
            cout << setw(4) << antQty << ANTS_ENTERED_PROMPT << endl;
            cout << setw(4) << doodlebugQty << DOODLEBUGS_ENTERED_PROMPT << endl;
            askAgain = true;
        }
        else if (totalUserCritters <= maxCritters)
        {
            askAgain = false;
        }
    } while (askAgain);
}

/*********************************************************************
** Description: Void method that dynamically creats as board based
** on the rows/cols determined via user input.
*********************************************************************/
void Game::initializeCritters()
{
    board = new Critter **[row];

    for (int index = 0; index < row; index++)
    {
        board[index] = new Critter *[col];
    }

    for (int r_index = 0; r_index < row; r_index++)
    {
        for (int c_index = 0; c_index < col; c_index++)
        {
            board[r_index][c_index] = nullptr;
        }
    }
    critterRandomPlacement();
    displayBoard();
}

/*********************************************************************
** Description: Void method that creates ant and doodlebug objects and
** randomly places them on the board.
*********************************************************************/
void Game::critterRandomPlacement()
{
    menu.menuRandomPlacement();

    int r_index = 0;
    int c_index = 0;

    for (int ant = 0; ant < antQty; ant++)
    {
        do
        {
            r_index = generateRandomNumber(0, row - 1);
            c_index = generateRandomNumber(0, col - 1);
        } while (board[r_index][c_index] != nullptr);
        board[r_index][c_index] = new Ant(r_index, c_index);
    }

    for (int doodlebug = 0; doodlebug < doodlebugQty; doodlebug++)
    {
        do
        {
            r_index = generateRandomNumber(0, row - 1);
            c_index = generateRandomNumber(0, col - 1);
        } while (board[r_index][c_index] != nullptr);
        board[r_index][c_index] = new Doodlebug(r_index, c_index);
    }
}

/*********************************************************************
** Description: Void method that controls moment, spawning, and starvation
** of critters on board; displays board afterward.
*********************************************************************/
void Game::critterActivities(int cStep)
{
    do
    {
        cStep++;
        int antsEaten = moveDoodlebugs();
        int starvedDoodles = starvedDoodlebugs();
        int newDoodles = spawnDoodlebugs();
        moveAnts();
        int newAnts = spawnAnts();
        displayBoard(cStep, antsEaten, newDoodles, newAnts, starvedDoodles);

    } while (cStep < steps);
}

/*********************************************************************
** Description: Void method that takes in 5 ints; step iteration,
** ants eaten, doodlebugs created, ants created, and starved doodlebugs
** Displays updated board. 
*********************************************************************/
void Game::displayBoard(int cStep, int antsEaten, int newDoodles, int newAnts, int starvedDoodles)
{
    for (int index = 0; index < col; index++)
    {
        cout << "__";
    }
    cout << endl;

    for (int r_index = 0; r_index < row; r_index++)
    {
        cout << "|";
        for (int c_index = 0; c_index < col; c_index++)
        {
            if (board[r_index][c_index] != nullptr)
            {
                if (board[r_index][c_index]->getCritterType() == "X")
                {
                    cout << "X|";
                }
                else if (board[r_index][c_index]->getCritterType() == "O")
                {
                    cout << "O|";
                }
            }
            else
            {
                cout << " |";
            }
        }
        cout << endl;
    }

    for (int index = 0; index < col; index++)
    {
        cout << "--";
    }
    cout << "\n"
         << endl;

    int doodleCt = getDoodleQty();
    int antCt = getAntQty();
    menu.menuDisplayBoard(col, cStep, doodleCt, antCt, antsEaten, newDoodles, newAnts, starvedDoodles);
}

/*********************************************************************
** Description: Getter for # of doodlebugs.
*********************************************************************/
int Game::getDoodleQty() { return doodlebugQty; }

/*********************************************************************
** Description: Setter for # of doodlebugs.
*********************************************************************/
void Game::setDoodleQty(int doodleChange)
{
    doodlebugQty = doodlebugQty + doodleChange;
}

/*********************************************************************
** Description: Getter for # of ants.
*********************************************************************/
int Game::getAntQty() { return antQty; }

/*********************************************************************
** Description: Setter for # of ants.
*********************************************************************/
void Game::setAntQty(int antChange)
{
    antQty = antQty + antChange;
}

/*********************************************************************
** Description: Method that moves critters and sets qty of ants.
** Returns an int
*********************************************************************/
int Game::moveDoodlebugs()
{
    int antChange = moveCritters("X");
    setAntQty(antChange);
    return abs(antChange);
}

/*********************************************************************
** Description: Iterates through board and removes doodlebugs from
** board that have not eaten more than 3x; returns an int.
*********************************************************************/
int Game::starvedDoodlebugs()
{
    int starvedDoodles = 0;
    for (int r_index = 0; r_index < row; r_index++)
    {
        for (int c_index = 0; c_index < col; c_index++)
        {
            if (board[r_index][c_index] != nullptr && board[r_index][c_index]->getCritterType() == "X")
            {
                if (board[r_index][c_index]->isStarved())
                {
                    delete board[r_index][c_index];
                    board[r_index][c_index] = nullptr;
                    setDoodleQty(-1);
                    starvedDoodles++;
                }
            }
        }
    }
    return starvedDoodles;
}

/*********************************************************************
** Description: Void method that calls function to move critters and 
** then sets quantity for specific type.
*********************************************************************/
void Game::moveAnts()
{
    int doodleChange = moveCritters("O");
    setDoodleQty(doodleChange);
}

/*********************************************************************
** Description: Takes in a string (critter type); iterates through the board
** and will move critter accordingly based on said type. If space on board
** is occupied, a direction is randomly generated to pick which 
** direction the critter should move.
*********************************************************************/
int Game::moveCritters(string critterType)
{
    int critterChange = 0;

    for (int r_index = 0; r_index < row; r_index++)
    {
        for (int c_index = 0; c_index < col; c_index++)
        {
            if (board[r_index][c_index] != nullptr && board[r_index][c_index]->getCritterType() == critterType)
            {
                critterChange += (board[r_index][c_index]->move(board, row, col));
            }
        }
    }

    for (int r_index = 0; r_index < row; r_index++)
    {
        for (int c_index = 0; c_index < col; c_index++)
        {
            if (board[r_index][c_index] != nullptr)
            {
                if (board[r_index][c_index]->getCritterType() == "X")
                {
                    board[r_index][c_index]->setCritterMoved(false);
                }
                if (board[r_index][c_index]->getCritterType() == "O")
                {
                    board[r_index][c_index]->setCritterMoved(false);
                }
            }
        }
    }
    return critterChange;
}

/*********************************************************************
** Description: Method used to create new doodlebugs on board.
** Returns an int.
*********************************************************************/
int Game::spawnDoodlebugs()
{
    int newDoodles = 0;
    for (int r_index = 0; r_index < row; r_index++)
    {
        for (int c_index = 0; c_index < col; c_index++)
        {
            if (board[r_index][c_index] != nullptr && board[r_index][c_index]->getCritterType() == "X")
            {
                newDoodles += (board[r_index][c_index]->breed(board, row, col));
            }
        }
    }
    setDoodleQty(newDoodles);
    return newDoodles;
}

/*********************************************************************
** Description: Method used to create new ants on board.
** Returns an int.
*********************************************************************/
int Game::spawnAnts()
{
    int newAnts = 0;
    for (int r_index = 0; r_index < row; r_index++)
    {
        for (int c_index = 0; c_index < col; c_index++)
        {
            if (board[r_index][c_index] != nullptr && board[r_index][c_index]->getCritterType() == "O")
            {

                newAnts += (board[r_index][c_index]->breed(board, row, col));
            }
        }
    }
    setAntQty(newAnts);
    return newAnts;
}

/*********************************************************************
** Description: Method that returns a boolean, representing if 
** another round of the game should occur.
*********************************************************************/
bool Game::goAgain()
{
    menu.menuPlayAgain();
    int selection = menu.inputValidator(1, 2);
    switch (selection)
    {
    case 1:
        return true;
        break;
    case 2:
        return false;
        break;
    default:
        cout << KEEP_PLAYING_PROMPT;
    }
    return false;
}
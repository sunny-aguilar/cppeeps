/*********************************************************************
** Program Name:  Predator vs Prey
** Class Name:    Menu
** Author:        Kuljot Biring, Rachel Schlick, Ryan Gross,
**                Sandro Aguilar, Jeesoo Ryoo
** Date:          02/17/2019
** Description:   Class specification file for Menu class.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include "utils.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::string;
using std::stringstream;

class Menu
{
private:
  const std::string USER_CHOICE_PROMPT = "Please enter a choice listed below\n";
  const std::string RUN_PROMPT = "1. Run Simulation\n";
  const std::string EXIT_PROMPT = "2. Exit Simulation\n";
  const std::string EC_ROW_SIZE_PROMPT = "\n[Extra Credit] ROW SIZE\n";
  const std::string ROW_RANGE_PROMPT = "Please enter the number of rows for the game board \n";
  const std::string BOARD_LENGTH_PROMPT = "Enter the length of the board from ";
  const std::string EC_COL_SIZE_PROMPT = "\n[Extra Credit] COLUMN SIZE\n";
  const std::string COL_RANGE_PROMPT = "Please enter the number of columns for the game board \n";
  const std::string BOARD_WIDTH_PROMPT = "Enter the width of the board from ";
  const std::string EC_NUM_OF_ANTS_PROMPT = "\n[Extra Credit] ANTS\n";
  const std::string ANT_USER_INPUT_PROMPT = "Enter the number of ants you would like to have\n";
  const std::string ANT_RANGE_PROMPT = "Enter the number of ants from ";
  const std::string EC_NUM_OF_DOODLEBUGS_PROMPT = "\n[Extra Credit] DOODLEBUGS\n";
  const std::string DOODLEBUG_USER_INPUT_PROMPT = "Enter the number of doodlebugs you would like to have\n";
  const std::string DOODLEBUG_RANGE_PROMPT = "Enter the number of doodlebugs from ";
  const std::string CRITTER_PLACEMENT_NOTIFICATION = "\nAnts and Doodlebugs have been randomly placed on the board\n";
  const std::string EC_ANT_STEPS_PROMPT = "\nSTEPS\n";
  const std::string ANT_STEPS_USER_INPUT_PROMPT = "Enter the total number of steps the ant should walk from 1 through 20000 only";
  const std::string CURRENT_STATS_NOTIFICATION = "Predator VS Prey - CURRENT STATS";
  const std::string CURRENT_STEPS_TAKEN_NOTIFICATION = "Current steps taken: ";
  const std::string ANT_AMT_NOTIFICATION = "Ants on board: ";
  const std::string DOODLEBUG_AMT_NOTIFICATION = "Doodlebugs on board: ";
  const std::string ANTS_EATEN_NOTIFICATION = "Ants eaten this step: ";
  const std::string ANTS_BRED_NOTIFICATION = "Ants bred this step: ";
  const std::string DOODLEBUGS_BRED_NOTIFICATION = "Doodlebugs bred this step: ";
  const std::string DOODLEBUGS_STARVED_NOTIFICATION = "Doodlebugs starved this step: ";
  const std::string GAME_RERUN_PROMPT = "\nWould you like to run the simulation again using "
                                        "a different number of steps?\n";
  const std::string ENTER_CHOICE_PROMPT = "Please enter a choice listed below\n";
  const std::string RERUN_SELECTION = "1. Changes Step count and rerun Simulation\n";
  const std::string QUIT_SELECTION = "2. Quit Simulation\n";
  const std::string EXITING_PROMPT = "\nNow exiting the predator-prey simulation";
  const std::string INVALID_ENTRY_PROMPT = "Invalid entry! You must choose number from ";
  bool numVerify;
  string userInput;
  int selection;

public:
  Menu();
  int inputValidator(int min, int max);
  void startMenu();
  void boardRowSizeMenu(int min, int max);
  void boardColSizeMenu(int min, int max);
  void numAntsMenu(int min, int max);
  void numDoodleBugsMenu(int min, int max);
  void menuRandomPlacement();
  void critterStepsPrompt();
  void menuDisplayBoard(int col = 0, int cStep = 0, int doodleCt = 0, int antCt = 0, int antsEaten = 0, int newDoodles = 0, int newAnts = 0, int starvedDoodles = 0);
  void menuPlayAgain();
  void menuExitGameMessage();
};

#endif

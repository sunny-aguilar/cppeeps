/*********************************************************************
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Header file for critter parent base class
*********************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

#include "utils.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

enum Direction
{
  UP = 1,
  RIGHT,
  DOWN,
  LEFT
};

class Critter
{
protected:
  const std::string UNABLE_TO_MOVE_PROMPT = "Unable to determine direction to move!\n";
  Direction direction;
  std::string critterType;
  int stepsSurvived;
  bool critterBred;
  int readyToBreed;
  bool critterMoved;
  int row, col, newRow, newCol;
  void makeStepToNewCell(Critter ***&grid);

public:
  Critter();
  Critter(string type, int row, int col);
  virtual ~Critter();

  int getRow();
  void setRow(int row);

  int getCol();
  void setCol(int col);

  void setNewRow(int row);
  int getNewRow();

  void setNewCol(int col);
  int getNewCol();

  bool getCritterMoved();
  void setCritterMoved(bool moved);
  string getCritterType();

  void setCritterBred(bool bred);
  bool getCritterBred();

  virtual void setStepsSurvived() = 0;
  virtual int getStepsSurvived() = 0;
  void resetStepsSurvived();
  virtual bool isStarved();

  virtual int move(Critter ***&grid, int ROW, int COL) = 0;
  virtual int breed(Critter ***&grid, int row, int col) = 0;
  void setNewRowColByDirection(int direction, int gridROW, int gridCOL);
  bool isSpaceAvailable(int *);
};
#endif //CRITTER_HPP

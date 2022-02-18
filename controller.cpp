#include "controller.h"
#include "Board.h"
Controller::Controller()
{

}

bool Controller::move(int i, class Board* B)
{
  int j=B->IsMovieCellTo(i) ;
    if (j==-1 ) return false;

      B->Swap(B->getCell(i),B->getCell(j)) ;
      return true;
}

bool Controller::start(Board *B,int level)
{
  B->Start(level);
  return true;
}

bool Controller::isWin(Board *B)
{
  return B->IsWin();
}

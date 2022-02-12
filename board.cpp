#include "board.h"

Board::Board(void){

    for (int i=0;i<16;i++)
        Cells[i]=new Cell(i+1,this);

}

bool Board::IsWin()
{
  return true;
}

bool Board::Swap(Cell * c_1, Cell * c_2)
{
   return true;
}

void Board::printBoard()
{
  for(int i=0;i<16;i++)
  {
     std::cout << Cells[i]->getName()<<":"<<int(Cells[i]->getNumber())<<std::endl;
  }
}

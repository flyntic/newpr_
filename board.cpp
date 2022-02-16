#include "board.h"
#include <vector>
Board::Board(void){

    for (int i=0;i<16;i++)
        Cells.push_back( new Cell((i),this));

}

bool Board::IsWin()
{int i=0;
    for(auto &c:Cells)
      {
        if (i++!=c->getNumber()) return false;
      }
  return true;
}

void Board::Swap(Cell * c_1, Cell * c_2)
{ //int i1=getNumberCell(c_1);
 // int i2=getNumberCell(c_2);
 // std::swap(Cells[i1],Cells[i2]);
 class Cell *c=new Cell();
  c->copyCell(c_1 );
  c_1->copyCell(c_2 );
  c_2->copyCell(c );

  delete c;
}

int Board::IsMovieCellTo(int i)
{  class Cell *c=getCell(i);
   for(int m=0;m<4;m++)
    if (c->isMovie(enMOVIES(m)))
      { class Cell *c2= c->Movie(enMOVIES(m));
        if(c2->getNumber()==0)
        {
            int tt=getNumberCell(c2);
            return tt;
        }
      }
  return -1;
}
void Board::printBoard()
{
  for(auto &c:Cells)//int i=0;i<16;i++)
  {
     std::cout << c->getName()<<":"<<int(c->getNumber())<<std::endl;
  }
}

Cell *Board::getCell(int i)
{
    return Cells[i];
}

int Board::getNumberCell(Cell *c)
{int i=0;
    for(auto t:Cells)
    {
        if(t->getName() ==c->getName()) return i;
        i++;
    }
}




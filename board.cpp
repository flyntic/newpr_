#include "board.h"
#include <vector>
#include <time.h>

Board::Board(void){

    for (int i=1;i<16;i++)
        Cells.push_back( new Cell(i,this));

    Cells.push_back( new Cell(0,this));

}

Cell *Board::getCell(int i)
{
  if (i!=0)
      return Cells[i-1];

  return Cells[15];
}

int Board::getNumberCell(Cell *c)
{int i=0;
    for(auto t:Cells)
    {
        if(t->getName() ==c->getName())
          return i+1;
       if (++i>15) return 0;
    }
}

void Board::Swap(Cell * c_1, Cell * c_2)
{
  class Cell *c=new Cell();
  c->copyCell(c_1 );
  c_1->copyCell(c_2 );
  c_2->copyCell(c );

  delete c;
}

void Board::Start(int level) //‘ишки перемешиваютс€ так, чтобы их можно было точно собрать, уровень - число перестановок
{
  srand(time(0));

  if (level==0) level=rand()%90+10;

  int cellmotion[4][2]; //_1[4],c[4];
  int ncell,nchoice_motion;

  for (int i_level=0;i_level<10+level;i_level++)
   {  int n=0;
      for(int ncell=0;ncell<16;ncell++)
        { //поиск пар €чеек дл€ перестановок
          cellmotion[n][0]=IsMovieCellTo(ncell);

          if (cellmotion[n][0]!=-1)
              cellmotion[n++][1]=ncell;
        }

      if (n!=0) nchoice_motion=rand()%n;
        else nchoice_motion=0;

      Swap(getCell(cellmotion[nchoice_motion][0]),getCell(cellmotion[nchoice_motion][1]));
   }

  for (int i_cell=0;i_cell<15;i_cell++) //сдвиг €чеек, чтобы 0 был справа внизу
    {
      if (getCell(i_cell)->getNumber()==0)
       if(i_cell%4<3) Swap(getCell(i_cell),getCell(i_cell+1));
         else if(i_cell/4<4) Swap(getCell(i_cell),getCell(i_cell+4));
    }

}

int Board::IsMovieCellTo(int i)
{
   class Cell *c=getCell(i);

   if (c->getNumber()==0) return -1;

   for(int movi=0;movi<4;movi++) //ћќ∆Ќќ ли организовать цикл по enum
    if (c->isMovieFromCell(enMOVIES(movi)))
    {
        class Cell *tocell= c->MovieFromCell(enMOVIES(movi));
        if(tocell->getNumber()==0)
        {
            int numbercell=getNumberCell(tocell);
            return numbercell;
        }

    }
   return -1;
}


void Board::printBoard()
{int i=0;
 int number;

  char str[2];
  for(auto &c:Cells)
  {
    if((i++)%4==0) std::cout<<std::endl;
    c->printCell();
  }
}

bool Board::IsWin()
{int i=1;
    for(auto &c:Cells)
      { if(i==16) break;
        if (i++!=c->getNumber()) return false;
      }
  return true;
}



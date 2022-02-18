#include "cell.h"

Cell::Cell()
{

}

Cell::Cell(int i, class Board *B)
{

  number=i;
  name="cell_"+std::to_string(i);

  if (i==0)i=16;
  movies[MOVIE_DOWN]= ((i-1)/4)<3;
  movies[MOVIE_UP]=   ((i-1)/4)>0;
  movies[MOVIE_LEFT]= ((i-1)%4)>0;
  movies[MOVIE_RIGHT]=((i-1)%4)<3;

  board=B;
}

const std::string &Cell::getName() const
{
    return name;
}

int Cell::getNumber() const
{
    return number;
}

void Cell::copyCell(Cell *c_2)
{
    this->name=c_2->name;
    this->number=c_2->number;
}

bool Cell::isMovieFromCell(enMOVIES m)
{
  return this->movies[m];
}

Cell *Cell::MovieFromCell(enMOVIES m)
{
  Board * B=this->board;

  int i=B->getNumberCell(this);
  switch (m)
  {
    case MOVIE_UP:    return B->getCell(i-4);
    case MOVIE_DOWN:  return B->getCell(i+4);
    case MOVIE_LEFT:  return B->getCell(i-1);
    case MOVIE_RIGHT: return B->getCell(i+1);
    }
}

void Cell::printCell()
{
  if (number==0) std::cout<<"\t";
  else std::cout<<number<<"\t";
}

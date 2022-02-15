#include "cell.h"

Cell::Cell()
{

}

Cell::Cell(int i, class Board *B)
{
  number=i;
  name="cell_"+std::to_string(i);

  movies[MOVIE_DOWN]= (i/4)<3;
  movies[MOVIE_UP]=   (i/4)>1;
  movies[MOVIE_LEFT]= (i%4)>1;
  movies[MOVIE_RIGHT]=(i%4)<3;

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
   // this->movies[MOVIE_UP]   =c_2->movies[MOVIE_UP];
   // this->movies[MOVIE_DOWN] =c_2->movies[MOVIE_DOWN];
   // this->movies[MOVIE_LEFT] =c_2->movies[MOVIE_LEFT];
   // this->movies[MOVIE_RIGHT]=c_2->movies[MOVIE_RIGHT];

}

bool Cell::isMovie(enMOVIES m)
{
  return true;
}

Cell *Cell::Movie(enMOVIES m)
{Board * B;
  switch (m)
  {
    case MOVIE_UP:    return B->getCell(B->getNumberCell(this)-4);
    case MOVIE_DOWN:  return B->getCell(B->getNumberCell(this)+4);
    case MOVIE_LEFT:  return B->getCell(B->getNumberCell(this)-1);
    case MOVIE_RIGHT: return B->getCell(B->getNumberCell(this)+1);
  }
}

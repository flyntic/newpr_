#include "cell.h"

Cell::Cell()
{

}

Cell::Cell(int i, Board *B)
{
  number=i;
  name="cell_"+std::to_string(i);

  movies[Down]=(i/4)<3;
  movies[Up]=(i/4)>0;
  movies[Left]=(i%4)>0;
  movies[Right]=(i%4)<3;

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

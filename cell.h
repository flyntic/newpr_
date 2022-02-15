#ifndef CELL_H
#define CELL_H

#include <string>
#include <iostream>

#include "Board.h"

typedef enum
{
  MOVIE_RIGHT=0,
  MOVIE_DOWN=1,
  MOVIE_LEFT=2,
  MOVIE_UP=3

}enMOVIES;

class Cell
{
public:
    Cell();
    Cell(int i,class Board * B);
    const std::string &getName() const;
    int getNumber() const;
    void copyCell(class Cell *c_2 );
    bool isMovie(enMOVIES m);
    class Cell* Movie(enMOVIES m);
private:
    std::string name;
    int number;
    bool movies[4];
    class Board *board;
};

#endif // CELL_H

#ifndef CELL_H
#define CELL_H

#include <string>
#include <iostream>

extern class Board;

typedef enum
{
  Right=0,
  Down=1,
  Left=2,
  Up=3

};

class Cell
{
public:
    Cell();
    Cell(int i,Board * B);
    const std::string &getName() const;

    int getNumber() const;

private:
    std::string name;
    int number;
    bool movies[4];
    Board *board;
};

#endif // CELL_H

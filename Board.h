#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include <vector>
#include "cell.h"


class Board
{
public:
    Board();
    class Cell * getCell(int i);
    int  getNumberCell(class Cell *c);
    void Swap(class Cell* c_1,class Cell * c_2);
    int  IsMovieCellTo(int i);
    void Start(int level=0);
    void printBoard();
    bool IsWin();
private:
    std::vector <class Cell*> Cells;
};

#endif // BOARD_H

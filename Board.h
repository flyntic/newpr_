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
    bool IsWin();
    void Swap(class Cell* c_1,class Cell * c_2);
    int  IsMovieCellTo(int i);
    void printBoard();

    class Cell * getCell(int i);
    int getNumberCell(class Cell *c);

private:
    std::vector <class Cell*> Cells;
};

#endif // BOARD_H

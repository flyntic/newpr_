#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>

#include "cell.h"


class Board
{
public:
    Board();
    bool IsWin();
    bool Swap(int c_1,int c_2);
    void printBoard();
private:
    Cell* Cells[16];
};

#endif // BOARD_H

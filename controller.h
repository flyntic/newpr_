#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Board.h"

class Controller
{
public:
    Controller();
    bool move(int i,class Board * B);
    bool start(class Board *B,int level=0);
    bool isWin(class Board *B);
};

#endif // CONTROLLER_H

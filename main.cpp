#include <iostream>
#include <time.h>
#include "Board.h"
#include "Controller.h"
using namespace std;

int main()
{
    Board *B=new Board();
    Controller * C=new Controller();

    int level;
    std::cout<<"LEVEL(int)?" ;
    std::cin>>level;

    C->start(B,level);

    int hod;
    while (! C->isWin(B))  //имитация игры
    {
      B->printBoard();
      std::cout<<"POSIBLE: ";
      for(int i=0;i<16;i++)   //подсказка игроку о возможных ходах
      {   int n=B->IsMovieCellTo(i);
          if (n!=-1)
          {  std::cout<<i<<" --> "<<n<<" ; ";
             hod=i;
           }
      };

      std::cout<<" MOVI ? ";  //выбор хода игрока
      std::cin>>hod;

      if (C->move(hod,B))   //ход
        std::cout<<" MOVI: "<<hod<<endl;
      else std::cout<<" MOVI NOT POSIBLE "<<endl;;
    }

    B->printBoard();
    std::cout<<"WIN";

    return 1;
}

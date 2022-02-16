#include <iostream>
#include "Board.h"
#include "Controller.h"
using namespace std;

int main()
{
    Board *B=new Board();
    Controller * C=new Controller();
    srand(time(0));
    int n=rand()%90+10;
    int c1,c2;
   /* for (int i=0;i<n;i++)
     {
        c1=rand()%16;
        c2=rand()%16;
        B->Swap(B->getCell(c1),B->getCell(c2));
     }*/

    B->printBoard();
    int hod;
  //  int n=0;
    do
    {
    for(int i=0;i<16;i++)
    {
        if (B->IsMovieCellTo(i)!=-1)
          {  std::cout<<i<<";";
            hod=i;
        }
    };

     std::cout<<"ХОД:"<<hod<<endl;
     C->move(hod,B);

     B->printBoard();
   }
    while (!B->IsWin());


        std::cout<<"ПОБЕДА";

    return 1;
}

#ifndef GAME_H
#define GAME_H

#include "time.h"
#include "stdlib.h"

struct acrossShip
{
    int flag=0;//
    int switchFF;
    int switchF[4]={1};
    int horizontal;
    int chance=2;
    int newi;
    int newj;
    int oldi;
    int oldj;
    int loop=0;
    int plus;
    int i;
    int j;
    int left;
    int right;
    int top;
    int buttom;
    //acrossShip() {}
};

class Game {
public:
    Game();
    int masMap[10][10]={0};
    int masMapF[10][10]={0};
    int Win;
    int WinF;
    int BotDmg;
    int Flag;
    void newGame();
    int checkAbout(int Map[10][10], int i, int j, bool horizontal, int sizeShip);
    int checkAbout(int Map[10][10], int i, int j);
    void genShips(int Map[10][10]);

};
#endif // GAME_H

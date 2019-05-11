#ifndef GAME_H
#define GAME_H

#include "time.h"
#include "stdlib.h"


class Game {
public:
    Game();
    int masMap[10][10]={0};
    int masMapF[10][10]={0};
    int Win;
    int WinF;
    int Flag;
    void newGame();
    int checkAbout(int Map[10][10], int i, int j, bool horizontal, int sizeShip);
    void genShips(int Map[10][10]);

};
#endif // GAME_H

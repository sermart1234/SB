#include "game.h"
#include "stdio.h"

int Game::checkAbout(int Map[10][10], int i, int j, bool horizontal, int sizeShip)
{
    i--;
    j--;
    sizeShip+=2;
    if (horizontal){
        for (int ic=i; ic<(i+3); ic++){
            if (ic<0||ic>9) continue;
            for (int jc=j; jc<(j+sizeShip); jc++){
                if (jc<0||jc>9) continue;
                if (Map[ic][jc]>1){return 1;};
            }
        }
    }
    else {
         for (int ic=i; ic<(i+sizeShip); ic++){
            if (ic<0||ic>9) continue;
            for (int jc=j; jc<(j+3); jc++){
                if (jc<0||jc>9) continue;
                if (Map[ic][jc]>1){return 1;};
            }
         }
    }
    return 0;
}

void Game::genShips(int Map[10][10])
{
    int i=0;
    int j=0;
    int size[10]={4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    int id=3;
    for (int s=0; s<10;s++){
        bool horizontal=rand()%2;
        if (horizontal){
            i=rand()%10;
            j=rand()%(11-size[s]);
            if (checkAbout(Map, i, j, horizontal, size[s])){s--; continue;};
            for (int ss=0; ss<size[s]; ss++){
                Map[i][j+ss]=id;
            }
        id++;
        }
        else {
            j=rand()%10;
            i=rand()%(11-size[s]);
            if (checkAbout(Map, i, j, horizontal, size[s])){s--; continue;};
            for (int ss=0; ss<size[s]; ss++){
                Map[i+ss][j]=id;
            }
            id++;
        }
     }
}

int Game::checkAbout(int Map[10][10], int i, int j)
{
    i--;
    j--;
    int sizeShip=1;
    sizeShip+=2;
        for (int ic=i; ic<(i+3); ic++){
            if (ic<0||ic>9) continue;
            for (int jc=j; jc<(j+sizeShip); jc++){
                if (jc<0||jc>9) continue;
                if (Map[ic][jc]==2){return 1;};
            }
        }
    return 0;
}

Game::Game(){}

void Game::newGame(){
    Win=10;
    WinF=10;
    BotDmg=0;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            masMap[i][j]=0;
            masMapF[i][j]=0;
        }
    }
    srand(time(NULL));
    genShips(masMap);
    genShips(masMapF);
}

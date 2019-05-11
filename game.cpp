#include "game.h"
#include "stdio.h"

int Game::checkAbout(int Map[10][10], int i, int j, bool horizontal, int sizeShip)
{
    i--;
    //printf("%d\n", i);
    j--;
    //printf("%d\n", j);
    sizeShip+=2;
    //printf("%d\n", sizeShip);
    if (horizontal){
        for (int ic=i; ic<(i+3); ic++){
            if (ic<0||ic>9) continue;
            //printf("%d i\n", i);
            for (int jc=j; jc<(j+sizeShip); jc++){
                if (jc<0||jc>9) continue;
                //printf("%d j\n", j);
                if (Map[ic][jc]>1){return 1;};
                //Map[ic][jc]=2;
            }}}
    else {
         for (int ic=i; ic<(i+sizeShip); ic++){
            if (ic<0||ic>9) continue;
            //printf("%d i\n", i);
            for (int jc=j; jc<(j+3); jc++){
                if (jc<0||jc>9) continue;
                //printf("%d j\n", j);
                if (Map[ic][jc]>1){return 1;};
                //Map[ic][jc]=2;
            }}}
    return 0;
}

void Game::genShips(int Map[10][10])
{
    int i=0;
    int j=0;
    int size[10]={4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    int id=3;
    //srand(time(NULL));
    for (int s=0; s<10;s++){
        //printf("%d\n", s);
        bool horizontal=rand()%2;
        if (horizontal){
            i=rand()%10;
            j=rand()%(11-size[s]);
            if (checkAbout(Map, i, j, horizontal, size[s])){s--; continue;};
            for (int ss=0; ss<size[s]; ss++){
                Map[i][j+ss]=id;
            }
        id++;}
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


Game::Game()
{
    newGame();

}

void Game::newGame(){
    srand(time(NULL));
    genShips(masMap);
    genShips(masMapF);
    //masMap[9][9]=20;
    //genShips(masMapg);
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            //masMap[i][j]=10*i+j+1;
            //masMapF[i][j]=10*i+j+1;
            //masMapg[i][j]=-1;
            //if (i==j){masMap[i][j]=1;}
            //else masMapF[i][j]=1;
            printf("%d ", masMap[i][j]);
        }
        printf("\n");
}
    printf("\n\n");
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            printf("%d ", masMapF[i][j]);
        }
        printf("\n");
}
}


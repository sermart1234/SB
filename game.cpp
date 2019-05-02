#include "game.h"
#include "stdio.h"

Game::Game()
{
    newGame();

}

void Game::newGame(){
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            masMap[i][j]=10*i+j+1;
            masMapF[i][j]=10*i+j+1;
            if (i==j){masMap[i][j]=1;}
            else masMapF[i][j]=1;
            printf("%d ", masMap[i][j]);
        }
        printf("\n");
}
}


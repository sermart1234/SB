#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "winner.h"
#include "game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Sea Battle");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::genButton(char flag)
{
    ui->lcdNumber->display(game.WinF);
    ui->lcdNumber_2->display(game.Win);
    int cellSize = 40;
    int cellSpace = 0;
    int topSpace = 40;
    int leftSpace = 0;
    QDynamicButton::ResID = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) {
    cells[i][j]= new QDynamicButton(this);
    cells[i][j]->setGeometry(
        (cellSize + cellSpace) * j + leftSpace,
        (cellSize + cellSpace) * i + topSpace,
        cellSize,
        cellSize);
    cells[i][j]->setVisible(true);
    if (flag==0) connect(cells[i][j], SIGNAL(clicked()), this, SLOT(slotGetNumber()));
    else connect(cells[i][j], SIGNAL(clicked()), this, SLOT(slotGetNumber2()));
        }
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) {
    cells2[i][j]= new QDynamicButton(this);
    cells2[i][j]->setGeometry(
        (cellSize + cellSpace) * j + leftSpace +11*40,
        (cellSize + cellSpace) * i + topSpace,
        cellSize,
        cellSize);
    cells2[i][j]->setVisible(true);
    cells2[i][j]->setEnabled(false);
    if (flag) connect(cells2[i][j], SIGNAL(clicked()), this, SLOT(slotGetNumber2()));
    else connect(cells2[i][j], SIGNAL(clicked()), this, SLOT(slotGetNumber()));
        }
    }
}

void MainWindow::on_Player2_triggered()
{
    game.newGame();
    cross.flag=0;
    genButton(0);

}

void MainWindow::on_Bot_triggered()
{
    game.newGame();
    cross.flag=1;
    genButton(1);

}


void MainWindow::slotGetNumber()
{
    QDynamicButton *button = (QDynamicButton*) sender();

    int indexButton=button->getID();
    int i=indexButton/10;
    int j=indexButton%10-1;
    int valueButton;
    int *mas=(int*)game.masMap;
    char flag=0;

    if (i>9){mas=(int*)game.masMapF; i=i-10; flag=1;};
    valueButton=mas[10*i+j];

    if (valueButton>2){button->setIcon(QIcon("img/true.png")); mas[10*i+j]=2;}
    else {if(valueButton!=2){button->setIcon(QIcon("img/false.png"));
            if (valueButton!=1){switchPlayer();}
            mas[10*i+j]=1; }}

    if (checkKill(valueButton, mas, flag)){setKill(i, j, mas, flag); checkWin();};
}


void MainWindow::slotGetNumber2()
{
    QDynamicButton *button = (QDynamicButton*) sender();

    int indexButton=button->getID();
    indexButton-=1;
    int i=indexButton/10;
    int j=indexButton%10;
    int valueButton;
    int *mas=(int*)game.masMap;
    char flag=0;
    char goBotF=0;

    if (i>9){mas=(int*)game.masMapF; i=i-10; flag=1;};
    valueButton=mas[10*i+j];

    if (valueButton>2){button->setIcon(QIcon("img/true.png")); mas[10*i+j]=2;
        if (flag) {game.BotDmg=1; goBotF=1;}
    }
    else {
        if(valueButton!=2){button->setIcon(QIcon("img/false.png"));
            if (valueButton!=1){mas[10*i+j]=1; if (!flag) {goBotF=1;}}
            else {if (flag) {goBotF=1;}}}
        else {if (flag) {goBotF=1;}}}
    if (checkKill(valueButton, mas, flag)){setKill(i, j, mas, flag); checkWin();};

    if (goBotF) goBot();
}

void MainWindow::goBot()
{
    int i, j;
    int *k;
    if (game.BotDmg)
    {
        i=cross.i;
        j=cross.j;
        if((game.masMapF[i][j]==1))
        {
            cross.chance--;
            i=cross.oldi;
            j=cross.oldj;
            reversPlus(&cross.plus);
        }

        if (cross.chance<0) {reversPlus(&cross.horizontal);cross.chance=2;}

        if (cross.horizontal){k=&j;}
        else k=&i;
     re_p:

        if((cross.plus)==1){if (*k<9) {(*k)++;} else {cross.chance--;reversPlus(&cross.plus);goto re_p;}}
        else {if (*k>0) {(*k)--;} else {cross.chance--;reversPlus(&cross.plus);goto re_p;}}


    }
    else
    {
        opt:
        i=rand() % 10;
        j=rand() % 10;
        cross.i=i;
        cross.j=j;
        cross.oldi=i;
        cross.oldj=j;
        cross.horizontal=rand() % 2;
        cross.plus=rand() % 2;
        cross.chance=2;
        if (game.checkAbout(game.masMapF, i, j)) goto opt;
        if (game.masMapF[i][j]==1||game.masMapF[i][j]==2) {goto opt;}
    }
    cross.i=i;
    cross.j=j;
    cells2[i][j]->clicked();
}

void MainWindow::reversPlus(int *plus)
{
    int buf=*plus;
    *plus=!buf;
}


void MainWindow::switchPlayer()
{
    bool flag=cells[0][0]->isEnabled();
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) {
          cells[i][j]->setEnabled(!flag);
          cells2[i][j]->setEnabled(flag);
        }
    }
}

void MainWindow::disablePlayer()
{
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) {
          cells[i][j]->setEnabled(false);
          cells2[i][j]->setEnabled(false);
        }
    }
}

int setIndex(int i, int j){
    asm(
        "movl    %edi, -4(%rbp)\n"
        "movl    %esi, -8(%rbp)\n"
        "movl    -4(%rbp), %eax\n"
        "imull   $10, %eax, %edx\n"
        "movl    -8(%rbp), %eax\n"
        "addl    %edx, %eax\n"
        );
}

int MainWindow::checkKill(int id, int* mas, char flag)
{
    int index;
    for (int i=0; i<10; i++){
            for (int j=0; j<10; j++){
                index=setIndex(i, j);
                if (mas[index]==id){return 0;}
            };
    }
    if (flag){game.Win--;game.BotDmg=0;}
    else {game.WinF--;}

    ui->lcdNumber->display(game.WinF);
    ui->lcdNumber_2->display(game.Win);
    return 1;
}


void MainWindow::setKill(int is, int js, int* mas, char flag)
{
    int i= is;
    int j= js;
    for (int i=is;i>(is-4);i--)
    {
        if (mas[10*i+j]==2){
            if (flag){cells2[i][j]->setIcon(QIcon("img/kill.png"));}
            else {cells[i][j]->setIcon(QIcon("img/kill.png"));}}
        else break;
        if (i==0){break;}
    }

    for (int i=is;i<(is+4);i++)
    {
        if (mas[10*i+j]==2){
            if (flag){cells2[i][j]->setIcon(QIcon("img/kill.png"));}
            else {cells[i][j]->setIcon(QIcon("img/kill.png"));}}
        else break;
        if (i==9){break;}
    }

    i= is;
    j= js;

    for (int j=js;j>(js-4);j--)
    {

        if (mas[10*i+j]==2){
            if (flag){cells2[i][j]->setIcon(QIcon("img/kill.png"));}
            else {cells[i][j]->setIcon(QIcon("img/kill.png"));};}
        else break;
        if (j==0){break;}
    }
    for (int j=js;j<(js+4);j++)
    {

        if (mas[10*i+j]==2){
            if (flag){cells2[i][j]->setIcon(QIcon("img/kill.png"));}
            else {cells[i][j]->setIcon(QIcon("img/kill.png"));};}
        else break;
        if (j==9){break;}
    }
}

int MainWindow::checkWin()
{

    if (game.Win==0){
        Winner win(this);
        disablePlayer();
        if (cross.flag) win.setWinner("Победил BOT", 1);
        else win.setWinner("Победил второй игрок", 0);
        win.exec();
    }
    if (game.WinF==0){
        Winner win(this);
        disablePlayer();
        win.setWinner("Победил первый игрок", 0);
        win.exec();
    }


    return 0;
}


void MainWindow::on_exit_triggered()
{
    qApp->quit();
}

void MainWindow::on_delWinList_triggered()
{
    FILE* WinList = fopen("./WINLIST.txt", "w");
    fclose(WinList);
}

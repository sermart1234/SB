#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include <QColor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game.Win=10;
    game.WinF=10;
    game.Flag=1;
}

MainWindow::~MainWindow()
{
    delete ui;
/*
    printf("\n\n");
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            printf("%d ", game.masMap[i][j]);
        }
        printf("\n");}

    printf("\n\n");
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            printf("%d ", game.masMapF[i][j]);
        }
        printf("\n");
}*/
}




/*Метод для добавления динамической кнопки*/
/*
void MainWindow::on_addButton_clicked2()
{
    int cellSize = 40; // Размер кнопки
    int cellSpace = 0; // Отступ
    int topSpace = 40; // Отступ сверху
    int leftSpace = 0; // Отступ слева

    // Создаём массив MapSize на MapSize из QPushButton
    for(int i = 0; i < 10; i++)
      for(int j = 0; j < 10; j++) {
        //cells[i][j] = new CellButton(game.getCell(i, j), this, i, j, game);
          //QDynamicButton *button = new CellButton(game.getCell(i, j), this, i, j, game);
          QDynamicButton *button = new QDynamicButton(this);
        // Шрифт как в прототипе
        //cells[i][j]->setFont(ui->fontPrototypeButton->font());
        // Задаём размеры и положение кнопки
        //cells[i][j]->setGeometry(
        button->setGeometry(
          (cellSize + cellSpace) * j + leftSpace,
          (cellSize + cellSpace) * i + topSpace,
          cellSize, // Ширина кнопки
          cellSize  // Высота кнопки
        );

        button->setText("К " + QString::number(button->getID()));
        ui->verticalLayout->addWidget(button);
        connect(button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
        //cells[i][j]->setVisible(true);

        //connect(cells[i][j], SIGNAL(clicked()),
                //cells[i][j], SLOT(slotCellClicked()));

        //connect(cells[i][j], SIGNAL(clicked()),
                //this, SLOT(updateWindow()));
      }

}*/

/*
void MainWindow::on_addButton_clicked()
{
    QDynamicButton *button = new QDynamicButton(this);  // Создаем объект динамической кнопки
    //Устанавливаем текст с номером этой кнопки
    button->setText("Кнопочка " + QString::number(button->getID()));
    // Добавляем кнопку в слой с вертикальной компоновкой
    ui->verticalLayout->addWidget(button);
    // Подключаем сигнал нажатия кнопки к СЛОТ получения номера кнопки
    connect(button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
}*/

void MainWindow::on_addButton_clicked()
{
    int cellSize = 40; // Размер кнопки
    int cellSpace = 0; // Отступ
    int topSpace = 40; // Отступ сверху
    int leftSpace = 0; // Отступ слева
    //QDynamicButton::ResID=0;
    QDynamicButton::ResID = 0;
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++) {
    //QDynamicButton *button
    cells[i][j]= new QDynamicButton(this);  // Создаем объект динамической кнопки
    //Устанавливаем текст с номером этой кнопки
    //button->setGeometry(10, 10, 10, 10);
    //button
    cells[i][j]->setGeometry(
      (cellSize + cellSpace) * j + leftSpace,
      (cellSize + cellSpace) * i + topSpace,
      cellSize, // Ширина кнопки
      cellSize  // Высота кнопки
    );
    //button->setIcon(QIcon("img/false.png"));//setText("К " + QString::number(button->getID()));
    // Добавляем кнопку в слой с вертикальной компоновкой
    //if (j==5){button->setVisible(false);}
    //else
    //button
    cells[i][j]->setVisible(true);
    //ui->verticalLayout->addWidget(button);
    //ui->verticalLayout->setGeometry(QRect(0, 0, 100-i*10, 100-i*10));

    //ui->centralWidget->
            //addWidget(button);
    // Подключаем сигнал нажатия кнопки к СЛОТ получения номера кнопки
    connect(cells[i][j], SIGNAL(clicked()), this, SLOT(slotGetNumber()));
      }}

    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++) {
    //QDynamicButton *button
    cells2[i][j]= new QDynamicButton(this);  // Создаем объект динамической кнопки
    //Устанавливаем текст с номером этой кнопки
    //button->setGeometry(10, 10, 10, 10);
    cells2[i][j]->setGeometry(
      (cellSize + cellSpace) * j + leftSpace +11*40,
      (cellSize + cellSpace) * i + topSpace,// +10*40,
      cellSize, // Ширина кнопки
      cellSize  // Высота кнопки
    );
    //button->setIcon(QIcon("img/false.png"));//setText("К " + QString::number(button->getID()));
    // Добавляем кнопку в слой с вертикальной компоновкой
    //if (j==5){button->setVisible(false);}
    //else
    cells2[i][j]->setVisible(true);
    //button
    cells2[i][j]->setEnabled(false);
    //ui->verticalLayout->addWidget(button);
    //ui->verticalLayout->setGeometry(QRect(0, 0, 100-i*10, 100-i*10));

    //ui->centralWidget->
            //addWidget(button);
    // Подключаем сигнал нажатия кнопки к СЛОТ получения номера кнопки
    connect(cells2[i][j], SIGNAL(clicked()), this, SLOT(slotGetNumber()));
      }}
}




//Метод для удаления динамической кнопки по её номеру
void MainWindow::on_deleteButton_clicked()
{
    int cellSize = 40; // Размер кнопки
    int cellSpace = 0; // Отступ
    int topSpace = 40; // Отступ сверху
    int leftSpace = 0; // Отступ слева
    //QDynamicButton::ResID=0;
    QDynamicButton::ResID = 0;
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++) {
    //QDynamicButton *button
    cells[i][j]= new QDynamicButton(this);  // Создаем объект динамической кнопки
    //Устанавливаем текст с номером этой кнопки
    //button->setGeometry(10, 10, 10, 10);
    //button
    cells[i][j]->setGeometry(
      (cellSize + cellSpace) * j + leftSpace,
      (cellSize + cellSpace) * i + topSpace,
      cellSize, // Ширина кнопки
      cellSize  // Высота кнопки
    );
    //button->setIcon(QIcon("img/false.png"));//setText("К " + QString::number(button->getID()));
    // Добавляем кнопку в слой с вертикальной компоновкой
    //if (j==5){button->setVisible(false);}
    //else
    //button
    cells[i][j]->setVisible(true);
    //ui->verticalLayout->addWidget(button);
    //ui->verticalLayout->setGeometry(QRect(0, 0, 100-i*10, 100-i*10));

    //ui->centralWidget->
            //addWidget(button);
    // Подключаем сигнал нажатия кнопки к СЛОТ получения номера кнопки
    connect(cells[i][j], SIGNAL(clicked()), this, SLOT(slotGetNumber2()));
      }}

    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++) {
    //QDynamicButton *button
    cells2[i][j]= new QDynamicButton(this);  // Создаем объект динамической кнопки
    //Устанавливаем текст с номером этой кнопки
    //button->setGeometry(10, 10, 10, 10);
    cells2[i][j]->setGeometry(
      (cellSize + cellSpace) * j + leftSpace +11*40,
      (cellSize + cellSpace) * i + topSpace,// +10*40,
      cellSize, // Ширина кнопки
      cellSize  // Высота кнопки
    );
    //button->setIcon(QIcon("img/false.png"));//setText("К " + QString::number(button->getID()));
    // Добавляем кнопку в слой с вертикальной компоновкой
    //if (j==5){button->setVisible(false);}
    //else
    cells2[i][j]->setVisible(true);
    //button
    cells2[i][j]->setEnabled(false);
    //ui->verticalLayout->addWidget(button);
    //ui->verticalLayout->setGeometry(QRect(0, 0, 100-i*10, 100-i*10));

    //ui->centralWidget->
            //addWidget(button);
    // Подключаем сигнал нажатия кнопки к СЛОТ получения номера кнопки
    connect(cells2[i][j], SIGNAL(clicked()), this, SLOT(slotGetNumber2()));
      }}
}

/* СЛОТ для получения номера кнопки.
 * */
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
    else {if(valueButton!=2){//button->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgba(0, 0, 255, 255));");
                        //QColor::red());//
            button->setIcon(QIcon("img/false.png"));
            if (valueButton!=1){switchPlayer();}
            mas[10*i+j]=1; }}

    if (checkKill(valueButton, mas, flag)){printf("kill\n"); setKill(i, j, mas, flag); checkWin();}; //button->setIcon(QIcon("img/kill.png"));};

    ui->lineEdit->setText(QString::number(indexButton));
}

void MainWindow::slotGetNumber2()
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
    else {if(valueButton!=2){//button->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgba(0, 0, 255, 255));");
                        //QColor::red());//
            button->setIcon(QIcon("img/false.png"));
            if (valueButton!=1){if (game.Flag){printf("%d", game.Flag); game.Flag=0; printf("BOT\n"); goBot(); }}
            mas[10*i+j]=1; }}
    game.Flag=1;
    if (checkKill(valueButton, mas, flag)){printf("kill\n"); setKill(i, j, mas, flag); checkWin();}; //button->setIcon(QIcon("img/kill.png"));};

    ui->lineEdit->setText(QString::number(indexButton));
}

void MainWindow::goBot()
{
    int i=rand() % 10;
    int j=rand() % 10;
    cells2[i][j]->clicked();
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

int MainWindow::checkKill(int id, int* mas, char flag)
{   //printf("check\n");
    for (int i=0; i<10; i++){
            for (int j=0; j<10; j++){
                if (mas[10*i+j]==id){return 0;}
                //printf("%d ", mas[10*i+j]);
            }
         //printf("\n");
    }
    if (flag){game.Win--;}
    else {game.WinF--;}
    printf("%d %d\n", game.Win, game.WinF);
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
    if (game.Win==0){printf("Победил первый игрок");return 1;};
    if (game.WinF==0){printf("Победил второй игрок");return 1;};
    return 0;
}

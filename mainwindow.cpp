#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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




/* Метод для удаления динамической кнопки по её номеру
void MainWindow::on_deleteButton_clicked()
{
    * Выполняем перебор всех элементов слоя, где располагаются динамические кнопки

    for(int i = 0; i < ui->verticalLayout->count(); i++){
        * Производим каст элемента слоя в объект динамической кнопки
         * *
        QDynamicButton *button = qobject_cast<QDynamicButton*>(ui->verticalLayout->itemAt(i)->widget());
         Если номер кнопки соответствует числу, которое установлено
         * в lineEdit, то производим удаление данной кнопки
         * *
        if(button->getID() == ui->lineEdit->text().toInt()){
            button->hide();

            //delete button;
        }
        button->setVisible(false);
    }
}*/

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

    if (valueButton>1){button->setIcon(QIcon("img/true.png")); mas[10*i+j]=2;}
    else {button->setIcon(QIcon("img/false.png")); if (valueButton!=1){switchPlayer();} mas[10*i+j]=1; }

    if (checkKill(valueButton, mas)){printf("kill\n"); setKill(i, j, mas, flag);}; //button->setIcon(QIcon("img/kill.png"));};

    ui->lineEdit->setText(QString::number(indexButton));
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

int MainWindow::checkKill(int id, int* mas)
{   //printf("check\n");
    for (int i=0; i<10; i++){
            for (int j=0; j<10; j++){
                if (mas[10*i+j]==id){return 0;}
                //printf("%d ", mas[10*i+j]);
            }
         //printf("\n");
    }
    return 1;
}


void MainWindow::setKill(int is, int js, int* mas, char flag)
{
    int i= is;
    int j= js;
    for (int i=is;i>(is-4);i--)
    {
        if (i==0){break;}
        if (mas[10*i+j]==2){
            if (flag){cells2[i][j]->setIcon(QIcon("img/kill.png"));}
            else {cells[i][j]->setIcon(QIcon("img/kill.png"));}}
        else break;}

    for (int i=is;i<(is+4);i++)
    {
        if (i==9){break;}
        if (mas[10*i+j]==2){
            if (flag){cells2[i][j]->setIcon(QIcon("img/kill.png"));}
            else {cells[i][j]->setIcon(QIcon("img/kill.png"));}}
        else break;
    }

    for (int j=is;j>(js-4);i--)
    {
        if (j==0){break;}
        if (mas[10*i+j]==2){
            if (flag){cells2[i][j]->setIcon(QIcon("img/kill.png"));}
            else {cells[i][j]->setIcon(QIcon("img/kill.png"));};}
        else break;
    }
    for (int j=is;j<(js+4);i++)
    {
        if (j==9){break;}
        if (mas[10*i+j]==2){
            if (flag){cells2[i][j]->setIcon(QIcon("img/kill.png"));}
            else {cells[i][j]->setIcon(QIcon("img/kill.png"));};}
        else break;
    }

}



#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    }


    /* Для удобства работы слои разделены QSplitter
         * */
    //ui->splitter->setStretchFactor(0,1);//
    //ui->splitter->setStretchFactor(1,0);//
//}

MainWindow::~MainWindow()
{
    delete ui;
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
    /* Определяем объект, который вызвал сигнал
     * */
    QDynamicButton *button = (QDynamicButton*) sender();
    /* После чего устанавливаем номер кнопки в lineEdit,
     * который содержится в данной динамической кнопке
     * */
    //ui->lineEdit->setText(QString::number(button->getID()));
    int indexButton=button->getID();
    printf("%d ", indexButton);////////
    int i=indexButton/10;
    int j=indexButton%10-1;
    int valueButton;
    if (i>9){valueButton=game.masMapF[i-10][j];}
    else {valueButton=game.masMap[i][j];}////////// Говно код. Переделать
    if (valueButton==1){button->setIcon(QIcon("img/true.png"));}//setText("X");}
    else {button->setIcon(QIcon("img/false.png")); switchPlayer();}//setText(".");//setVisible(false);
    ui->lineEdit->setText(QString::number(valueButton));////////
    //switchPlayer();
    /* То есть номер кнопки устанавливается в поле lineEdit только тогда,
     * когда мы нажимаем одну из динамических кнопок, и этот номер соответствует
     * номеру нажатой кнопки
     * */
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

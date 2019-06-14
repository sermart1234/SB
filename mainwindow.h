#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "cellbutton.h"//
#include "game.h"
//#include "winner.h"//

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //void resizeButtonsArray();

//private slots:
public slots:
    void on_addButton_clicked();    // СЛОТ-обработчик нажатия кнопки добавления
    void on_deleteButton_clicked(); // СЛОТ-обработчик нажатия кнопки удаления
    void on_Player2_triggered();
    void on_Bot_triggered();
    void slotGetNumber();           // СЛОТ для получения номера нажатой динамической кнопки
    void slotGetNumber2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Game game;
    struct acrossShip cross;
    //Winner win(this); // = new Winner(this);
    QDynamicButton* cells[10][10];
    QDynamicButton* cells2[10][10];
    void switchPlayer();
    void disablePlayer();
    int checkKill(int i, int *mas, char flag);
    int checkWin();
    void setKill(int is, int js, int* mas, char flag);
    //void goBot(int i, int j, int f);
    void goBot();
    void reversPlus(int *plus);
};

#endif // MAINWINDOW_H

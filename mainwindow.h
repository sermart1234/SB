#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "cellbutton.h"
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    struct acrossShip cross;
    QDynamicButton* cells[10][10];
    QDynamicButton* cells2[10][10];

public slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_Player2_triggered();
    //void genButton(char f);
    void genButton(char flag);
    void on_Bot_triggered();
    void slotGetNumber();
    void slotGetNumber2();
    void on_exit_triggered();
    void on_delWinList_triggered();


private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Game game;
    void switchPlayer();
    void disablePlayer();
    int checkKill(int i, int *mas, char flag);
    int checkWin();
    void setKill(int is, int js, int* mas, char flag);
    void goBot();
    void reversPlus(int *plus);
};

#endif // MAINWINDOW_H

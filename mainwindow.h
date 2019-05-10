#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "cellbutton.h"//
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
    //void resizeButtonsArray();

//private slots:
public slots:
    void on_addButton_clicked();    // СЛОТ-обработчик нажатия кнопки добавления
    void on_deleteButton_clicked(); // СЛОТ-обработчик нажатия кнопки удаления
    void slotGetNumber();           // СЛОТ для получения номера нажатой динамической кнопки

private:
    Ui::MainWindow *ui;
    Game game;
    QDynamicButton* cells[10][10];
    QDynamicButton* cells2[10][10];
    void switchPlayer();
    int checkKill(int i, int *mas);
    int checkWin(int i, int j);
    void setKill(int is, int js, int* mas, char flag);
};

#endif // MAINWINDOW_H

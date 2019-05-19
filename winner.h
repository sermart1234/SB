#ifndef WINNER_H
#define WINNER_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class Winner;
}

//class Winner : public QWidget
class Winner : public QDialog
{
    Q_OBJECT

public:
    explicit Winner(QWidget *parent = 0);
    ~Winner();
    void setWinner(char *s);

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Winner *ui;
};

#endif // WINNER_H

#include "winner.h"
#include "ui_winner.h"

Winner::Winner(QWidget *parent) :
   // QWidget(parent),
    QDialog(parent),
    ui(new Ui::Winner)
{
    ui->setupUi(this);
}

Winner::~Winner()
{
    delete ui;
}

void Winner::setWinner(char *s)
{
    ui->label->setText(s);
}

void Winner::on_pushButton_clicked()
{
    printf("dsf");
}

void Winner::on_buttonBox_accepted()
{
    ui->label->setText("fdsf");
}

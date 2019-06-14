#include "winner.h"
#include "ui_winner.h"
#include "QFile"
#include "game.h"

using namespace std;
Winner::Winner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Winner)
{
    ui->setupUi(this);
    this->setWindowTitle("Сохранить?");
    ui->lineEdit->setPlaceholderText("Введите имя ");
    ui->lineEdit->setFocus();

    QFile WinList("WINLIST.txt");

    if(WinList.open(QIODevice::ReadOnly | QIODevice::Text)){
    ui->textBrowser->setText(WinList.readAll());
    WinList.close();}
}

Winner::~Winner()
{
    delete ui;
}

void Winner::setWinner(char *s, char f)
{
    ui->label->setText(s);
    bot=f;
    if (bot) {ui->lineEdit->setDisabled(true); ui->lineEdit->setPlaceholderText(" BOT ");}
}

void Winner::on_buttonBox_accepted()
{
    QFile WinList("WINLIST.txt");
    QString str_r("Победил игрок ");
    QString str_g("");
    if (bot){str_g = "BOT\n"; goto end;}
    str_g =  ui->lineEdit->text() + "\n";
    str_r += str_g;
    ui->label->setText(str_r);
end:
    if(WinList.open(QIODevice::Append | QIODevice::Text))
    {
        WinList.write(str_g.toUtf8());
        WinList.close();
    }

    WinList.open(QIODevice::ReadOnly | QIODevice::Text);

    ui->buttonBox->setDisabled(true);
    ui->textBrowser->setText(WinList.readAll());
    WinList.close();
}


void Winner::on_buttonBox_rejected()
{
    destroy(true);
}

#include "welcome.h"
#include "ui_welcome.h"

Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    this->setWindowTitle("Добро пожаловать");
}

Welcome::~Welcome()
{
    delete ui;
}

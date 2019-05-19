#include "mainwindow.h"
#include <QApplication>
//#include "winner.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //Winner w;
    //w.show();
    w.show();

    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication tandaPlayer(argc, argv);
    MainWindow w;
    w.show();

    return tandaPlayer.exec();
}

#include "mainwindow.h"
#include <QApplication>
#include <QFile>
int main(int argc, char *argv[]) {
  QApplication tandaPlayer(argc, argv);

  QFile file(":/qss/default.qss");
  file.open(QFile::ReadOnly);
  tandaPlayer.setStyleSheet(file.readAll());

  MainWindow w;
  w.show();
  return tandaPlayer.exec();
}

#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication tandaPlayer(argc, argv);
  qDebug() << "Current path: " << QDir::currentPath();

  QFile file("default.qss");
  file.open(QFile::ReadOnly);
  tandaPlayer.setStyleSheet(file.readAll());
  file.close();

  MainWindow w;
  w.show();
  return tandaPlayer.exec();
}

#include <QApplication>
#include <QFile>
#include <QDir>
#include <QDebug>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
  QApplication tandaPlayer(argc, argv);
  qDebug() << "Current path: " << QDir::currentPath();

  QFile file(":/qss/default.qss");
  file.open(QFile::ReadOnly);
  tandaPlayer.setStyleSheet(file.readAll());
  file.close();

  MainWindow window;
  window.show();

  return tandaPlayer.exec();
}

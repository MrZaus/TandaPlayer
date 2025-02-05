#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QLoggingCategory>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
  QApplication tandaPlayer(argc, argv);
  QLoggingCategory::defaultCategory()->setEnabled(QtDebugMsg, true);
  qDebug() << "Current path: " << QDir::currentPath();
  QFile file(":/qss/default.qss");
  file.open(QFile::ReadOnly);
  tandaPlayer.setStyleSheet(file.readAll());
  file.close();

  MainWindow window;
  // window.setWindowState(Qt::WindowFullScreen);
  window.show();

  return tandaPlayer.exec();
}

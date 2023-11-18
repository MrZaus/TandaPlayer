#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  bool eventFilter(QObject *o, QEvent *e);
  virtual ~MainWindow() = default;
};

#endif // MAINWINDOW_H

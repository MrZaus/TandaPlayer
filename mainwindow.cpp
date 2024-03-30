#include "mainwindow.h"

#include <QApplication>
#include <QEvent>
#include <QFile>
#include <QFileSystemModel>
#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QMessageBox>
#include <QModelIndex>
#include <QMouseEvent>
#include <QSplitter>
#include <QStringList>
#include <QTreeView>
// #include <QMediaPlayer>

#include <cstdlib>

#include "common.h"
#include "controlswidget.h"
#include "displaywidget.h"
#include "mimefilterproxymodel.h"
#include "tandadelegate.h"
#include "tandawidget.h"
#include "wavewidget.h"

bool MainWindow::eventFilter(QObject *o, QEvent *e)
{
#ifndef NDEBUG
  if (o == centralWidget() && (e->type() == QMouseEvent::MouseButtonPress ||
                               e->type() == QEvent::WindowActivate))
  {
    qDebug() << "Reloading style from a file on an event!";
    QFile file("../default.qss");
    if (file.exists())
    {
      file.open(QFile::ReadOnly);
      auto *qapp = dynamic_cast<QApplication *>(QApplication::instance());
      qapp->setStyleSheet(file.readAll());
      file.close();
    }
    else
    {
      qDebug() << "File ../default.qss not found!";
    }
  }
#endif // NDEBUG
  if (e->type() == QKeyEvent::KeyRelease && static_cast<QKeyEvent *>(e)->key() == Qt::Key_Escape)
  {
    qDebug() << "Quitting on Esc!";
    QApplication::quit();
  }
  return QObject::eventFilter(o, e);
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
  //    this->setWindowFlags(Qt::FramelessWindowHint);
  //    this->setAttribute(Qt::WA_TranslucentBackground);

  auto *mainWidget = new QWidget(this);
  auto *mainLayout = new QVBoxLayout(mainWidget);
  mainLayout->setSpacing(0);
  mainLayout->setContentsMargins(0, 0, 0, 0);
  setCentralWidget(mainWidget);

  auto *displayWidget = new DisplayWidget(this);
  auto *waveWidget = new WaveWidget(this);
  auto *controlsWidget = new ControlsWidget(this);
  auto *splitter = new QSplitter(this);

  mainLayout->addWidget(displayWidget, STRETCH::NO);
  mainLayout->addWidget(waveWidget, STRETCH::NO);
  mainLayout->addWidget(controlsWidget, STRETCH::NO);
  mainLayout->addWidget(splitter, STRETCH::HI);
  auto *qtrv = new QTreeView(splitter);
  splitter->addWidget(qtrv);

  auto *playlistView = new QListView(this);
  playlistView->setItemDelegate(new TandaDelegate(playlistView));
  playlistView->setEditTriggers(playlistView->AllEditTriggers);
  splitter->addWidget(qtrv);
  splitter->addWidget(playlistView);
  playlistView->setModel(new PlaylistModel(this));
  auto *fsmodel = new QFileSystemModel(this);
  QStringList filters;
  filters << "*.mp3"
          << "*.wav"
          << "*.ogg"
          << "*.flac";
  fsmodel->setRootPath("C:\\");
  fsmodel->setNameFilters(filters);
  auto idx = fsmodel->index("C:\\");

  auto *proxyModel = new MimeFilterProxyModel(this);
  // TODO: filter on mimetype
  proxyModel->setSourceModel(fsmodel);
  qtrv->setModel(proxyModel);
  qtrv->setRootIndex(proxyModel->mapFromSource(idx));
  constexpr auto WinWidth = 700u;
  constexpr auto WinHeight = 480u;
  resize(WinWidth, WinHeight);
  mainWidget->installEventFilter(this);

  connect(qtrv, &QTreeView::doubleClicked,
          [proxyModel, fsmodel](const QModelIndex &index)
          {
            QMessageBox msgBox;
            msgBox.setText("The item has been double clicked.");
            auto const sourceIndex = proxyModel->mapToSource(index);
            auto fi = fsmodel->fileInfo(sourceIndex);
            const QString fname = fi.filePath();
            const QString str = "Do you want it to be double clicked? Path: " + fname;
            msgBox.setInformativeText(str);
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
          });
}

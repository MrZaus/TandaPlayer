#include "mainwindow.h"
#include <QApplication>
#include <QEvent>
#include <QFileSystemModel>
#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPushButton>
#include <QSortFilterProxyModel>
#include <QSplitter>
#include <QToolBar>
#include <QToolButton>
#include <QTreeView>

#include "common.h"
#include "controlswidget.h"
#include "displaywidget.h"
#include "mimefilterproxymodel.h"
#include "tandatreemodel.h"
#include "wavewidget.h"

void insertRow(const QAbstractItemView *view) {
  //    const QModelIndex index = view.selectionModel()->currentIndex();
  QAbstractItemModel *model = view->model();

  if (!model->insertRows(0, 4)) {
    qDebug() << "InsertRows error!";
    exit(1);
  }

  for (int column = 0; column < model->columnCount(); ++column) {
    QModelIndex child = model->index(1, column);
    model->setData(child, QVariant("[No data]"), Qt::EditRole);
  }
}

bool MainWindow::eventFilter(QObject *o, QEvent *e) {
  if (o == centralWidget() && (e->type() == QMouseEvent::MouseButtonPress ||
                               e->type() == QEvent::WindowActivate)) {
    qDebug() << "Reloading style from a file on an event!";
    QFile file("default.qss");
    file.open(QFile::ReadOnly);
    auto qapp = static_cast<QApplication *>(QApplication::instance());
    qapp->setStyleSheet(file.readAll());
    file.close();
  }
  return QObject::eventFilter(o, e);
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  //  this->setWindowFlags(Qt::FramelessWindowHint);
  //  this->setAttribute(Qt::WA_TranslucentBackground);

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
  auto *foo = new QWidget(this);
  splitter->addWidget(qtrv);
  splitter->addWidget(foo);

  auto fsmodel = new QFileSystemModel(this);
  QStringList filters;
  filters << "*.mp3"
          << "*.wav"
          << "*.ogg"
          << "*.flac";
  fsmodel->setRootPath("C:\\Users\\Marcin\\Desktop\\nagrania");
  fsmodel->setNameFilters(filters);
  auto idx = fsmodel->index("C:\\Users\\Marcin\\Desktop\\nagrania");

  auto *proxyModel = new MimeFilterProxyModel(this);
  // TODO: filter on mimetype
  proxyModel->setSourceModel(fsmodel);
  qtrv->setModel(proxyModel);
  qtrv->setRootIndex(proxyModel->mapFromSource(idx));
  resize(700, 480);
  mainWidget->installEventFilter(this);

  connect(qtrv, &QTreeView::doubleClicked,
          [proxyModel, fsmodel](const QModelIndex &index) {
            QMessageBox msgBox;
            msgBox.setText("The item has been double clicked.");
            auto const sourceIndex = proxyModel->mapToSource(index);
            auto fi = fsmodel->fileInfo(sourceIndex);
            QString fname = fi.filePath();
            QString str = "Do you want it to be double clicked? Path: " + fname;
            msgBox.setInformativeText(str);
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
          });
  /*


  QStringList headers;
  headers << tr("Artist") << tr("Title") << tr("Length");
  auto tandaTreeModel = new TandaTreeModel(headers, "", this);
  tandaTree->setModel(tandaTreeModel);
  insertRow(tandaTree);

  */
}

#include "mainwindow.h"
#include <QFileSystemModel>
#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMessageBox>
#include <QPushButton>
#include <QSplitter>
#include <QToolBar>
#include <QToolButton>
#include <QTreeView>
#include "common.h"
#include "controlswidget.h"
#include "displaywidget.h"
#include "tandatreemodel.h"
#include "wavewidget.h"

void insertRow(const QAbstractItemView *view) {
  //    const QModelIndex index = view.selectionModel()->currentIndex();
  QAbstractItemModel *model = view->model();

  if (!model->insertRows(0, 4)) {
    qDebug() << "InsertRows error!";
    exit(1);
    return;
  }

  for (int column = 0; column < model->columnCount(); ++column) {
    QModelIndex child = model->index(1, column);
    model->setData(child, QVariant("[No data]"), Qt::EditRole);
  }
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  //  this->setWindowFlags(Qt::FramelessWindowHint);
  //  this->setAttribute(Qt::WA_TranslucentBackground);

  auto mainWidget = new QWidget(this);
  auto mainLayout = new QVBoxLayout(mainWidget);
  mainLayout->setSpacing(0);
  mainLayout->setContentsMargins(0, 0, 0, 0);
  //  mainWidget->setLayout(mainLayout);
  setCentralWidget(mainWidget);

  //  auto splitter = new QSplitter(this);
  auto displayWidget = new DisplayWidget(this);
  auto waveWidget = new WaveWidget(this);
  auto controlsWidget = new ControlsWidget(this);
  mainLayout->addWidget(displayWidget, NOSTRETCH);
  mainLayout->addWidget(waveWidget, NOSTRETCH);
  mainLayout->addWidget(controlsWidget, NOSTRETCH);
  mainLayout->addStretch(STRETCH_HI);
  mainLayout->addSpacing(200);
  //  mainLayout->addWidget(splitter, 1);

  resize(700, 480);

  /*
  auto fsmodel = new QFileSystemModel(this);
  QStringList filters;
  filters << "*.mp3"
          << "*.wav"
          << "*.ogg";
  fsmodel->setRootPath(QDir::currentPath());
  fsmodel->setNameFilters(filters);

  auto fstree = new QTreeView(this);
  fstree->setModel(fsmodel);

  connect(fstree, &QTreeView::doubleClicked,
          [&fsmodel](const QModelIndex &index) {
            QMessageBox msgBox;
            msgBox.setText("The item has been double clicked.");
            QString fname = fsmodel->fileInfo(index).filePath();
            QString str = "Do you want it to be double clicked? Path: " + fname;
            msgBox.setInformativeText(str);
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
          });

  splitter->addWidget(fstree);

  auto tandaTree = new QTreeView(this);
  splitter->addWidget(tandaTree);

  QStringList headers;
  headers << tr("Artist") << tr("Title") << tr("Length");
  auto tandaTreeModel = new TandaTreeModel(headers, "", this);
  tandaTree->setModel(tandaTreeModel);
  insertRow(tandaTree);

  auto controlsToolBar = new QToolBar(tr("controls"), this);
  controlsToolBar->setObjectName("controlsToolBar");

  addToolBar(Qt::BottomToolBarArea, controlsToolBar);

  auto m_playButton = new QToolButton(this);
  m_playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

  controlsToolBar->addWidget(m_playButton);

  auto m_player = new QMediaPlayer(this);
  m_player->setAudioRole(QAudio::MusicRole);

  auto playlist = new QMediaPlaylist(m_player);
  playlist->addMedia(QUrl("C:/Users/Marcin/Desktop/nagrania/Zaus-Janis.mp3"));

  m_player->setPlaylist(playlist);

  //  QMediaPlayer::State m_playerState = QMediaPlayer::StoppedState;
  auto playClicked = [&, m_player]() {
    switch (m_player->state()) {
    case QMediaPlayer::StoppedState:
      [[fallthrough]];
    case QMediaPlayer::PausedState:
      m_player->play();
      break;
    case QMediaPlayer::PlayingState:
      qDebug() << "clicked pause";
      m_player->pause();
      break;
    }
  };
  connect(m_playButton, &QAbstractButton::clicked, playClicked);
  */
}

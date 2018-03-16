#include "mainwindow.h"
#include "tandatreemodel.h"
#include <QFileSystemModel>
#include <QTreeView>
#include <QHBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QSplitter>
#include <QToolButton>
#include <QToolBar>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QFileSystemModel *fsmodel = new QFileSystemModel(this);
    QStringList filters;
    filters << "*.mp3" << "*.wav" << "*.ogg";
    fsmodel->setRootPath(QDir::currentPath());
    fsmodel->setNameFilters(filters);
    QTreeView *fstree = new QTreeView(this);
    fstree->setModel(fsmodel);
    connect(fstree, &QTreeView::doubleClicked, [&fsmodel](const QModelIndex &index){
        QMessageBox msgBox;
        msgBox.setText("The item has been double clicked.");
        QString fname=fsmodel->fileInfo(index).filePath();
        QString str = "Do you want it to be double clicked? Path: " + fname;
        msgBox.setInformativeText(str);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    });

    QSplitter *mainLayout = new QSplitter(this);

    mainLayout->addWidget(fstree);

    QTreeView *tandaTree = new QTreeView(this);
    TreeModel *tandaTreeModel = new TreeModel("", this);
    tandaTree->setModel(tandaTreeModel);

    mainLayout->addWidget(tandaTree);

    setCentralWidget(mainLayout);

    QToolBar *controlsToolBar = new QToolBar(tr("controls"), this);
    controlsToolBar->setObjectName("controlsToolBar");

    controlsToolBar->setAllowedAreas(Qt::TopToolBarArea
                                     | Qt::BottomToolBarArea);
    addToolBar(controlsToolBar);

    QAbstractButton *m_playButton = nullptr;
    m_playButton = new QToolButton(this);
    m_playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    controlsToolBar->addWidget(m_playButton);

    QMediaPlayer *m_player;
    m_player = new QMediaPlayer(this);
    m_player->setAudioRole(QAudio::MusicRole);

    QMediaPlaylist* playlist = new QMediaPlaylist(m_player);
    playlist->addMedia(QUrl("C:/Users/Marcin/Desktop/Zaus-Janis.mp3"));

    m_player->setPlaylist(playlist);

    QMediaPlayer::State m_playerState = QMediaPlayer::StoppedState;
    auto playClicked = [&, m_player]()
    {
        switch (m_player->state()) {
        case QMediaPlayer::StoppedState:
            [[fallthrough]];
        case QMediaPlayer::PausedState:
            m_player->play();
            break;
        case QMediaPlayer::PlayingState:
            qDebug()<<"clicked pause";
            m_player->pause();
            break;
        }
    };
    connect(m_playButton, &QAbstractButton::clicked, playClicked);

}

MainWindow::~MainWindow()
{

}

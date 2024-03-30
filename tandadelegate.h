#ifndef TANDADELEGATE
#define TANDADELEGATE

#include <QApplication>
#include <QComboBox>
#include <QDebug>
#include <QString>
#include <QStyledItemDelegate>

#include "wavewidget.h" //TODO remove
class TandaDelegate : public QStyledItemDelegate
{

public:
    TandaDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent){};

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override
    {
        const QString text = QString::number(index.row() + 1) + " : tanda -";
        auto *button = new QPushButton(nullptr);
        button->setObjectName("tandaButton");
        button->setStyleSheet("-qt-user-state: clear;");
        QMainWindow *mainWindow{};
        auto list = QApplication::topLevelWidgets();
        for (QWidget *w : list)
        {
            mainWindow = qobject_cast<QMainWindow *>(w);
            if (mainWindow)
                break;
        }
        auto *ww = mainWindow->findChild<WaveWidget *>("WaveWidget");
        if (ww && ww->layout())
            ww->layout()->addWidget(button);
        button->hide();

        QStyleOptionButton style;
        style.initFrom(button);
        style.rect = QRect(option.rect);
        style.text = text;
        style.state = QStyle::State_Enabled;
        (QApplication::style())->drawControl(QStyle::CE_PushButton, &style, painter, button);
        qDebug() << "painted " << index.row();
    };
};

class PlaylistModel : public QAbstractListModel
{
    Q_OBJECT

public:
    PlaylistModel(QObject *parent = nullptr) : QAbstractListModel(parent){};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override
    {
        return 15;
    }
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override
    {
        return QVariant();
    }
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
    {
        return QVariant();
    }
};

#endif /* TANDADELEGATE */
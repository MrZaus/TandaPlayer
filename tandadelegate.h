#ifndef TANDADELEGATE
#define TANDADELEGATE

#include <QApplication>
#include <QComboBox>
#include <QDebug>
#include <QPainter>
#include <QString>
#include <QStyledItemDelegate>

#include "tandawidget.h"

class TandaDelegate : public QStyledItemDelegate
{

public:
    TandaDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent){};
    // TODO rule of 5
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override
    {
        auto options = option;
        initStyleOption(&options, index);

        painter->save();

        QPixmap pixmap(option.rect.size());
        TandaWidget tandaWidget;
        tandaWidget.setGeometry(option.rect);
        tandaWidget.render(&pixmap);
        painter->drawPixmap(option.rect, pixmap);
        painter->restore();
        qDebug()
            << "painted " << index.row();
    };

    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        qDebug() << "createEditor " << index.row();
        return new TandaWidget(parent);
    }

    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        return TandaWidget(nullptr).sizeHint();
    }

private:
    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const override
    {
        // TODO static_cast<TandaWidget *>(editor)->data(index.data());
    }

    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        static_cast<TandaWidget *>(editor)->setGeometry(option.rect);
    }

    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override
    {
        // TODO model->setData(index, static_cast<TandaWidget *>(editor)->data());
    }

    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override
    {
        qDebug() << "editorEvent " << index.row();
        return QStyledItemDelegate::editorEvent(event, model, option, index);
    }

    TandaWidget tandaWidget;
};

class PlaylistModel : public QAbstractListModel // TODO move to playlistmodel.h
{
    Q_OBJECT

public:
    PlaylistModel(QObject *parent = nullptr) : QAbstractListModel(parent){};
    int rowCount(const QModelIndex &parent = QModelIndex()) const override
    {
        return 4;
    }
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override
    {
        return QVariant(); // TODO implement
    }
    Qt::ItemFlags flags(const QModelIndex &index) const override
    {
        return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled;
    }
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
    {
        return QVariant(); // TODO implement
    }
};

#endif /* TANDADELEGATE */
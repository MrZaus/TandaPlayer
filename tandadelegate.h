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
    Q_OBJECT
public:
    TandaDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {};
    // TODO rule of 5
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override
    {
        auto options = option;
        initStyleOption(&options, index);

        painter->save();

        QPixmap pixmap(option.rect.size());
        TandaWidget tandaWidget;
        tandaWidget.setTandaType(index.data(std::to_underlying((TPRoles::TypeRole))).value<std::string>());
        tandaWidget.setTandaSize(index.data(std::to_underlying((TPRoles::SizeRole))).value<std::uint8_t>());
        tandaWidget.setGeometry(option.rect);
        tandaWidget.render(&pixmap);
        painter->drawPixmap(option.rect, pixmap);
        painter->restore();
    };

    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
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
        return QStyledItemDelegate::editorEvent(event, model, option, index);
    }

    TandaWidget tandaWidget;
};

#endif /* TANDADELEGATE */
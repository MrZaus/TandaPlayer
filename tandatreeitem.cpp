#include "tandatreeitem.h"
#include <QStringList>

TandaTreeItem::TandaTreeItem(const QVector<QVariant> &data, TandaTreeItem *parent)
{
    parentItem = parent;
    itemData = data;
}

TandaTreeItem::~TandaTreeItem()
{
    qDeleteAll(childItems);
}

TandaTreeItem *TandaTreeItem::child(int number)
{
    return childItems.value(number);
}

int TandaTreeItem::childCount() const
{
    return childItems.count();
}

int TandaTreeItem::childNumber() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<TandaTreeItem*>(this));

    return 0;
}

int TandaTreeItem::columnCount() const
{
    return itemData.count();
}

QVariant TandaTreeItem::data(int column) const
{
    return itemData.value(column);
}

bool TandaTreeItem::insertChildren(int position, int count, int columns)
{
    if (position < 0 || position > childItems.size())
        return false;

    for (int row = 0; row < count; ++row) {
        QVector<QVariant> data(columns);
        TandaTreeItem *item = new TandaTreeItem(data, this);
        childItems.insert(position, item);
    }

    return true;
}

bool TandaTreeItem::insertColumns(int position, int columns)
{
    if (position < 0 || position > itemData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        itemData.insert(position, QVariant());

    foreach (TandaTreeItem *child, childItems)
        child->insertColumns(position, columns);

    return true;
}

TandaTreeItem *TandaTreeItem::parent()
{
    return parentItem;
}

bool TandaTreeItem::removeChildren(int position, int count)
{
    if (position < 0 || position + count > childItems.size())
        return false;

    for (int row = 0; row < count; ++row)
        delete childItems.takeAt(position);

    return true;
}

bool TandaTreeItem::removeColumns(int position, int columns)
{
    if (position < 0 || position + columns > itemData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        itemData.remove(position);

    foreach (TandaTreeItem *child, childItems)
        child->removeColumns(position, columns);

    return true;
}

bool TandaTreeItem::setData(int column, const QVariant &value)
{
    if (column < 0 || column >= itemData.size())
        return false;

    itemData[column] = value;
    return true;
}

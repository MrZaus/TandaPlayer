#ifndef TANDATREEITEM_H
#define TANDATREEITEM_H

#include <QList>
#include <QVariant>

class TandaTreeItem
{
public:
  explicit TandaTreeItem(const QVector<QVariant> &data,
                         TandaTreeItem *parent = nullptr);
  ~TandaTreeItem();

  TandaTreeItem *child(int number);
  int childCount() const;
  int columnCount() const;
  QVariant data(int column) const;
  bool insertChildren(int position, int count, int columns);
  bool insertColumns(int position, int columns);
  TandaTreeItem *parent();
  bool removeChildren(int position, int count);
  bool removeColumns(int position, int columns);
  int childNumber() const;
  bool setData(int column, const QVariant &value);

private:
  QList<TandaTreeItem *> childItems;
  QVector<QVariant> itemData;
  TandaTreeItem *parentItem;
};

#endif // TANDATREEITEM_H

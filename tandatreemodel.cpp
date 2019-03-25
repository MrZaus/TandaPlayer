#include <QtWidgets>

#include "tandatreeitem.h"
#include "tandatreemodel.h"

TandaTreeModel::TandaTreeModel(const QStringList &headers, const QString &data,
                               QObject *parent)
    : QAbstractItemModel(parent) {
  QVector<QVariant> rootData;
  foreach (QString header, headers)
    rootData << header;

  rootItem = new TandaTreeItem(rootData);
  setupModelData(data.split(QString("\n")), rootItem);
}

TandaTreeModel::~TandaTreeModel() { delete rootItem; }

int TandaTreeModel::columnCount(const QModelIndex & /* parent */) const {
  return rootItem->columnCount();
}

QVariant TandaTreeModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) return QVariant();

  if (role != Qt::DisplayRole && role != Qt::EditRole) return QVariant();

  TandaTreeItem *item = getItem(index);

  return item->data(index.column());
}

Qt::ItemFlags TandaTreeModel::flags(const QModelIndex &index) const {
  if (!index.isValid()) return nullptr;

  return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

TandaTreeItem *TandaTreeModel::getItem(const QModelIndex &index) const {
  if (index.isValid()) {
    TandaTreeItem *item = static_cast<TandaTreeItem *>(index.internalPointer());
    if (item) return item;
  }
  return rootItem;
}

QVariant TandaTreeModel::headerData(int section, Qt::Orientation orientation,
                                    int role) const {
  if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    return rootItem->data(section);

  return QVariant();
}

QModelIndex TandaTreeModel::index(int row, int column,
                                  const QModelIndex &parent) const {
  if (parent.isValid() && parent.column() != 0) return QModelIndex();

  TandaTreeItem *parentItem = getItem(parent);

  TandaTreeItem *childItem = parentItem->child(row);
  if (childItem)
    return createIndex(row, column, childItem);
  else
    return QModelIndex();
}

bool TandaTreeModel::insertColumns(int position, int columns,
                                   const QModelIndex &parent) {
  bool success;

  beginInsertColumns(parent, position, position + columns - 1);
  success = rootItem->insertColumns(position, columns);
  endInsertColumns();

  return success;
}

bool TandaTreeModel::insertRows(int position, int rows,
                                const QModelIndex &parent) {
  TandaTreeItem *parentItem = getItem(parent);
  bool success;

  beginInsertRows(parent, position, position + rows - 1);
  success = parentItem->insertChildren(position, rows, rootItem->columnCount());
  endInsertRows();

  return success;
}

QModelIndex TandaTreeModel::parent(const QModelIndex &index) const {
  if (!index.isValid()) return QModelIndex();

  TandaTreeItem *childItem = getItem(index);
  TandaTreeItem *parentItem = childItem->parent();

  if (parentItem == rootItem) return QModelIndex();

  return createIndex(parentItem->childNumber(), 0, parentItem);
}

bool TandaTreeModel::removeColumns(int position, int columns,
                                   const QModelIndex &parent) {
  bool success;

  beginRemoveColumns(parent, position, position + columns - 1);
  success = rootItem->removeColumns(position, columns);
  endRemoveColumns();

  if (rootItem->columnCount() == 0) removeRows(0, rowCount());

  return success;
}

bool TandaTreeModel::removeRows(int position, int rows,
                                const QModelIndex &parent) {
  TandaTreeItem *parentItem = getItem(parent);
  bool success = true;

  beginRemoveRows(parent, position, position + rows - 1);
  success = parentItem->removeChildren(position, rows);
  endRemoveRows();

  return success;
}

int TandaTreeModel::rowCount(const QModelIndex &parent) const {
  TandaTreeItem *parentItem = getItem(parent);

  return parentItem->childCount();
}

bool TandaTreeModel::setData(const QModelIndex &index, const QVariant &value,
                             int role) {
  if (role != Qt::EditRole) return false;

  TandaTreeItem *item = getItem(index);
  bool result = item->setData(index.column(), value);

  if (result) emit dataChanged(index, index);

  return result;
}

bool TandaTreeModel::setHeaderData(int section, Qt::Orientation orientation,
                                   const QVariant &value, int role) {
  if (role != Qt::EditRole || orientation != Qt::Horizontal) return false;

  bool result = rootItem->setData(section, value);

  if (result) emit headerDataChanged(orientation, section, section);

  return result;
}

void TandaTreeModel::setupModelData(const QStringList &lines,
                                    TandaTreeItem *parent) {
  QList<TandaTreeItem *> parents;
  QList<int> indentations;
  parents << parent;
  indentations << 0;

  int number = 0;

  while (number < lines.count()) {
    int position = 0;
    while (position < lines[number].length()) {
      if (lines[number].at(position) != ' ') break;
      ++position;
    }

    QString lineData = lines[number].mid(position).trimmed();

    if (!lineData.isEmpty()) {
      // Read the column data from the rest of the line.
      QStringList columnStrings = lineData.split("\t", QString::SkipEmptyParts);
      QVector<QVariant> columnData;
      for (int column = 0; column < columnStrings.count(); ++column)
        columnData << columnStrings[column];

      if (position > indentations.last()) {
        // The last child of the current parent is now the new parent
        // unless the current parent has no children.

        if (parents.last()->childCount() > 0) {
          parents << parents.last()->child(parents.last()->childCount() - 1);
          indentations << position;
        }
      } else {
        while (position < indentations.last() && parents.count() > 0) {
          parents.pop_back();
          indentations.pop_back();
        }
      }

      // Append a new item to the current parent's list of children.
      TandaTreeItem *parent = parents.last();
      parent->insertChildren(parent->childCount(), 1, rootItem->columnCount());
      for (int column = 0; column < columnData.size(); ++column)
        parent->child(parent->childCount() - 1)
            ->setData(column, columnData[column]);
    }

    ++number;
  }
}

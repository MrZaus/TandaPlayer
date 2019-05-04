#include "mimefilterproxymodel.h"
#include <QFileSystemModel>
#include <QMimeData>
#include <QMimeDatabase>

MimeFilterProxyModel::MimeFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent) {}

bool MimeFilterProxyModel::filterAcceptsRow(
    int sourceRow, const QModelIndex &sourceParent) const {
  const auto index = sourceModel()->index(sourceRow, 0, sourceParent);
  const auto fileSysModel = static_cast<QFileSystemModel *>(sourceModel());
  const auto filePath = fileSysModel->filePath(index);
  const auto mimeType = QMimeDatabase().mimeTypeForFile(QFileInfo(filePath));
  return mimeType.name().contains("audio") ||
         mimeType.inherits("inode/directory");
}

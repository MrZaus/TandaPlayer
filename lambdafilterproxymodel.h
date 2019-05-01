#ifndef LAMBDAFILTERPROXYMODEL_H
#define LAMBDAFILTERPROXYMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

class LambdaFilterProxyModel : public QSortFilterProxyModel {
 public:
  LambdaFilterProxyModel(QObject *parent = nullptr);

 protected:
  bool filterAcceptsRow(int sourceRow,
                        const QModelIndex &sourceParent) const override;
};

#endif  // LAMBDAFILTERPROXYMODEL_H

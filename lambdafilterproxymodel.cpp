#include "lambdafilterproxymodel.h"

LambdaFilterProxyModel::LambdaFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent) {}

bool LambdaFilterProxyModel::filterAcceptsRow(
    int sourceRow, const QModelIndex &sourceParent) const {}

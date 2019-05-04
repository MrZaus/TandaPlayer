#ifndef LAMBDAFILTERPROXYMODEL_H
#define LAMBDAFILTERPROXYMODEL_H
#include <QObject>
#include <QSortFilterProxyModel>

class MimeFilterProxyModel : public QSortFilterProxyModel {
 protected:
  bool filterAcceptsRow(int sourceRow,
                        const QModelIndex &sourceParent) const override;
  std::function<bool()> predicate;

 public:
  MimeFilterProxyModel(QObject *parent = nullptr);
  template <typename F>
  void setPredicate(const F &f);

  //  void setPredicate(std::function<bool()> pred) { predicate = pred; }
};

#endif  // LAMBDAFILTERPROXYMODEL_H

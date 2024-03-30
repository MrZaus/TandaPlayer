#ifndef TANDAWIDGET_H
#define TANDAWIDGET_H

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QTreeView>
#include <QVBoxLayout>

class TandaWidget : public QFrame
{
    Q_OBJECT
public:
    explicit TandaWidget(QWidget *parent = nullptr);
    ~TandaWidget() override = default;
    TandaWidget(const TandaWidget &) = delete;
    TandaWidget &operator=(const TandaWidget &) = delete;
    TandaWidget(TandaWidget &&) = delete;
    TandaWidget &operator=(TandaWidget &&) = delete;
signals:

public slots:
private:
    QVBoxLayout layout;
    QHBoxLayout headerLayout;
    QLabel tandaTypeLabel;
    QSpinBox tandaSizeSpinBox;
    QLabel tandaTotalTimeLabel;
    QTreeView tandaItemsWidget;
};

#endif // TANDAWIDGET_H
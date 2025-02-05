#ifndef TANDAWIDGET_H
#define TANDAWIDGET_H

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QSpinBox>
#include <QVBoxLayout>
#include <cstdint>
#include <qboxlayout.h>
#include <qframe.h>
#include <qlabel.h>
#include <qlistwidget.h>
#include <qspinbox.h>
#include <qtmetamacros.h>
#include <qwidget.h>
#include <string>
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

    void setTandaType(std::string type);
    void setTandaSize(std::uint8_t size);
signals:

public slots:
private:
    QVBoxLayout layout;
    QHBoxLayout headerLayout;
    QLabel tandaTypeLabel;
    QSpinBox tandaSizeSpinBox;
    QLabel tandaTotalTimeLabel;
    QListWidget tandaItemsWidget;
};

#endif // TANDAWIDGET_H
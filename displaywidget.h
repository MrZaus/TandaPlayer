#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

class DisplayWidget : public QFrame
{
  Q_OBJECT
public:
  explicit DisplayWidget(QWidget *parent = nullptr);
  ~DisplayWidget() override = default;
  DisplayWidget(const DisplayWidget &) = delete;
  DisplayWidget &operator=(const DisplayWidget &) = delete;
  DisplayWidget(DisplayWidget &&) = delete;
  DisplayWidget &operator=(DisplayWidget &&) = delete;
signals:

public slots:
private:
  QHBoxLayout layout;
  QVBoxLayout trackDurationLayout;
  QVBoxLayout tandaInfoLayout;
  QLabel elapsedTimeLabel;
  QLabel trackDurationLabel;
  QLabel timeLeftLabel;
  QLabel artistLabel;
  QLabel titleLabel;
  QLabel tandaTimeLeftLabel;
  QLabel tandaIndexLabel;
};

#endif // DISPLAYWIDGET_H

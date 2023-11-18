#ifndef WAVEWIDGET_H
#define WAVEWIDGET_H

#include <QFrame>

constexpr int MAX_HEIGHT = 52;
constexpr int MIN_HEIGHT = MAX_HEIGHT;

class WaveWidget : public QFrame
{
  Q_OBJECT
public:
  explicit WaveWidget(QWidget *parent = nullptr) : QFrame(parent)
  {
    setMaximumHeight(MAX_HEIGHT);
    setMinimumHeight(MIN_HEIGHT);
  }
  virtual ~WaveWidget() = default;
signals:

public slots:
private:
};

#endif // WAVEWIDGET_H
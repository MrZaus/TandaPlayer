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
  ~WaveWidget() override = default;
  WaveWidget(const WaveWidget &) = delete;
  WaveWidget &operator=(const WaveWidget &) = delete;
  WaveWidget(WaveWidget &&) = delete;
  WaveWidget &operator=(WaveWidget &&) = delete;
signals:

public slots:
private:
};

#endif // WAVEWIDGET_H
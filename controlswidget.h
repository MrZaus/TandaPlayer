#ifndef CONTROLSWIDGET_H
#define CONTROLSWIDGET_H

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

class ControlsWidget : public QFrame {
  Q_OBJECT
 public:
  explicit ControlsWidget(QWidget *parent = nullptr);

 signals:

 public slots:
 private:
  QHBoxLayout layout;
  QLabel logoLabel;
  QPixmap logo;
  QHBoxLayout buttons;
  QPushButton playButton;
  QPushButton stopButton;
  QPushButton prevButton;
  QPushButton nextButton;
};

#endif  // CONTROLSWIDGET_H

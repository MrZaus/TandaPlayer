#include "controlswidget.h"

namespace {

constexpr int MAX_HEIGHT = 70;
constexpr int MIN_HEIGHT = MAX_HEIGHT;
const QString LOGO_PATH(":/img/logo.png");
}  // namespace

ControlsWidget::ControlsWidget(QWidget *parent)
    : QFrame(parent), layout(this), logo(LOGO_PATH) {
  setMaximumHeight(MAX_HEIGHT);
  setMinimumHeight(MIN_HEIGHT);

  playButton.setObjectName("playButton");
  stopButton.setObjectName("stopButton");
  prevButton.setObjectName("prevButton");
  nextButton.setObjectName("nextButton");
  buttons.setObjectName("buttons");
  logoLabel.setPixmap(logo);
  buttons.addWidget(&prevButton);
  buttons.addWidget(&stopButton);
  buttons.addWidget(&playButton);
  buttons.addWidget(&nextButton);
  layout.addLayout(&buttons);
  layout.addWidget(&logoLabel);

  layout.setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
  logoLabel.show();
}

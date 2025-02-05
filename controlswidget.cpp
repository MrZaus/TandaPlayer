#include "controlswidget.h"
#include "common.h"
#include <QtCore/Qt>

namespace
{

  constexpr int MAX_HEIGHT = 70;
  constexpr int MIN_HEIGHT = MAX_HEIGHT;
  const QString LOGO_PATH(":/img/logo.png");
} // namespace

ControlsWidget::ControlsWidget(QWidget *parent)
    : QFrame(parent), layout(this), logo(LOGO_PATH)
{
  setMaximumHeight(MAX_HEIGHT);
  setMinimumHeight(MIN_HEIGHT);

  playButton.setObjectName("playButton");
  stopButton.setObjectName("stopButton");
  prevButton.setObjectName("prevButton");
  nextButton.setObjectName("nextButton");
  buttons.setObjectName("buttons");
  logoLabel.setPixmap(logo);
  constexpr auto LogoWidth = 278U;
  logoLabel.setFixedWidth(LogoWidth);
  buttons.addWidget(&prevButton);
  buttons.addWidget(&stopButton);
  buttons.addWidget(&playButton);
  buttons.addWidget(&nextButton);
  buttons.setAlignment(Qt::AlignLeft);
  layout.addLayout(&buttons);
  layout.addStretch(STRETCH::HI);

  layout.addWidget(&logoLabel, Qt::AlignCenter);
  layout.addStretch(STRETCH::MID);
  layout.addStretch(STRETCH::MID);

  layout.setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
  logoLabel.show();
}

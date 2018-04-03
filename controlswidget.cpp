#include "controlswidget.h"

namespace {

constexpr int MAX_HEIGHT = 70;
constexpr int MIN_HEIGHT = MAX_HEIGHT;
const QString LOGO_PATH(":/img/logo.png");
}

ControlsWidget::ControlsWidget(QWidget *parent)
    : QFrame(parent), layout(this), logo(LOGO_PATH) {
  setMaximumHeight(MAX_HEIGHT);
  setMinimumHeight(MIN_HEIGHT);
  logoLabel.setPixmap(logo);
  layout.addWidget(&logoLabel);
  layout.setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
  //  logoLabel.show();
}

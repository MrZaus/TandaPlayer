#include "displaywidget.h"
#include "common.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

namespace {
const QString TIME_NA("00:00");
const QString INDEX_NA("0/0");
const QString UNKNOWN("unknown");
constexpr int MAX_HEIGHT = 70;
constexpr int MIN_HEIGHT = MAX_HEIGHT;
}

DisplayWidget::DisplayWidget(QWidget *parent)
    : QFrame(parent),
      elapsedTimeLabel(TIME_NA),
      trackDurationLabel(TIME_NA),
      timeLeftLabel(TIME_NA),
      artistLabel(UNKNOWN),
      titleLabel(UNKNOWN),
      tandaTimeLeftLabel(TIME_NA),
      tandaIndexLabel(INDEX_NA) {
  setMaximumHeight(MAX_HEIGHT);
  setMinimumHeight(MIN_HEIGHT);

  elapsedTimeLabel.setObjectName("elapsedTimeLabel");
  trackDurationLabel.setObjectName("trackDurationLabel");
  timeLeftLabel.setObjectName("timeLeftLabel");
  artistLabel.setObjectName("artistLabel");
  titleLabel.setObjectName("titleLabel");
  tandaIndexLabel.setObjectName("tandaIndexLabel");
  tandaTimeLeftLabel.setObjectName("tandaTimeLeftLabel");

  trackDurationLayout.setSpacing(0);
  trackDurationLayout.addWidget(&elapsedTimeLabel, NOSTRETCH);
  trackDurationLayout.addWidget(&trackDurationLabel, NOSTRETCH);
  trackDurationLayout.addStretch(STRETCH_HI);
  trackDurationLayout.setContentsMargins(0, 0, 0, 0);

  tandaInfoLayout.addWidget(&tandaIndexLabel);
  tandaInfoLayout.addWidget(&tandaTimeLeftLabel);
  tandaInfoLayout.setAlignment(Qt::AlignRight);

  layout.setContentsMargins(0, 0, 0, 0);
  layout.setSpacing(0);
  layout.addLayout(&trackDurationLayout, NOSTRETCH);
  layout.addWidget(&timeLeftLabel, NOSTRETCH);
  layout.addStretch(STRETCH_HI);
  layout.addWidget(&artistLabel, STRETCH_LOW);
  layout.addWidget(&titleLabel, STRETCH_LOW);
  layout.addStretch(STRETCH_HI);
  layout.addLayout(&tandaInfoLayout, NOSTRETCH);

  setLayout(&layout);
}

#include "displaywidget.h"
#include "common.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

namespace {
const QString TIME_NA("00:00");
const QString INDEX_NA("0/0");
const QString UNKNOWN("unknown");
namespace HEIGHT {
constexpr int MAX = 70;
constexpr int MIN = MAX;
}  // namespace HEIGHT
}  // namespace

DisplayWidget::DisplayWidget(QWidget *parent)
    : QFrame(parent),
      elapsedTimeLabel(TIME_NA),
      trackDurationLabel(TIME_NA),
      timeLeftLabel(TIME_NA),
      artistLabel(UNKNOWN),
      titleLabel(UNKNOWN),
      tandaTimeLeftLabel(TIME_NA),
      tandaIndexLabel(INDEX_NA) {
  setMaximumHeight(HEIGHT::MAX);
  setMinimumHeight(HEIGHT::MIN);

  elapsedTimeLabel.setObjectName("elapsedTimeLabel");
  trackDurationLabel.setObjectName("trackDurationLabel");
  timeLeftLabel.setObjectName("timeLeftLabel");
  artistLabel.setObjectName("artistLabel");
  titleLabel.setObjectName("titleLabel");
  tandaIndexLabel.setObjectName("tandaIndexLabel");
  tandaTimeLeftLabel.setObjectName("tandaTimeLeftLabel");

  trackDurationLayout.addWidget(&elapsedTimeLabel, STRETCH::NO);
  trackDurationLayout.addWidget(&trackDurationLabel, STRETCH::NO);
  trackDurationLayout.setSpacing(0);
  trackDurationLayout.setMargin(0);

  tandaInfoLayout.setAlignment(Qt::AlignRight);
  tandaInfoLayout.addWidget(&tandaIndexLabel);
  tandaInfoLayout.addWidget(&tandaTimeLeftLabel);
  tandaInfoLayout.setAlignment(Qt::AlignRight);
  tandaInfoLayout.setSpacing(0);
  tandaInfoLayout.setMargin(0);

  layout.setContentsMargins(0, 0, 0, 0);
  layout.setSpacing(0);
  layout.addLayout(&trackDurationLayout, STRETCH::NO);
  layout.addWidget(&timeLeftLabel, STRETCH::NO);
  layout.addStretch(STRETCH::HI);
  layout.addWidget(&artistLabel, STRETCH::LOW);
  layout.addWidget(&titleLabel, STRETCH::LOW);
  layout.addStretch(STRETCH::HI);
  layout.addLayout(&tandaInfoLayout, STRETCH::NO);

  setLayout(&layout);
}

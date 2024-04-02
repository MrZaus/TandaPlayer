#include "tandawidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

#include "common.h"

TandaWidget::TandaWidget(QWidget *parent) : QFrame(parent), layout(this)
{
    // this->set
    headerLayout.setObjectName("tandaHeader");
    tandaTypeLabel.setObjectName("tandaTypeLabel");
    tandaTypeLabel.setText("Tangos");
    headerLayout.addWidget(&tandaTypeLabel);
    headerLayout.addStretch(STRETCH::MID);
    headerLayout.addWidget(&tandaSizeSpinBox);
    tandaSizeSpinBox.setObjectName("tandaSizeSpinBox");
    tandaSizeSpinBox.setValue(4);
    tandaTotalTimeLabel.setObjectName("tandaTotalTimeLabel");
    tandaTotalTimeLabel.setText("00:00");
    headerLayout.addWidget(&tandaTotalTimeLabel);
    layout.addLayout(&headerLayout);

    layout.addWidget(&tandaItemsWidget);
    tandaItemsWidget.addItem("Hello World");
}

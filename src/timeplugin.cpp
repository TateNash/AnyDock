#include "timeplugin.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QTime>

TimePlugin::TimePlugin(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

    timeLabel = new QLabel(this);
    timeLabel->setText("00:00:00");
    timeLabel->setStyleSheet("color: white;font-size: 50pt;");
    
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TimePlugin::updateTime);
    timer->start(1000);
    
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(timeLabel);
    setLayout(layout);
}

void TimePlugin::updateTime()
{
    timeLabel->setText(QTime::currentTime().toString("hh:mm:ss"));
}
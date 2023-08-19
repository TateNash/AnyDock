#include "timeplugin.h"

#include <QGuiApplication>
#include <QScreen>
#include <QHBoxLayout>
#include <QTime>

TimePlugin::TimePlugin(QWidget *parent)
    : QWidget(parent),
    m_timeLabel(new QLabel(this)),
    m_timer(new QTimer(this)),
    m_menu(new QMenu(this))
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::SubWindow);
    setAttribute(Qt::WA_TranslucentBackground);
    setCursor(Qt::OpenHandCursor);

    m_timeLabel->setText("00:00");
    m_timeLabel->setStyleSheet("color: white;font-size: 50pt;");
    
    connect(m_timer, &QTimer::timeout, this, &TimePlugin::updateTime);
    m_timer->start(1000);
    
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(m_timeLabel);
    setLayout(layout);

    InitMenu();
    
    hide();
}

void TimePlugin::InitMenu()
{
    QAction *exitAction = new QAction(tr("Exit"), this);
    connect(exitAction, &QAction::triggered, this, &TimePlugin::close);
    m_menu->addAction(exitAction);
    m_timeLabel->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(m_timeLabel, &QLabel::customContextMenuRequested, [=](){
        m_menu->exec(QCursor::pos());
    });
}

void TimePlugin::updateTime()
{
    m_timeLabel->setText(QTime::currentTime().toString("hh:mm"));
}
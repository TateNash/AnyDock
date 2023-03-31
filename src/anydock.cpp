#include "anydock.h"
#include "timeplugin.h"
#include "mousedragger.h"
#include <QDockWidget>
#include <QScreen>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include <QDebug>
#include <QApplication>
#include <QGraphicsItem>

AnyDock::AnyDock(QWidget *parent)
    : QMainWindow(parent), m_time(new TimePlugin), m_menu(new QMenu("File", this))
{
    ui.setupUi(this);
    m_time->hide();

    InitMainWindows();
    InitPara();

    QAction *act_time = new QAction(tr("Time"));
    connect(act_time, &QAction::triggered, this, &AnyDock::createDigitalClock);
    m_menu->addAction(act_time); 

    MouseDragger *mouseDragger = new MouseDragger(m_time);
}

AnyDock::~AnyDock()
{
}

void AnyDock::InitMainWindows()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    qreal scale = screen->logicalDotsPerInch() / 96.0;
    QSize screenSize = screen->size();
    resize(QSize(int(screenSize.width() * 0.4 / scale), int(screenSize.height() * 0.4 / scale)));   
}

void AnyDock::InitPara()
{
    m_time->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::SubWindow);
    m_time->setAttribute(Qt::WA_TranslucentBackground);
    m_time->setGeometry(100, 100, 200, 200);
    m_time->setCursor(Qt::OpenHandCursor);

    // 设置菜单
    QAction *exitAction = new QAction(tr("Exit"), this);
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
    m_menu->addAction(exitAction);
}

void AnyDock::createDigitalClock()
{
    m_time->show();
}

void AnyDock::closeEvent(QCloseEvent *event)
{
    event->ignore();
    hide();
    QSystemTrayIcon *back{new QSystemTrayIcon(this)};
    back->setIcon(QIcon(":/icon/exe.png"));
    back->show();

    QMenu *menu = new QMenu(this);
    QAction *exitAction = new QAction(tr("Exit"), this);
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
    menu->addAction(exitAction);

    back->setContextMenu(menu);
}

void AnyDock::contextMenuEvent(QContextMenuEvent* event)
{
    m_menu->exec(event->globalPos());
}
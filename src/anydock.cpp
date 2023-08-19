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
#include <QMimeData>
#include <QGraphicsItem>
#include <QDir>
#include <QLabel>
#include <QPainter>
#include <QPoint>
#include <QDesktopServices>
#include <QFileIconProvider>
#include <QHBoxLayout>
#include <QListView>
#include <QToolButton>
#include <QDrag>

AnyDock::AnyDock(QWidget *parent)
    : QMainWindow(parent), 
    m_menu(new QMenu),
    m_time(new TimePlugin),
    m_screenWidth(QGuiApplication::primaryScreen()->availableGeometry().width()),
    m_screenHeight(QGuiApplication::primaryScreen()->availableGeometry().height())
{
    ui.setupUi(this);

    InitMainWindows();
    InitListWidget();
    InitPara();

    MouseDragger *mouseDragger = new MouseDragger(m_time);
}

AnyDock::~AnyDock()
{
}

void AnyDock::InitMainWindows()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    qreal scale = screen->logicalDotsPerInch() / 96.0;
    setGeometry(m_screenWidth / 6, m_screenHeight * 7 / 9, 
                m_screenWidth * 2 / 3 / scale, m_screenHeight / 9);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setStatusBar(nullptr);

    // 托盘图标
    QSystemTrayIcon *back{new QSystemTrayIcon(this)};
    back->setIcon(QIcon(":/icon/exe.png"));
    back->show();

    QMenu *menu = new QMenu(this);
    QAction *exitAction = new QAction(tr("Exit"), this);
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
    menu->addAction(exitAction);

    back->setContextMenu(menu);
    setAcceptDrops(true);
}

void AnyDock::InitListWidget()
{
    QWidget *shortcutContainer = new QWidget(this);
    shortcutContainer->setStyleSheet("background-color: #fff; border-radius: 10px;");
    m_shortcutLayout = new QHBoxLayout(shortcutContainer);
    m_shortcutLayout->setContentsMargins(10, 10, 10, 10);
    m_shortcutLayout->setSpacing(2);
    setCentralWidget(shortcutContainer);
}

void AnyDock::InitPara()
{
    // 设置菜单
    QAction *act_time = new QAction(tr("Time"));
    connect(act_time, &QAction::triggered, this, [&](){
        m_time->adjustSize();
        m_time->move((m_screenWidth - m_time->width())/ 2, (m_screenHeight - m_time->height()) / 2);
        m_time->show();
    });
    
    QAction *exitAction = new QAction(tr("Exit"));
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
    m_menu->addAction(act_time);
    m_menu->addAction(exitAction);
}

void AnyDock::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true); //设置抗锯齿
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawRoundedRect(rect(), 10, 10); //绘制圆角矩形
}

void AnyDock::contextMenuEvent(QContextMenuEvent* event)
{
    m_menu->exec(event->globalPos());
}

void AnyDock::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls()) 
    {
        event->acceptProposedAction();
    }
}

void AnyDock::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    foreach(QUrl url, urls) 
    {
        QString filePath = url.toLocalFile();
        QFileIconProvider iconProvider;
        QIcon icon = iconProvider.icon(QFileInfo(filePath));
        QString targetFilePath = QFileInfo(filePath).symLinkTarget();

        // 创建一个新的QToolButton并设置图标和文字
        QToolButton *button = new QToolButton;
        button->setIcon(icon);
        button->setIconSize(QSize(50, 50)); // 设置图标大小
        button->setText(QFileInfo(filePath).completeBaseName());
        button->setToolTip(targetFilePath); // 设置鼠标悬停时显示的快捷方式路径
        button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon); // 将文字放在图标的下方
        button->setStyleSheet("text-align: center;"); // 将文字居中对齐

        // 添加点击事件
        connect(button, &QToolButton::clicked, [=]() {
            QDesktopServices::openUrl(QUrl::fromLocalFile(targetFilePath));
        });

        // 添加到布局中
        m_shortcutLayout->addWidget(button);
    }
}


void AnyDock::onShortcutItemDoubleClicked(QListWidgetItem *item)
{
    QString shortcutFilePath = item->data(Qt::UserRole).toString();
    QDesktopServices::openUrl(QUrl::fromLocalFile(shortcutFilePath));
}

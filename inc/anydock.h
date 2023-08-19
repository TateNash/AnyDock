#ifndef ANYDOCK_H
#define ANYDOCK_H

#include <QtWidgets/QMainWindow>
#include "ui_anydock.h"
#include <QListWidget>
#include <memory> 

class TimePlugin;
class ListWidget;
class QHBoxLayout;
class QPoint;

namespace Ui {
class AnyDock;
}

class AnyDock : public QMainWindow
{
    Q_OBJECT
public:
    AnyDock(QWidget *parent = nullptr);
    ~AnyDock();

private:
    void InitMainWindows();
    void InitListWidget();
    void InitPara();

protected:
    void contextMenuEvent(QContextMenuEvent* event);
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void onShortcutItemDoubleClicked(QListWidgetItem *item);
    void paintEvent(QPaintEvent *event);

private slots:

private:
    Ui::AnyDock ui;

    QMenu *m_menu;
    TimePlugin *m_time;
    QHBoxLayout *m_shortcutLayout;

    const int m_screenWidth;
    const int m_screenHeight;
};

#endif // ANYDOCK_H

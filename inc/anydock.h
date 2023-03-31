#ifndef ANYDOCK_H
#define ANYDOCK_H

#include <QtWidgets/QMainWindow>
#include "ui_anydock.h"
#include <memory> 

class TimePlugin;

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
    void InitPara();

protected:
    void closeEvent(QCloseEvent *event);
    void contextMenuEvent(QContextMenuEvent* event);

private slots:
    void createDigitalClock();

private:
    Ui::AnyDock ui;

    std::unique_ptr<QMenu> m_menu;
    TimePlugin *m_time;
};

#endif // ANYDOCK_H

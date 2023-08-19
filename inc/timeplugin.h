#ifndef TIMEPLUGIN_H
#define TIMEPLUGIN_H

#include <QtWidgets/QWidget>

#include <QLabel>
#include <QTimer>
#include <QMenu>

class TimePlugin : public QWidget
{ 
    Q_OBJECT
public:
    TimePlugin(QWidget *parent = nullptr);

private:
    void InitMenu();
    
private slots:
    void updateTime();
    
private:
    QLabel *m_timeLabel;
    QTimer *m_timer;
    QMenu *m_menu;
};

#endif // TIMEPLUGIN_H
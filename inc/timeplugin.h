#ifndef TIMEPLUGIN_H
#define TIMEPLUGIN_H

#include <QtWidgets/QWidget>

class QLabel;
class QTimer;

class TimePlugin : public QWidget
{ 
    Q_OBJECT
public:
    TimePlugin(QWidget *parent = nullptr);
    
private slots:
    void updateTime();
    
private:
    QLabel *timeLabel;
    QTimer *timer;
};

#endif // TIMEPLUGIN_H
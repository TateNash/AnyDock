#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AnyDock.h"

class AnyDock : public QMainWindow
{
    Q_OBJECT

public:
    AnyDock(QWidget *parent = nullptr);
    ~AnyDock();

private:
    Ui::AnyDockClass ui;
};

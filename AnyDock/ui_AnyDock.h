/********************************************************************************
** Form generated from reading UI file 'AnyDock.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANYDOCK_H
#define UI_ANYDOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnyDockClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AnyDockClass)
    {
        if (AnyDockClass->objectName().isEmpty())
            AnyDockClass->setObjectName("AnyDockClass");
        AnyDockClass->resize(600, 400);
        menuBar = new QMenuBar(AnyDockClass);
        menuBar->setObjectName("menuBar");
        AnyDockClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AnyDockClass);
        mainToolBar->setObjectName("mainToolBar");
        AnyDockClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(AnyDockClass);
        centralWidget->setObjectName("centralWidget");
        AnyDockClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(AnyDockClass);
        statusBar->setObjectName("statusBar");
        AnyDockClass->setStatusBar(statusBar);

        retranslateUi(AnyDockClass);

        QMetaObject::connectSlotsByName(AnyDockClass);
    } // setupUi

    void retranslateUi(QMainWindow *AnyDockClass)
    {
        AnyDockClass->setWindowTitle(QCoreApplication::translate("AnyDockClass", "AnyDock", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnyDockClass: public Ui_AnyDockClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANYDOCK_H

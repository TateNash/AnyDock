#include "anydock.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_AttributeCount);
    QApplication a(argc, argv);
    QIcon icon(":/icon/exe.png");
    QApplication::setWindowIcon(icon);
    a.setQuitOnLastWindowClosed(false);
    AnyDock w;
    w.show();
    return a.exec();
}

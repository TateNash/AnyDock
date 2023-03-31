#include "anydock.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_AttributeCount);
    QApplication a(argc, argv);
    AnyDock w;
    w.show();
    QIcon icon(":/icon/exe.png");
    QApplication::setWindowIcon(icon);
    a.setQuitOnLastWindowClosed(false);
    return a.exec();
}

#include "AnyDock.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AnyDock w;
    w.show();
    return a.exec();
}

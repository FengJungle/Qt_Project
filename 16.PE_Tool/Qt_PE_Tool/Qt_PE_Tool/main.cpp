#include "Qt_PE_Tool.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_PE_Tool w;
    w.show();
    return a.exec();
}

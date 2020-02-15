#include "qtserver.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtServer w;
	w.show();
	return a.exec();
}

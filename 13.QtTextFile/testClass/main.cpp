#include "testClass.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	testClass w;
	w.show();
	return a.exec();
}

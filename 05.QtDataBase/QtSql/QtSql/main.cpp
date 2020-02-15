#include "QtSql.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtSql w;
	w.show();
	return a.exec();
}

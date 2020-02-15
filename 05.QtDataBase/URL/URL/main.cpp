#include "url.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	URL w;
	w.show();
	return a.exec();
}

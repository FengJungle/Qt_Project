#include "winqt_server.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WinQt_Server w;
	w.show();
	return a.exec();
}

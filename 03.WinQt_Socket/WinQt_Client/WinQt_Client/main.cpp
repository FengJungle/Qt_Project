#include "winqt_client.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WinQt_Client w;
	w.show();
	return a.exec();
}

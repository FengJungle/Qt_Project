#ifndef ROBOT_H
#define ROBOT_H

#include <QtGui/QWidget>
#include <QThread>
#include <QMutex>
#include <Windows.h>
#include <QDebug>

class Robot :public QObject
{
	Q_OBJECT
public:
	Robot();
	~Robot();
	static int ID;
	int Inum;

	void setPriStr(QString msg);

	int arr[5];
public slots:
	void pathplanning();
	void test();
	void getMessage(QList<double>);

signals:
		void sendMsg(QString);

private:
	QMutex mutex;

	QString priStr;
};

#endif //ROBOT_H
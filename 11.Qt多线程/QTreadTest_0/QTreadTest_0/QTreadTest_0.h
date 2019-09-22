#ifndef QTREADTEST_0_H
#define QTREADTEST_0_H

#include <QtGui/QWidget>
#include <QThread>
#include <QMutex>
#include <QTimer>
#include <QDebug>
#include "ui_QTreadTest_0.h"

//添加文件引用
#include <QMetaType>


#include "Robot.h"

//class Thread:public QThread
//{
//	Q_OBJECT
//public:
//	Thread()
//	{
//		qDebug()<<"Thread!";
//	}
//	virtual void run()
//	{
//		emit send("New thread!");
//		qDebug()<<currentThreadId();
//	}
//	void stop();
//signals:
//	void send(QString msg);
//};



class QTreadTest_0 : public QWidget
{
	Q_OBJECT

public:
	QTreadTest_0(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QTreadTest_0();

private slots:
	void controlTimer();

signals:
	void sendMessage(QList<double>);
private:
	Ui::QTreadTest_0Class ui;

	QThread thread0,thread1;
	Robot *r1,*r2;
	QTimer timer;
};

#endif // QTREADTEST_0_H

#include "QTreadTest_0.h"

QTreadTest_0::QTreadTest_0(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	timer.setInterval(1000);
	r1 = new Robot();
	r2 = new Robot();

	r1->setPriStr("BUAA");
	r2->setPriStr("Beihang");
	r2->arr[4]=99;
	r1->moveToThread(&thread0);
	r2->moveToThread(&thread1);
	thread0.start();
	thread1.start();

	qDebug()<<"构造函数："<<QThread::currentThreadId();
	qDebug()<<"Thread0:"<<thread0.currentThreadId();
	qDebug()<<"Thread1:"<<thread1.currentThreadId();

	//注册参数类型
	qRegisterMetaType<QList<QString> > ("QList<double>");

	/*connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(controlTimer()));
	connect(&timer,SIGNAL(timeout()),r1,SLOT(pathplanning()));
	connect(&timer,SIGNAL(timeout()),r2,SLOT(pathplanning()));*/

	connect(ui.pushButton_2,SIGNAL(clicked()),r1,SLOT(test()));
	connect(ui.pushButton_2,SIGNAL(clicked()),r2,SLOT(test()));

	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(controlTimer()));
	bool i=connect(this,SIGNAL(sendMessage(QList<double>)),r1,SLOT(getMessage(QList<double>)));
	bool j=connect(this,SIGNAL(sendMessage(QList<double>)),r2,SLOT(getMessage(QList<double>)));
	if(!i)
		qDebug()<<"link false";

	connect(&thread0, SIGNAL(&QThread::finished), r1, SLOT(&QObject::deleteLater)); 
	connect(&thread1, SIGNAL(&QThread::finished), r2, SLOT(&QObject::deleteLater)); 
}

QTreadTest_0::~QTreadTest_0()
{
	
}

void QTreadTest_0::controlTimer()
{
	QList<double> l;
	l<<1<<2<<3<<4<<5<<6;
	emit sendMessage(l);
	/*r1->test();
	r2->test();*/
}




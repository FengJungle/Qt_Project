#include "Robot.h"

Robot::Robot()
{
	Inum = ID;
	ID++;
	for(int i=0;i<5;i++)
		arr[i] = 2*i*i-3;
}

int Robot::ID = 0;

Robot::~Robot()
{

}

void Robot::setPriStr(QString msg)
{
	this->priStr = msg;
}

void Robot::getMessage(QList<double> Msg)
{
	for(int i=0;i<6;i++)
		qDebug()<<"Get Message:"<<QString::number(Msg[i]);
	qDebug()<<"Get Message ID:"<<QThread::currentThreadId();
	qDebug()<<"PriStr = "<<this->priStr;
}

void Robot::pathplanning()
{
	for(int i=0;i<3;i++)
	{
		Sleep(500);
		qDebug()<<"Robot"+QString::number(Inum)+"  "+QString::number(i);
		qDebug()<<"ID:"<<QThread::currentThreadId();
	}
}

void Robot::test()
{
	for(int i=0;i<5;i++)
	{
		mutex.lock();
		Sleep(500);
		qDebug()<<"Test"+QString::number(Inum)+"  "+QString::number(this->arr[i])<<"  ID:"<<QThread::currentThreadId();
		mutex.unlock();
	}
}

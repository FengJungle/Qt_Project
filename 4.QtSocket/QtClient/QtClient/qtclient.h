#ifndef QTCLIENT_H
#define QTCLIENT_H

#include <QtGui/QWidget>
#include "ui_qtclient.h"
#include <QtNetwork>
#include <QTcpSocket>
#include <QDataStream>
#include <QByteArray>
#include <QDebug>
#include <QDateTime>

#include <QFile>
#include <QFileDialog>

class QtClient : public QWidget
{
	Q_OBJECT

public:
	QtClient(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QtClient();

	void initTCP();
	void newConnect();

	private slots:
		////连接服务器
		void connectServer();
		////与服务器断开连接
		void disconnectServer();
		////接收服务器发送的数据
		void receiveData();	
		////向服务器发送数据
		void sendData();

		////浏览文件
		void selectFile();
		////发送文件
		void sendFile();
		////更新文件传送进度
		void updateFileProgress(qint64);

private:
	Ui::QtClientClass ui;
	QTcpSocket *tcpSocket;
	QTcpSocket *fileSocket;

	///文件传送
	QFile *localFile;
	///文件大小
	qint64 totalBytes;
	qint64 bytesWritten;
	qint64 bytestoWrite;
	///每次发送数据大小
	qint64 perDataSize;
	QString filename;
	///数据缓冲区
	QByteArray outBlock;

	////系统时间
	QDateTime current_date_time;
	QString str_date_time;
};

#endif // QTCLIENT_H

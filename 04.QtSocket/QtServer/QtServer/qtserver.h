#ifndef QTSERVER_H
#define QTSERVER_H

#include <QtGui/QWidget>
#include "ui_qtserver.h"

#include <QtNetwork>
#include <QAbstractSocket>
#include<QTcpServer>  
#include<QTcpSocket> 
#include <QDateTime>

#include <QFile>

class QtServer : public QWidget
{
	Q_OBJECT

public:
	QtServer(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QtServer();

	QTcpServer *server;
	QTcpSocket *socket;
	QTcpServer *fileserver;
	QTcpSocket *filesocket;

private slots:  
	void sendMessage(); 
	void acceptConnection();
	////接收客户端发送的数据
	void receiveData();

	void acceptFileConnection();
	void updateFileProgress();
	void displayError(QAbstractSocket::SocketError socketError);
private:
	Ui::QtServerClass ui;

	////传送文件相关变量
	qint64 totalBytes;
	qint64 bytesReceived;
	qint64 filenameSize;
	QString filename;
	QFile *localFile;
	////本地缓冲区
	QByteArray inBlock;

	////系统时间
	QDateTime current_date_time;
	QString str_date_time;
};

#endif // QTSERVER_H

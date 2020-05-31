#ifndef SERVER_H
#define SERVER_H

#include <QtWidgets/QWidget>
#include "ui_Server.h"

#include <QtNetwork>
#include <QAbstractSocket>
#include <QTcpSocket> 

#include <QFile>
#include <QFileDialog>

#include <QDateTime>
#include <QDataStream>

class Server : public QWidget
{
	Q_OBJECT

public:
	Server(QWidget *parent = 0);
	~Server();

	QTcpServer *server;
	QTcpSocket *socket;
	QTcpServer *fileserver;
	QTcpSocket *filesocket;

private slots:
	void sendMessage();
	void acceptConnection();
	// ���տͻ��˷��͵�����
	void receiveData();

	void acceptFileConnection();
	void updateFileProgress();
	void displayError(QAbstractSocket::SocketError socketError);

	// ѡ���͵��ļ�
	void selectFile();
	void sendFile();
	// �����ļ����ͽ���
	void updateFileProgress(qint64);

private:
	Ui::ServerClass ui;

	// �����ļ���ر���
	qint64 totalBytes;
	qint64 bytesReceived;
	qint64 bytestoWrite;
	qint64 bytesWritten;
	qint64 filenameSize;
	QString filename;
	// ÿ�η������ݴ�С
	qint64 perDataSize;
	QFile *localFile;
	// ���ػ�����
	QByteArray inBlock;
	QByteArray outBlock;

	// ϵͳʱ��
	QDateTime current_date_time;
	QString str_date_time;
};

#endif // SERVER_H

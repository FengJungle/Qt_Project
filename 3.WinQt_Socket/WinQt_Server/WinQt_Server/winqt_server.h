#ifndef WINQT_SERVER_H
#define WINQT_SERVER_H

#include <QtGui/QWidget>
#include "ui_winqt_server.h"

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <WinSock2.h>  
#include <QTimer>

#define PORT 8087  
#define SERVER_IP "127.0.0.1"  
#define BUFFER_SIZE 1024  
#define FILE_NAME_MAX_SIZE 512  
#pragma comment(lib, "WS2_32")  

class WinQt_Server : public QWidget
{
	Q_OBJECT

public:
	WinQt_Server(QWidget *parent = 0, Qt::WFlags flags = 0);
	~WinQt_Server();

	// ����һ������˵ĵ�ַ�ṹ
	sockaddr_in server_addr;
	// ������׽���
	SOCKET m_Socket;

	// ��ʼ������˵�ַ�ṹ
	void initialServerEnd();

public slots:
	// ���տͻ����׽���
	void startListen();

private:
	Ui::WinQt_ServerClass ui;

	QTimer timer;
};

#endif // WINQT_SERVER_H

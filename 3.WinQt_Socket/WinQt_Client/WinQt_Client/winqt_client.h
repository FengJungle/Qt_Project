#ifndef WINQT_CLIENT_H
#define WINQT_CLIENT_H

#include <QtGui/QWidget>
#include "ui_winqt_client.h"

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <WinSock2.h>  

#define PORT 8087  
#define SERVER_IP "127.0.0.1"  
#define BUFFER_SIZE 1024  
#define FILE_NAME_MAX_SIZE 512  
#pragma comment(lib, "WS2_32")  

class WinQt_Client : public QWidget
{
	Q_OBJECT

public:
	WinQt_Client(QWidget *parent = 0, Qt::WFlags flags = 0);
	~WinQt_Client();

	public slots:
		void sendCalculatePara();

private:
	Ui::WinQt_ClientClass ui;

	SOCKET c_Socket;
};

#endif // WINQT_CLIENT_H

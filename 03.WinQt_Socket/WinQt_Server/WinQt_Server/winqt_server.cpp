#include "winqt_server.h"

WinQt_Server::WinQt_Server(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	timer.start();
	QObject::connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(startListen()));
	this->initialServerEnd();
	//receiveClientEnd();
}

WinQt_Server::~WinQt_Server()
{

}

void WinQt_Server::initialServerEnd()
{
	this->server_addr.sin_family = AF_INET;
	server_addr.sin_addr.S_un.S_addr = INADDR_ANY;
	server_addr.sin_port = htons(8087);

	// 初始化socket dll  
	WSADATA wsaData;  
	WORD socketVersion = MAKEWORD(2, 0);  
	if(WSAStartup(socketVersion, &wsaData) != 0)  
	{  
		this->ui.textEdit->append("Init socket dll error!");  
		exit(1);  
	} 

	// 创建socket  
	m_Socket = socket(AF_INET, SOCK_STREAM, 0);  
	if (SOCKET_ERROR == m_Socket)  
	{  
		this->ui.textEdit->append("Create Socket Error!");  
		exit(1);  
	} 

	//绑定socket和服务端(本地)地址  
	if (SOCKET_ERROR == bind(m_Socket, (LPSOCKADDR)&server_addr, sizeof(server_addr)))  
	{  
		this->ui.textEdit->append("Server Bind Failed!\n");
		exit(1);  
	}
	else 
		this->ui.textEdit->append("Port release success!");

	//监听  
	if (SOCKET_ERROR == listen(m_Socket, 10))  
	{  
		this->ui.textEdit->append("Server Listen Failed");  
		exit(1);  
	} 
}

void WinQt_Server::startListen()
{
	while(1)
	{
		int nlen = sizeof(this->server_addr);
		///返回新的连接套接字
		SOCKET socka = accept(m_Socket,(sockaddr*)&server_addr,&nlen);
		if(socka == INVALID_SOCKET)
		{
			this->ui.textEdit->append("accept()函数失败！\n");
			this->ui.textEdit->append("错误代码是:");
			this->ui.textEdit->append(QString::number(WSAGetLastError()));
			break;
		}
		else
		{
			QString str = "连接IP："+QLatin1String(inet_ntoa(server_addr.sin_addr))+QString::number(htons(server_addr.sin_port));
			this->ui.textEdit->append(str);
		}
	}
}
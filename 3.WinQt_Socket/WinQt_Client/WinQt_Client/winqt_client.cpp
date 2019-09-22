#include "winqt_client.h"

WinQt_Client::WinQt_Client(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	connect(ui.pushButton_calculate,SIGNAL(clicked()),this,SLOT(sendCalculatePara()));
	// 初始化socket dll  
	WSADATA wsaData;  
	WORD socketVersion = MAKEWORD(2, 0);  
	if(WSAStartup(socketVersion, &wsaData) != 0)  
	{  
		this->ui.textEdit->append("Init socket dll error!");  
		exit(1);  
	}  

	//创建socket  
	/*SOCKET*/ c_Socket = socket(AF_INET, SOCK_STREAM, 0);  
	if (SOCKET_ERROR == c_Socket)  
	{  
		printf("Create Socket Error!");  
		system("pause");  
		exit(1);  
	}  

	//指定服务端的地址  
	sockaddr_in server_addr;  
	server_addr.sin_family = AF_INET;  
	server_addr.sin_addr.S_un.S_addr = inet_addr(SERVER_IP);  
	server_addr.sin_port = htons(PORT);  

	if (SOCKET_ERROR == ::connect(c_Socket, (LPSOCKADDR)&server_addr, sizeof(server_addr)))  
	{  
		printf("Can Not Connect To Server IP!\n");  
		system("pause");  
		exit(1);  
	}  

}

WinQt_Client::~WinQt_Client()
{

}

void WinQt_Client::sendCalculatePara()
{
	QString a = ui.lineEdit_a->text();
	QString b = ui.lineEdit_b->text();
	QString para = a+","+b;
	QByteArray ba = para.toLocal8Bit();
	char s[100];
	char *tmp = ba.data();
	strcpy(s,tmp);
	send(c_Socket,s,strlen(s),0);
}
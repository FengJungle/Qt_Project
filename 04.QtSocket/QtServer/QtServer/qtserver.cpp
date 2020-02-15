#include "qtserver.h"
#include <QDataStream>
#include <QMessageBox>
#include <QString>
#include <QByteArray>

QtServer::QtServer(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	this->socket = new QTcpSocket(this);
	this->server = new QTcpServer(this);
	this->server->listen(QHostAddress::Any,6666);
	connect(this->server,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
	connect(ui.pushButton_send,SIGNAL(clicked()),this,SLOT(sendMessage()));

	///�ļ������׽���
	this->filesocket = new QTcpSocket(this);
	this->fileserver = new QTcpServer(this);
	this->fileserver->listen(QHostAddress::Any,8888);
	connect(this->fileserver,SIGNAL(newConnection()),this,SLOT(acceptFileConnection()));

	//// �ļ�������ر�����ʼ��
	bytesReceived = 0;
	totalBytes = 0;
	filenameSize = 0;
}

QtServer::~QtServer()
{

}

void QtServer::acceptConnection()
{
	this->socket = this->server->nextPendingConnection();

	connect(socket,SIGNAL(readyRead()),this,SLOT(receiveData()));
}

void QtServer::acceptFileConnection()
{
	this->filesocket = this->fileserver->nextPendingConnection();
	///�����ļ�
	connect(filesocket,SIGNAL(readyRead()),this,SLOT(updateFileProgress()));	
	connect(filesocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError socketError)));
}

void QtServer::sendMessage()
{
	////��������
	this->socket->write(ui.lineEdit->text().toLatin1());
	////��ʾ
	current_date_time = QDateTime::currentDateTime();
	str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
	QString str = "You "+str_date_time+"\n"+ui.lineEdit->text();
	ui.browser->append(str);
}

void QtServer::receiveData()
{
	////��������
	QString str = this->socket->readAll();

	/////��ȡ��ǰʱ��
	current_date_time = QDateTime::currentDateTime();
	str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss")+"\n";
	////��ʾ
	str = "Client "+str_date_time+str;
	this->ui.browser->append(str);
}

void QtServer::updateFileProgress()
{
	QDataStream inFile(this->filesocket);
	inFile.setVersion(QDataStream::Qt_4_8);
	
	///������յ�������С��16���ֽڣ����浽�����ļ�ͷ�ṹ
	if(bytesReceived <= sizeof(qint64)*2)
	{
		if((filesocket->bytesAvailable()>=(sizeof(qint64))*2) && (filenameSize==0))
		{
			inFile>>totalBytes>>filenameSize;
			bytesReceived += sizeof(qint64)*2;
		}
		if((filesocket->bytesAvailable()>=filenameSize) && (filenameSize != 0))
		{
			inFile>>filename;
			bytesReceived += filenameSize;
			filename = "ClientData/"+filename;
			localFile = new QFile(filename);
			if(!localFile->open(QFile::WriteOnly))
			{
				qDebug()<<"Server::open file error!";
				return;
			}
		}
		else
			return;
	}
	/////������յ�����С�������ݣ���д���ļ�
	if(bytesReceived < totalBytes)
	{
		bytesReceived += filesocket->bytesAvailable();
		inBlock = filesocket->readAll();
		localFile->write(inBlock);
		inBlock.resize(0);
	}
	////���½�������ʾ
	this->ui.progressBar_fileProgress->setMaximum(totalBytes);
	this->ui.progressBar_fileProgress->setValue(bytesReceived);
	////���ݽ������ʱ
	if(bytesReceived == totalBytes)
	{
		this->ui.browser->append("Receive file successfully!");
		bytesReceived = 0;
		totalBytes = 0;
		filenameSize = 0;
		localFile->close();
		filesocket->close();
	}
}

void QtServer::displayError(QAbstractSocket::SocketError socketError)
{
	qDebug()<<socket->errorString();
	socket->close();
}
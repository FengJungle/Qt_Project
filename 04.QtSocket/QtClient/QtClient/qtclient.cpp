#include "qtclient.h"

#include <QHostAddress>
#include <QMessageBox>

QtClient::QtClient(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);
	this->initTCP();

	/////文件传送相关变量初始化
	///每次发送数据大小为64kb
	perDataSize = 64*1024;
	totalBytes = 0;
	bytestoWrite = 0;
	bytesWritten = 0;

	connect(this->ui.pushButton_openFile,SIGNAL(clicked()),this,SLOT(selectFile()));
	connect(this->ui.pushButton_sendFile,SIGNAL(clicked()),this,SLOT(sendFile()));
}

QtClient::~QtClient()
{
}

void QtClient::initTCP()
{
	this->tcpSocket = new QTcpSocket(this);
	connect(ui.pushButton_connect,SIGNAL(clicked()),this,SLOT(connectServer()));
	connect(ui.pushButton_disconnect,SIGNAL(clicked()),this,SLOT(disconnectServer()));
	connect(ui.pushButton_send,SIGNAL(clicked()),this,SLOT(sendData()));
}

void QtClient::connectServer()
{
	tcpSocket->abort();
	tcpSocket->connectToHost("127.0.0.1",6666);
	connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(receiveData()));
}

void QtClient::disconnectServer()
{
	;
}

void QtClient::receiveData()
{
	/////获取当前时间
	current_date_time = QDateTime::currentDateTime();
	str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss")+"\n";
	////接收数据
	QString str = tcpSocket->readAll();
	////显示
	str = "Server "+str_date_time+str;
	this->ui.textEdit->append(str);
}

void QtClient::sendData()
{
	////发送数据
	QString str = ui.lineEdit->text();
	this->tcpSocket->write(ui.lineEdit->text().toLatin1());
	////显示
	current_date_time = QDateTime::currentDateTime();
	str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
	str = "You "+str_date_time+"\n"+str;
	ui.textEdit->append(str);
}

void QtClient::selectFile()
{
	this->fileSocket = new QTcpSocket(this);
	fileSocket->abort();
	fileSocket->connectToHost("127.0.0.1",8888);
	////文件传送进度更新
	connect(fileSocket,SIGNAL(bytesWritten(qint64)),this,SLOT(updateFileProgress(qint64)));

	this->ui.progressBar->setValue(0);
	this->filename = QFileDialog::getOpenFileName(this,"Open a file","/","files (*)");
	ui.lineEdit_filename->setText(filename);
}

void QtClient::sendFile()
{
	this->localFile = new QFile(filename);
	if(!localFile->open(QFile::ReadOnly))
	{
		ui.textEdit->append(tr("Client:open file error!"));
		return;
	}
	///获取文件大小
	this->totalBytes = localFile->size();
	QDataStream sendout(&outBlock,QIODevice::WriteOnly);
	sendout.setVersion(QDataStream::Qt_4_8);
	QString currentFileName = filename.right(filename.size()-filename.lastIndexOf('/')-1);
	
	qDebug()<<sizeof(currentFileName);
	////保留总代大小信息空间、文件名大小信息空间、文件名
	sendout<<qint64(0)<<qint64(0)<<currentFileName;
	totalBytes += outBlock.size();
	sendout.device()->seek(0);
	sendout<<totalBytes<<qint64((outBlock.size()-sizeof(qint64)*2));

	bytestoWrite = totalBytes-fileSocket->write(outBlock);
	outBlock.resize(0);
}

void QtClient::updateFileProgress(qint64 numBytes)
{
	////已经发送的数据大小
	bytesWritten += (int)numBytes;

	////如果已经发送了数据
	if(bytestoWrite > 0)
	{
		outBlock = localFile->read(qMin(bytestoWrite,perDataSize));
		///发送完一次数据后还剩余数据的大小
		bytestoWrite -= ((int)fileSocket->write(outBlock));
		///清空发送缓冲区
		outBlock.resize(0);
	}
	else
		localFile->close();

	////更新进度条
	this->ui.progressBar->setMaximum(totalBytes);
	this->ui.progressBar->setValue(bytesWritten);

	////如果发送完毕
	if(bytesWritten == totalBytes)
	{
		localFile->close();
		fileSocket->close();
	}
}
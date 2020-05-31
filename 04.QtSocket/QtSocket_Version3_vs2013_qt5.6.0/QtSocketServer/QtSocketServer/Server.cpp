#include "Server.h"
#include <QMessageBox>
#include <QString>
#include <QByteArray>

Server::Server(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->socket = new QTcpSocket(this);
	this->server = new QTcpServer(this);
	this->server->listen(QHostAddress::Any, 6666);
	connect(this->server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
	connect(ui.pushButton_send, SIGNAL(clicked()), this, SLOT(sendMessage()));

	// �ļ������׽���
	this->filesocket = new QTcpSocket(this);
	this->fileserver = new QTcpServer(this);
	this->fileserver->listen(QHostAddress::Any, 8888);
	connect(this->fileserver, SIGNAL(newConnection()), this, SLOT(acceptFileConnection()));

	// �ļ�������ر�����ʼ��
	bytesReceived = 0;
	totalBytes = 0;
	filenameSize = 0;
	connect(ui.pushButton_selectFile, SIGNAL(clicked()), this, SLOT(selectFile()));
	connect(ui.pushButton_sendFile, SIGNAL(clicked()), this, SLOT(sendFile()));
}

Server::~Server()
{

}

void Server::acceptConnection()
{
	this->socket = this->server->nextPendingConnection();

	connect(socket, SIGNAL(readyRead()), this, SLOT(receiveData()));
}

void Server::acceptFileConnection()
{
	bytesWritten = 0;
	// ÿ�η������ݴ�СΪ64kb
	perDataSize = 64 * 1024;
	this->filesocket = this->fileserver->nextPendingConnection();
	// �����ļ�
	connect(filesocket, SIGNAL(readyRead()), this, SLOT(updateFileProgress()));
	connect(filesocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(updateFileProgress(qint64)));
	connect(filesocket, SIGNAL(bytesWritten(qint64)), this, SLOT(displayError(QAbstractSocket::SocketError socketError)));
}

void Server::sendMessage()
{
	this->socket->write(ui.lineEdit->text().toLatin1());
	// ��ʾ
	current_date_time = QDateTime::currentDateTime();
	str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
	QString str = "You " + str_date_time + "\n" + ui.lineEdit->text();
	ui.browser->append(str);
}

void Server::receiveData()
{
	// ��ȡ��ǰʱ��
	current_date_time = QDateTime::currentDateTime();
	str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss") + "\n";

	// ��������
	QString str = this->socket->readAll();

	// ��ʾ
	str = "Client " + str_date_time + str;
	this->ui.browser->append(str);
}

void Server::updateFileProgress()
{
	QDataStream inFile(this->filesocket);
	inFile.setVersion(QDataStream::Qt_4_8);

	// ������յ�������С��16���ֽڣ����浽�����ļ�ͷ�ṹ
	if (bytesReceived <= sizeof(qint64)* 2)
	{
		if ((filesocket->bytesAvailable() >= (sizeof(qint64)) * 2) && (filenameSize == 0))
		{
			inFile >> totalBytes >> filenameSize;
			bytesReceived += sizeof(qint64)* 2;
		}
		if ((filesocket->bytesAvailable() >= filenameSize) && (filenameSize != 0))
		{
			inFile >> filename;
			bytesReceived += filenameSize;
			localFile = new QFile(filename);
			if (!localFile->open(QFile::WriteOnly))
			{
				qDebug() << "Server::open file error!";
				return;
			}
		}
		else
			return;
	}
	// ������յ�����С�������ݣ���д���ļ�
	if (bytesReceived < totalBytes)
	{
		bytesReceived += filesocket->bytesAvailable();
		inBlock = filesocket->readAll();
		localFile->write(inBlock);
		inBlock.resize(0);
	}
	// ���½�������ʾ
	this->ui.progressBar_fileProgress->setMaximum(totalBytes);
	this->ui.progressBar_fileProgress->setValue(bytesReceived);
	// ���ݽ������ʱ
	if (bytesReceived == totalBytes)
	{
		this->ui.browser->append("Receive file successfully!");
		bytesReceived = 0;
		totalBytes = 0;
		filenameSize = 0;
		localFile->close();
		//filesocket->close();
	}
}

void Server::displayError(QAbstractSocket::SocketError socketError)
{
	qDebug() << socket->errorString();
	socket->close();
}

void Server::selectFile()
{
	filesocket->open(QIODevice::WriteOnly);
	// �ļ����ͽ��ȸ���
	connect(filesocket, SIGNAL(bytesWritten(qint64)), this, SLOT(updateFileProgress(qint64)));

	this->filename = QFileDialog::getOpenFileName(this, "Open a file", "/", "files (*)");
	ui.lineEdit_fileName->setText(filename);
}

void Server::sendFile()
{
	this->localFile = new QFile(filename);
	if (!localFile->open(QFile::ReadOnly))
	{
		return;
	}
	// ��ȡ�ļ���С
	this->totalBytes = localFile->size();
	QDataStream sendout(&outBlock, QIODevice::WriteOnly);
	sendout.setVersion(QDataStream::Qt_4_8);
	QString currentFileName = filename.right(filename.size() - filename.lastIndexOf('/') - 1);

	// �����ܴ���С��Ϣ�ռ䡢�ļ�����С��Ϣ�ռ䡢�ļ���
	sendout << qint64(0) << qint64(0) << currentFileName;
	totalBytes += outBlock.size();
	sendout.device()->seek(0);
	sendout << totalBytes << qint64((outBlock.size() - sizeof(qint64)* 2));

	bytestoWrite = totalBytes - filesocket->write(outBlock);
	outBlock.resize(0);
}

void Server::updateFileProgress(qint64 numBytes)
{
	////�Ѿ����͵����ݴ�С
	bytesWritten += (int)numBytes;

	////����Ѿ�����������
	if (bytestoWrite > 0)
	{
		outBlock = localFile->read(qMin(bytestoWrite, perDataSize));
		///������һ�����ݺ�ʣ�����ݵĴ�С
		bytestoWrite -= ((int)filesocket->write(outBlock));
		///��շ��ͻ�����
		outBlock.resize(0);
	}
	else
		localFile->close();

	// ����������
	if (bytesWritten == totalBytes)
	{
		localFile->close();
		//filesocket->close();
	}
}
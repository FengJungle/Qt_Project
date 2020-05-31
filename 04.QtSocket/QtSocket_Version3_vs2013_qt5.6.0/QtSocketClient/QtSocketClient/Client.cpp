#include "Client.h"

Client::Client(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->initTCP();

	// �ļ�������ر�����ʼ��
	// ÿ�η������ݴ�СΪ64kb
	perDataSize = 64 * 1024;
	totalBytes = 0;
	bytestoWrite = 0;
	bytesWritten = 0;
	bytesReceived = 0;
	filenameSize = 0;

	connect(this->ui.pushButton_openFile, SIGNAL(clicked()), this, SLOT(selectFile()));
	connect(this->ui.pushButton_sendFile, SIGNAL(clicked()), this, SLOT(sendFile()));
}

Client::~Client()
{

}

void Client::initTCP()
{
	this->tcpSocket = new QTcpSocket(this);
	connect(ui.pushButton_connect, SIGNAL(clicked()), this, SLOT(connectServer()));
	connect(ui.pushButton_disconnect, SIGNAL(clicked()), this, SLOT(disconnectServer()));
	connect(ui.pushButton_send, SIGNAL(clicked()), this, SLOT(sendData()));
}

void Client::connectServer()
{
	tcpSocket->abort();
	tcpSocket->connectToHost("127.0.0.1", 6666);
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveData()));
}

void Client::disconnectServer()
{
	;
}

void Client::receiveData()
{
	// ��ȡ��ǰʱ��
	current_date_time = QDateTime::currentDateTime();
	str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss") + "\n";

	// ��������
	QString str = tcpSocket->readAll();
	// ��ʾ
	str = "Server " + str_date_time + str;
	this->ui.textEdit->append(str);
}

void Client::sendData()
{
	// ��������
	QString str = ui.lineEdit->text();
	this->tcpSocket->write(ui.lineEdit->text().toLatin1());
	// ��ʾ
	current_date_time = QDateTime::currentDateTime();
	str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
	str = "You " + str_date_time + "\n" + str;
	ui.textEdit->append(str);
}

void Client::selectFile()
{
	this->fileSocket = new QTcpSocket(this);
	fileSocket->abort();
	fileSocket->connectToHost("127.0.0.1", 8888);
	// �ļ����ͽ��ȸ���
	connect(fileSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(updateFileProgress(qint64)));
	connect(fileSocket, SIGNAL(readyRead()), this, SLOT(updateFileProgress()));

	this->ui.progressBar->setValue(0);
	this->filename = QFileDialog::getOpenFileName(this, "Open a file", "/", "files (*)");
	ui.lineEdit_filename->setText(filename);
}

void Client::sendFile()
{
	this->localFile = new QFile(filename);
	if (!localFile->open(QFile::ReadOnly))
	{
		ui.textEdit->append(tr("Client:open file error!"));
		return;
	}
	// ��ȡ�ļ���С
	this->totalBytes = localFile->size();
	QDataStream sendout(&outBlock, QIODevice::WriteOnly);
	sendout.setVersion(QDataStream::Qt_4_8);
	QString currentFileName = filename.right(filename.size() - filename.lastIndexOf('/') - 1);

	qDebug() << sizeof(currentFileName);
	// �����ܴ���С��Ϣ�ռ䡢�ļ�����С��Ϣ�ռ䡢�ļ���
	sendout << qint64(0) << qint64(0) << currentFileName;
	totalBytes += outBlock.size();
	sendout.device()->seek(0);
	sendout << totalBytes << qint64((outBlock.size() - sizeof(qint64)* 2));

	bytestoWrite = totalBytes - fileSocket->write(outBlock);
	outBlock.resize(0);
}

void Client::updateFileProgress(qint64 numBytes)
{
	// �Ѿ����͵����ݴ�С
	bytesWritten += (int)numBytes;

	// ����Ѿ�����������
	if (bytestoWrite > 0)
	{
		outBlock = localFile->read(qMin(bytestoWrite, perDataSize));
		// ������һ�����ݺ�ʣ�����ݵĴ�С
		bytestoWrite -= ((int)fileSocket->write(outBlock));
		// ��շ��ͻ�����
		outBlock.resize(0);
	}
	else
		localFile->close();

	// ���½�����
	this->ui.progressBar->setMaximum(totalBytes);
	this->ui.progressBar->setValue(bytesWritten);

	// ����������
	if (bytesWritten == totalBytes)
	{
		localFile->close();
		//fileSocket->close();
	}
}

void Client::updateFileProgress()
{
	QDataStream inFile(this->fileSocket);
	inFile.setVersion(QDataStream::Qt_4_8);

	// ������յ�������С��16���ֽڣ����浽�����ļ�ͷ�ṹ
	if (bytesReceived <= sizeof(qint64)* 2)
	{
		if ((fileSocket->bytesAvailable() >= (sizeof(qint64)) * 2) && (filenameSize == 0))
		{
			inFile >> totalBytes >> filenameSize;
			bytesReceived += sizeof(qint64)* 2;
		}
		if ((fileSocket->bytesAvailable() >= filenameSize) && (filenameSize != 0))
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
		bytesReceived += fileSocket->bytesAvailable();
		inBlock = fileSocket->readAll();
		localFile->write(inBlock);
		inBlock.resize(0);
	}

	// ���ݽ������ʱ
	if (bytesReceived == totalBytes)
	{
		this->ui.textEdit->append("Receive file successfully!");
		bytesReceived = 0;
		totalBytes = 0;
		filenameSize = 0;
		localFile->close();
		//fileSocket->close();
	}
}
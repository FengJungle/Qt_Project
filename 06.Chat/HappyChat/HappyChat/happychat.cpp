#include "happychat.h"

HappyChat::HappyChat(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	this->udpSocket = new QUdpSocket(this);
	port = 45454;
	udpSocket->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
	connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
	connect(ui.pushButtonSend,SIGNAL(clicked()),this,SLOT(sendmsg()));
	connect(ui.pushButton_save,SIGNAL(clicked()),this,SLOT(savefile()));
	connect(ui.pushButton_clear,SIGNAL(clicked()),this,SLOT(clearMsg()));
	sendMessage(NewParticipant);
}

HappyChat::~HappyChat()
{

}

void HappyChat::sendMessage(MessageType type, QString serverAddress)
{
	QByteArray data;
	QDataStream out(&data,QIODevice::WriteOnly);
	QString localHostName = QHostInfo::localHostName();
	QString address = getIP();
	out<<type<<getUserName()<<localHostName;
	
	switch(type)
	{
	case Message:
		if(ui.textEdit_message->toPlainText() == "")
		{
			QMessageBox::warning(0,tr("Waring"),tr("发送内容不能为空!"),QMessageBox::Ok);
			return ;
		}
		out<<address<<getMessage();
		ui.messageBrowser->verticalScrollBar()->setValue(ui.messageBrowser->verticalScrollBar()->maximum());
		break;
	case NewParticipant:
		out<<address;
		break;
	case FileName:
		break;
	case ParticipantLeft:
		break;
	case Refuse:
		break;
	}
	////UDP广播
	udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast,port);
}

void HappyChat::processPendingDatagrams()
{
	while(udpSocket->hasPendingDatagrams())
	{
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());
		udpSocket->readDatagram(datagram.data(),datagram.size());
		QDataStream in(&datagram,QIODevice::ReadOnly);
		int messageType;
		in>>messageType;
		QString userName,localHostName,ipAddress,message;
		QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

		switch(messageType)
		{
		case Message:
			in>>userName>>localHostName>>ipAddress>>message;
			ui.messageBrowser->setTextColor(Qt::blue);
			ui.messageBrowser->setCurrentFont(QFont("Times New Roman",12));
			ui.messageBrowser->append("["+userName+"]"+time);
			ui.messageBrowser->append(message);
			break;
		case NewParticipant:
			in>>userName>>localHostName>>ipAddress;
			newParticipant(userName,localHostName,ipAddress);
			break;
		case ParticipantLeft:
			in>>userName>>localHostName;
			participantLeft(userName,localHostName,time);
			break;
		case FileName:
			break;
		case Refuse:
			break;
		}
	}
}

void HappyChat::participantLeft(QString userName, QString localHostName, QString time)
{
	int rowNum = ui.tableWidget->findItems(localHostName,Qt::MatchExactly).first()->row();
	ui.tableWidget->removeRow(rowNum);
	ui.messageBrowser->setTextColor(Qt::gray);
	ui.messageBrowser->setCurrentFont(QFont("Times New Roman",10));
	ui.messageBrowser->append(tr("%1已经于%2离开!").arg(userName).arg(time));
	ui.label->setText(tr("Online people :%1").arg(ui.tableWidget->rowCount()));
}

void HappyChat::newParticipant(QString userName, QString localHostName, QString ipAddress)
{
	bool isEmpty = ui.tableWidget->findItems(localHostName,Qt::MatchExactly).isEmpty();
	if(isEmpty)
	{
		QTableWidgetItem *user = new QTableWidgetItem(userName);
		QTableWidgetItem *host = new QTableWidgetItem(localHostName);
		QTableWidgetItem *ip = new QTableWidgetItem(ipAddress);

		ui.tableWidget->insertRow(0);
		ui.tableWidget->setItem(0,0,user);
		ui.tableWidget->setItem(0,1,host);
		ui.tableWidget->setItem(0,2,ip);

		ui.messageBrowser->setTextColor(Qt::gray);
		ui.messageBrowser->setCurrentFont(QFont("Times New Roman",10));
		ui.messageBrowser->append(tr("%1 is online!").arg(userName));
		ui.label->setText(tr("Online people :%1").arg(ui.tableWidget->rowCount()));

		sendMessage(NewParticipant);
	}
}

QString HappyChat::getIP()
{
	QList<QHostAddress>list = QNetworkInterface::allAddresses();
	foreach(QHostAddress address,list)
	{
		if(address.protocol() == QAbstractSocket::IPv4Protocol)
			return address.toString();
	}
	return 0;
}

QString HappyChat::getUserName()
{
	QStringList envVaribles;
	envVaribles<<"USERNAME.*"<<"USER.*"<<"USERDOMAIN.*"<<"HOSTNAME.*"<<"DOMAINNAME.*";
	QStringList environment = QProcess::systemEnvironment();
	foreach(QString string,envVaribles)
	{
		int index = environment.indexOf(QRegExp(string));
		if(index != 1)
		{
			QStringList stringList = environment.at(index).split('=');///
			if(stringList.size() == 2)
			{
				return stringList.at(1);
				break;
			}

		}
	}
	return "unknown";
}

QString HappyChat::getMessage()
{
	QString msg = ui.textEdit_message->toHtml();
	ui.textEdit_message->clear();
	ui.textEdit_message->setFocus();
	qDebug()<<msg;
	return msg;
}

void HappyChat::sendmsg()
{
	sendMessage(Message);
}

bool HappyChat::saveFile(QString &fileName)
{
	QFile file(fileName);
	if(!file.open(QFile::WriteOnly|QFile::Text))
	{
		qDebug()<<"cannot save file!";
		return false;
	}
	QTextStream out(&file);
	out<<ui.messageBrowser->toPlainText();
	return true;
}

void HappyChat::savefile()
{
	QString fileName = QFileDialog::getSaveFileName(this,tr("保存聊天记录"),tr("聊天记录"),tr("文本(*.txt);;All File(*.*)"));
	if(!fileName.isEmpty())
		saveFile(fileName);
}

void HappyChat::clearMsg()
{
	ui.messageBrowser->clear();
}
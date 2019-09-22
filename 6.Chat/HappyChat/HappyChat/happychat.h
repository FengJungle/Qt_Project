#ifndef HAPPYCHAT_H
#define HAPPYCHAT_H

#include <QtGui/QWidget>
#include "ui_happychat.h"

#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

////ö�ٱ��������岻ͬ�㲥����
enum MessageType
{
	Message,
	NewParticipant,
	ParticipantLeft,
	FileName,
	Refuse
};

class HappyChat : public QWidget
{
	Q_OBJECT

public:
	HappyChat(QWidget *parent = 0, Qt::WFlags flags = 0);
	~HappyChat();

	///�㲥�û���¼��Ϣ
	void newParticipant(QString userName,QString localHostName,QString ipAddress);
	void participantLeft(QString userName,QString localHostName,QString time);
	void sendMessage(MessageType type,QString serverAddress = "");
	///���������¼
	bool saveFile(QString& fileName);

	QString getIP();
	QString getUserName();
	QString getMessage();

	private slots:
		void processPendingDatagrams();
		void sendmsg();
		void savefile();
		void clearMsg();
		
private:
	Ui::HappyChatClass ui;

	QUdpSocket *udpSocket;
	qint16 port;

};

#endif // HAPPYCHAT_H

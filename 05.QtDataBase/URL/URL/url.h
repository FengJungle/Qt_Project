#ifndef URL_H
#define URL_H

#include <QtGui/QWidget>
#include "ui_url.h"

#include <QtNetwork>
#include <QTextCodec>
#include <QDesktopServices>

class URL : public QWidget
{
	Q_OBJECT

public:
	URL(QWidget *parent = 0, Qt::WFlags flags = 0);
	~URL();

	QNetworkAccessManager *manager;
	
	private slots:
		void replyFinished(QNetworkReply *);
		void openWeb();

private:
	Ui::URLClass ui;
};

#endif // URL_H

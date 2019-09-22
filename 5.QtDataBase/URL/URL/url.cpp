#include "url.h"

URL::URL(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	manager = new QNetworkAccessManager(this);
	connect(manager,SIGNAL(finished(QNetworkReply *)),this,SLOT(replyFinished(QNetworkReply *)));
	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(openWeb()));
	manager->get(QNetworkRequest(QUrl("http://www.baidu.com")));
}

URL::~URL()
{

}

void URL::replyFinished(QNetworkReply *reply)
{
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	QString all = codec->toUnicode(reply->readAll());
	ui.textEdit->setText(all);
	reply->deleteLater();
}
void URL::openWeb()
{
	//QDesktopServices::openUrl(QUrl(QString("www.baidu.com")));
	QUrl url(QString("www.zhihu.com"));
	bool is_open = QDesktopServices::openUrl(url);
}
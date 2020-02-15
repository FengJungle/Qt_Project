#ifndef FILEBROWER_H
#define FILEBROWER_H

#include <QtGui/QWidget>
#include "ui_FileBrower.h"

#include <QIcon>
#include <QDir>

class FileBrower : public QWidget
{
	Q_OBJECT

public:
	FileBrower(QWidget *parent = 0, Qt::WFlags flags = 0);
	~FileBrower();

	///��QListWidget����ʾ��ǰĿ¼�µ���ϸ
	void showFileInfoList(QFileInfoList pInfoList);

	///�����ļ����ʻ�ȡͼ��
	///iType=1:�ļ���
	///iType=2:�ļ�
	QIcon *getItemPropertyIcon(int iType);

public slots:
	///��ʾ��ǰĿ¼�µ��ļ��к��ļ�
	void showCurrentDirFiles();
	///��ʾ���˫�����б�����ļ����µ��ļ�
	void showNextDirFiles(QListWidgetItem *item);

private:
	Ui::FileBrowerClass ui;
};

#endif // FILEBROWER_H

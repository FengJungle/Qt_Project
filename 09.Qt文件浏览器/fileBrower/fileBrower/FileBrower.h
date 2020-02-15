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

	///在QListWidget里显示当前目录下的明细
	void showFileInfoList(QFileInfoList pInfoList);

	///根据文件性质获取图标
	///iType=1:文件夹
	///iType=2:文件
	QIcon *getItemPropertyIcon(int iType);

public slots:
	///显示当前目录下的文件夹和文件
	void showCurrentDirFiles();
	///显示鼠标双击的列表里的文件夹下的文件
	void showNextDirFiles(QListWidgetItem *item);

private:
	Ui::FileBrowerClass ui;
};

#endif // FILEBROWER_H

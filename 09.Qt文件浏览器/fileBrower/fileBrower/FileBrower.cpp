#include "FileBrower.h"

FileBrower::FileBrower(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	connect(ui.lineEdit,SIGNAL(returnPressed()),this,SLOT(showCurrentDirFiles()));
	connect(ui.listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(showNextDirFiles(QListWidgetItem*)));
}

FileBrower::~FileBrower()
{

}

void FileBrower::showNextDirFiles(QListWidgetItem *item)
{
	///获取鼠标双击的文件名字
	QString strName = item->text();
	QDir dir;
	//设置路径为当前目录路径
	dir.setPath(ui.lineEdit->text());
	//重新设置路径
	dir.cd(strName);
	//更新当前显示路径,并显示当前目录下所有文件
	ui.lineEdit->setText(dir.absolutePath());
	showCurrentDirFiles();
}

void FileBrower::showCurrentDirFiles()
{
	//获取当前输入的目录
	QDir currentDir(ui.lineEdit->text());
	QStringList fileList;
	fileList<<"*";
	QFileInfoList infoList = currentDir.entryInfoList(fileList,QDir::AllEntries,QDir::DirsFirst);
	//在QListWidget里显示文件列表
	this->showFileInfoList(infoList);
}

void FileBrower::showFileInfoList(QFileInfoList pInfoList)
{
	ui.listWidget->clear();
	for(int i=0;i<pInfoList.size();i++)
	{
		QFileInfo tmpInfo = pInfoList.at(i);
		QString pFileName = tmpInfo.fileName();
		QListWidgetItem *tmpItem = new QListWidgetItem(pFileName);
		if(tmpInfo.isDir())
			tmpItem->setIcon(*getItemPropertyIcon(1));
		else
			tmpItem->setIcon(*getItemPropertyIcon(2));
		ui.listWidget->addItem(tmpItem);
	}
}

QIcon * FileBrower::getItemPropertyIcon(int iType)
{
	QDir dir;
	QString path = dir.currentPath();
	switch(iType)
	{
	case 1:
		return new QIcon(path+"/Folder.png");
		break;
	case 2:
		return new QIcon(path+"/File.png");
		break;
	}
	return NULL;
}

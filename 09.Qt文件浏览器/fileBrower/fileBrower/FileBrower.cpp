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
	///��ȡ���˫�����ļ�����
	QString strName = item->text();
	QDir dir;
	//����·��Ϊ��ǰĿ¼·��
	dir.setPath(ui.lineEdit->text());
	//��������·��
	dir.cd(strName);
	//���µ�ǰ��ʾ·��,����ʾ��ǰĿ¼�������ļ�
	ui.lineEdit->setText(dir.absolutePath());
	showCurrentDirFiles();
}

void FileBrower::showCurrentDirFiles()
{
	//��ȡ��ǰ�����Ŀ¼
	QDir currentDir(ui.lineEdit->text());
	QStringList fileList;
	fileList<<"*";
	QFileInfoList infoList = currentDir.entryInfoList(fileList,QDir::AllEntries,QDir::DirsFirst);
	//��QListWidget����ʾ�ļ��б�
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

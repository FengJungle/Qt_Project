
#include <QtCore/QCoreApplication>

#include <QDir>
#include <QDirIterator>

#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QDir dir("G:/3.Study/2.Graduate/6.Lab/1.Paper/9.Edge Conference/Figure");
	if(!dir.exists())
	{
		cout<<"Current Dir dose not exist!";
		return -1;
	}
	dir.setFilter(QDir::Files|QDir::NoSymLinks);
	QFileInfoList flist = dir.entryInfoList();

	int fileCount = flist.count();
	QStringList str_filelist;
	for(int i=0;i<fileCount;i++)
	{
		//str_filelist<<flist.at(i).absoluteFilePath();//绝对路径
		//str_filelist<<flist.at(i).baseName();//文件名字（不带后缀名）
		//str_filelist<<(flist[i].completeBaseName()+"."+flist[i].suffix());//文件名字（带后缀名）
		str_filelist<<(flist[i].completeBaseName()+"."+flist[i].suffix()+"    "+QString::number(flist[i].size()));//文件名字（带后缀名+文件大小）
	}
	for(int i=0;i<str_filelist.size();i++)
	{
		cout<<string((const char*)str_filelist[i].toLocal8Bit())<<endl;
	}
	

	return a.exec();
}

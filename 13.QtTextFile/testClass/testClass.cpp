#include "testClass.h"

testClass::testClass(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	
	connect(ui.pushButton_saveFile,SIGNAL(clicked()),this,SLOT(saveFile()));
	connect(ui.pushButton_openFile,SIGNAL(clicked()),this,SLOT(openFile()));	
}

testClass::~testClass()
{

}

void testClass::openFile()
{
	QString fileName = QFileDialog::getOpenFileName(this,tr("Open file"),"/","All files(*);;Text files(*.txt)");
	QFile file(fileName);
	///以只读方式打开文件
	if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
		return;
	QTextStream inFile(&file);
	QString strLine;
	while(!inFile.atEnd())
	{
		strLine = inFile.readLine();
		ui.textEdit->append(strLine);
	}
	file.close();
}

void testClass::saveFile()
{
	QString fileName = QFileDialog::getSaveFileName(this,tr("Open file"),"/","All files(*);;Text files(*.txt)");
	QFile file(fileName+".txt");
	///以只写方式打开文件
	if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
		return;
	QTextStream outFile(&file);
	QString str = ui.textEdit->toPlainText();
	outFile<<str;
	file.close();
}

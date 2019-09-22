#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QtGui/QMainWindow>
#include "ui_testClass.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

class testClass : public QMainWindow
{
	Q_OBJECT

public:
	testClass(QWidget *parent = 0, Qt::WFlags flags = 0);
	~testClass();

public slots:
	///打开文本文件
	void openFile();
	///保存为文本文件
	void saveFile();

private:
	Ui::testClassClass ui;
};

#endif // TESTCLASS_H

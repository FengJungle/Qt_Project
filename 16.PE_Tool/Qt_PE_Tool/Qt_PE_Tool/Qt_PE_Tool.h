#pragma once

#include <QtWidgets/QWidget>
#include "ui_Qt_PE_Tool.h"

class Qt_PE_Tool : public QWidget
{
    Q_OBJECT

public:
    Qt_PE_Tool(QWidget *parent = Q_NULLPTR);
	~Qt_PE_Tool();

public slots:
	void openExeFile();

private:
    Ui::Qt_PE_ToolClass ui;
	QTableWidgetItem* itemArr;

	void parsePE(char* filePE);
};

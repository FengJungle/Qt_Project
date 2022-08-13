#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtWidgetsApplication.h"

class QtWidgetsApplication : public QWidget
{
    Q_OBJECT

public:
    QtWidgetsApplication(QWidget *parent = nullptr);
    ~QtWidgetsApplication();

	// ��ʼ��UI����
	void initialUI();

	// ����TreeWidget�������ק��ص�����
	void setTreeDragConfig();

	// ���Զ����������ӵ�TreeWidget��
	void addUserDataToTreeWidget();

private:
    Ui::QtWidgetsApplicationClass ui;
};

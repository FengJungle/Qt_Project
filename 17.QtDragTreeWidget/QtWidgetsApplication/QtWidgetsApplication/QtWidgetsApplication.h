#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtWidgetsApplication.h"

class QtWidgetsApplication : public QWidget
{
    Q_OBJECT

public:
    QtWidgetsApplication(QWidget *parent = nullptr);
    ~QtWidgetsApplication();

	// 初始化UI设置
	void initialUI();

	// 设置TreeWidget组件的拖拽相关的配置
	void setTreeDragConfig();

	// 将自定义的数据添加到TreeWidget中
	void addUserDataToTreeWidget();

private:
    Ui::QtWidgetsApplicationClass ui;
};

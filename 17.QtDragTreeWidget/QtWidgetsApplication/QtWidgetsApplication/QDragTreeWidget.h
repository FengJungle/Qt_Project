#ifndef DRAGTREEWIDGET_H
#define DRAGTREEWIDGET_H

#include <QTreeWidget>
#include <QLabel>

class QDragTreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	QDragTreeWidget(QWidget* parent = nullptr);

	//初始化函数
	void initTreeWidget();

	// 覆写鼠标事件：按下、移动、释放
	void mousePressEvent(QMouseEvent* ev) override;
	void mouseMoveEvent(QMouseEvent* ev) override;
	void mouseReleaseEvent(QMouseEvent* ev) override;

private:
	// 用来显示被鼠标拖拽的item
	QLabel label;

	// 被拖拽的item
	QTreeWidgetItem* pSource;

	// 被拖拽的item的父节点
	QTreeWidgetItem* pParent;

	// 被拖拽的item在父节点中的索引
	int originIndex;
	
	// 用于判断在mouseMoveEvent中是否已经移除了组件
	bool isJudged;
};

#endif // DRAGTREEWIDGET_H

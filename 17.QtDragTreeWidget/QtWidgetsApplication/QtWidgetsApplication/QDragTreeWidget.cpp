#include "qdragtreewidget.h"
#include <QDebug>
#include <QMouseEvent>

QDragTreeWidget::QDragTreeWidget(QWidget *parent)
	:QTreeWidget(parent),
	label(this),
	pSource(nullptr)
{
	initTreeWidget();
	setHeaderHidden(true);
	label.resize(100, 30);
	label.setText("");
	label.hide();

	
}

void QDragTreeWidget::initTreeWidget()
{
	for (int i = 0; i < 5; i++) {
		QTreeWidgetItem* pTopItem = new QTreeWidgetItem(this);
		pTopItem->setText(0, QString::number(114514 + i));
		addTopLevelItem(pTopItem);
	}
	for (int i = 0; i < 5; i++) {
		QTreeWidgetItem* pChildItem = new QTreeWidgetItem(topLevelItem(0));
		pChildItem->setText(0, QString::number(191981 + i));
		topLevelItem(0)->addChild(pChildItem);
	}
}

void QDragTreeWidget::mousePressEvent(QMouseEvent *ev)
{
	qDebug() << "Enter mousePressEvent()";
	isJudged = false;

	pSource = itemAt(ev->pos());

	
	if (pSource != nullptr) {
		pParent = pSource->parent();
		// label显示被拖拽的item的内容
		label.setText(pSource->text(0));
	}

	QTreeWidget::mousePressEvent(ev);
}

void QDragTreeWidget::mouseMoveEvent(QMouseEvent *ev)
{
	//qDebug() << "Enter mouseMoveEvent()";
	if (pSource == nullptr) {
		QTreeWidget::mouseMoveEvent(ev);
		return;
	}

	label.show();
	label.move(ev->pos());

	if (isJudged == false) {
		isJudged = true;
		//将item从parent中脱离出来
		//并且记录原始的位置，方便后面复原
		if (pParent) {
			originIndex = pParent->indexOfChild(pSource);
			// 从父节点中去除该节点
			pParent->takeChild(originIndex);
		}
		else {
			// 获取item在顶层项中的索引
			originIndex = indexOfTopLevelItem(pSource);
			// 删除指定位置的顶层项
			takeTopLevelItem(originIndex);
		}
	}
}

void QDragTreeWidget::mouseReleaseEvent(QMouseEvent *ev)
{
	qDebug() << "Enter mouseReleaseEvent()";
	//无论如何都先隐藏一下label
	label.hide();

	QTreeWidgetItem* pTarget = itemAt(ev->pos());

	//如果拖动到没有item的地方
	if (pTarget == nullptr) {
		//如果是子节点，那么返回原位
		if (pParent) {
			pParent->insertChild(originIndex, pSource);
		}
		//如果是父节点，那么移动到最下方
		else {
			addTopLevelItem(pSource);
		}
	}
	//如果拖动到子节点处
	else if (pTarget->parent()) {
		//如果将子节点A拖动到子节点B处，那么将子节点A放置到子节点B的下方
		if (pParent) {
			pTarget->parent()->insertChild(
				pTarget->parent()->indexOfChild(pTarget), pSource);
		}
		//如果将父节点A拖动到子节点B处，那么父节点A回归到原位
		else {
			insertTopLevelItem(originIndex, pSource);
		}
	}
	//如果拖动到父节点处
	else {
		//如果将子节点A拖动到父节点B处，那么将子节点A添加到父节点B中
		if (pParent) {
			pTarget->addChild(pSource);
		}
		//如果将父节点A拖动到父节点B处，那么将父节点A放置到父节点B的下方
		else {
			insertTopLevelItem(indexOfTopLevelItem(pTarget), pSource);
		}
	}
	//设置当前的焦点为pSource
	setCurrentItem(pSource);
}


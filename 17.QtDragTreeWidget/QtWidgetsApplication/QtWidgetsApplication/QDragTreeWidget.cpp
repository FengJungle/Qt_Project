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
		// label��ʾ����ק��item������
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
		//��item��parent���������
		//���Ҽ�¼ԭʼ��λ�ã�������渴ԭ
		if (pParent) {
			originIndex = pParent->indexOfChild(pSource);
			// �Ӹ��ڵ���ȥ���ýڵ�
			pParent->takeChild(originIndex);
		}
		else {
			// ��ȡitem�ڶ������е�����
			originIndex = indexOfTopLevelItem(pSource);
			// ɾ��ָ��λ�õĶ�����
			takeTopLevelItem(originIndex);
		}
	}
}

void QDragTreeWidget::mouseReleaseEvent(QMouseEvent *ev)
{
	qDebug() << "Enter mouseReleaseEvent()";
	//������ζ�������һ��label
	label.hide();

	QTreeWidgetItem* pTarget = itemAt(ev->pos());

	//����϶���û��item�ĵط�
	if (pTarget == nullptr) {
		//������ӽڵ㣬��ô����ԭλ
		if (pParent) {
			pParent->insertChild(originIndex, pSource);
		}
		//����Ǹ��ڵ㣬��ô�ƶ������·�
		else {
			addTopLevelItem(pSource);
		}
	}
	//����϶����ӽڵ㴦
	else if (pTarget->parent()) {
		//������ӽڵ�A�϶����ӽڵ�B������ô���ӽڵ�A���õ��ӽڵ�B���·�
		if (pParent) {
			pTarget->parent()->insertChild(
				pTarget->parent()->indexOfChild(pTarget), pSource);
		}
		//��������ڵ�A�϶����ӽڵ�B������ô���ڵ�A�ع鵽ԭλ
		else {
			insertTopLevelItem(originIndex, pSource);
		}
	}
	//����϶������ڵ㴦
	else {
		//������ӽڵ�A�϶������ڵ�B������ô���ӽڵ�A��ӵ����ڵ�B��
		if (pParent) {
			pTarget->addChild(pSource);
		}
		//��������ڵ�A�϶������ڵ�B������ô�����ڵ�A���õ����ڵ�B���·�
		else {
			insertTopLevelItem(indexOfTopLevelItem(pTarget), pSource);
		}
	}
	//���õ�ǰ�Ľ���ΪpSource
	setCurrentItem(pSource);
}


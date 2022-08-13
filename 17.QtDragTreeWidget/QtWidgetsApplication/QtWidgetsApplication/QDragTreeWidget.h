#ifndef DRAGTREEWIDGET_H
#define DRAGTREEWIDGET_H

#include <QTreeWidget>
#include <QLabel>

class QDragTreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	QDragTreeWidget(QWidget* parent = nullptr);

	//��ʼ������
	void initTreeWidget();

	// ��д����¼������¡��ƶ����ͷ�
	void mousePressEvent(QMouseEvent* ev) override;
	void mouseMoveEvent(QMouseEvent* ev) override;
	void mouseReleaseEvent(QMouseEvent* ev) override;

private:
	// ������ʾ�������ק��item
	QLabel label;

	// ����ק��item
	QTreeWidgetItem* pSource;

	// ����ק��item�ĸ��ڵ�
	QTreeWidgetItem* pParent;

	// ����ק��item�ڸ��ڵ��е�����
	int originIndex;
	
	// �����ж���mouseMoveEvent���Ƿ��Ѿ��Ƴ������
	bool isJudged;
};

#endif // DRAGTREEWIDGET_H

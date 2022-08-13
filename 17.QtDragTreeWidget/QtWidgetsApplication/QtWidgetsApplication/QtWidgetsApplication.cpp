#include "QtWidgetsApplication.h"
#include "Data.h"
#include <qdebug.h>

QtWidgetsApplication::QtWidgetsApplication(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

	setTreeDragConfig();
	initialUI();
	addUserDataToTreeWidget();
}

QtWidgetsApplication::~QtWidgetsApplication()
{

}

void QtWidgetsApplication::initialUI()
{
	QTreeWidgetItem* item = nullptr;
	QTreeWidgetItem* itemChild = nullptr;

	QString province[2] = { "Sichuan", "Guangdong" };
	QString city[2] = { "Chengdu", "Guangzhou" };

	for (int i = 0; i < 2; ++i)
	{
		item = new QTreeWidgetItem(this->ui.treeWidget);
		item->setText(0, province[i]);

		itemChild = new QTreeWidgetItem(item);
		itemChild->setText(0, city[i]);
	}
}

void QtWidgetsApplication::setTreeDragConfig()
{
	QStringList headers;
	headers << "name" << "cmd";
	this->ui.treeWidget->setColumnCount(2);
	this->ui.treeWidget->setHeaderLabels(headers);
	this->ui.treeWidget->setAcceptDrops(true);
	this->ui.treeWidget->setDragEnabled(true);
	this->ui.treeWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void QtWidgetsApplication::addUserDataToTreeWidget()
{
	QTreeWidgetItem* item = new QTreeWidgetItem(this->ui.treeWidget);
	item->setText(0, "Good");

	Data *myData1 = new Data(16);
	auto data = QVariant::fromValue(*myData1);
	item->setData(0, Qt::UserRole, data);
}

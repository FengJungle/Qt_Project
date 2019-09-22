#ifndef QTSQL_H
#define QTSQL_H

#include <QtGui/QWidget>
#include "ui_QtSql.h"
///Qt Print
#include <QtDebug>
///Qt SQL
#include <QSqlQuery>
#include <QSqlDatabase>

class QtSql : public QWidget
{
	Q_OBJECT

public:
	QtSql(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QtSql();

private:
	Ui::QtSqlClass ui;
};

#endif // QTSQL_H

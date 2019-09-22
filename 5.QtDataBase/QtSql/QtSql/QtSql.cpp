#include "QtSql.h"

QtSql::QtSql(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	///打印已有的数据库驱动
	QStringList drivers = QSqlDatabase::drivers();
	foreach(QString driver,drivers)
		qDebug()<<driver;

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","DB_Jungle");
	db.setDatabaseName("myDB.db");
	if(!db.open())
		qDebug()<<"Open failed!";

	QSqlQuery query(db);
	query.exec("create table student (id int primary key,name varchar(20))");
	query.exec("insert into student values(0,LiMing)");
	query.exec("insert into student values(1,NieWei)");
	query.exec("insert into student values(2,WangHong)");

	query.exec("select * from student");
	while(query.next())
	{
		qDebug()<<query.value(0).toInt()<<query.value(1).toString();
	}
}

QtSql::~QtSql()
{

}

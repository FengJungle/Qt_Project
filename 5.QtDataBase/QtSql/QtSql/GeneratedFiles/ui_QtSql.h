/********************************************************************************
** Form generated from reading UI file 'QtSql.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSQL_H
#define UI_QTSQL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtSqlClass
{
public:
    QWidget *widget;

    void setupUi(QWidget *QtSqlClass)
    {
        if (QtSqlClass->objectName().isEmpty())
            QtSqlClass->setObjectName(QString::fromUtf8("QtSqlClass"));
        QtSqlClass->resize(600, 400);
        widget = new QWidget(QtSqlClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 461, 371));

        retranslateUi(QtSqlClass);

        QMetaObject::connectSlotsByName(QtSqlClass);
    } // setupUi

    void retranslateUi(QWidget *QtSqlClass)
    {
        QtSqlClass->setWindowTitle(QApplication::translate("QtSqlClass", "QtSql", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QtSqlClass: public Ui_QtSqlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSQL_H

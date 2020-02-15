/********************************************************************************
** Form generated from reading UI file 'qtserver.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSERVER_H
#define UI_QTSERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtServerClass
{
public:
    QTextEdit *browser;
    QPushButton *pushButton_close;
    QPushButton *pushButton_send;
    QLineEdit *lineEdit;
    QProgressBar *progressBar_fileProgress;

    void setupUi(QWidget *QtServerClass)
    {
        if (QtServerClass->objectName().isEmpty())
            QtServerClass->setObjectName(QString::fromUtf8("QtServerClass"));
        QtServerClass->resize(600, 400);
        browser = new QTextEdit(QtServerClass);
        browser->setObjectName(QString::fromUtf8("browser"));
        browser->setGeometry(QRect(20, 10, 381, 271));
        pushButton_close = new QPushButton(QtServerClass);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(420, 10, 75, 23));
        pushButton_send = new QPushButton(QtServerClass);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setGeometry(QRect(460, 300, 75, 23));
        lineEdit = new QLineEdit(QtServerClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 300, 381, 31));
        progressBar_fileProgress = new QProgressBar(QtServerClass);
        progressBar_fileProgress->setObjectName(QString::fromUtf8("progressBar_fileProgress"));
        progressBar_fileProgress->setGeometry(QRect(420, 40, 171, 23));
        progressBar_fileProgress->setValue(0);

        retranslateUi(QtServerClass);

        QMetaObject::connectSlotsByName(QtServerClass);
    } // setupUi

    void retranslateUi(QWidget *QtServerClass)
    {
        QtServerClass->setWindowTitle(QApplication::translate("QtServerClass", "QtServer", 0, QApplication::UnicodeUTF8));
        pushButton_close->setText(QApplication::translate("QtServerClass", "Close", 0, QApplication::UnicodeUTF8));
        pushButton_send->setText(QApplication::translate("QtServerClass", "Send", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QtServerClass: public Ui_QtServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSERVER_H

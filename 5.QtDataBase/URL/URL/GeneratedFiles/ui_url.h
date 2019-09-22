/********************************************************************************
** Form generated from reading UI file 'url.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_URL_H
#define UI_URL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_URLClass
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;

    void setupUi(QWidget *URLClass)
    {
        if (URLClass->objectName().isEmpty())
            URLClass->setObjectName(QString::fromUtf8("URLClass"));
        URLClass->resize(600, 400);
        pushButton = new QPushButton(URLClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(400, 100, 75, 23));
        lineEdit = new QLineEdit(URLClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 100, 321, 41));
        textEdit = new QTextEdit(URLClass);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(60, 170, 511, 211));

        retranslateUi(URLClass);

        QMetaObject::connectSlotsByName(URLClass);
    } // setupUi

    void retranslateUi(QWidget *URLClass)
    {
        URLClass->setWindowTitle(QApplication::translate("URLClass", "URL", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("URLClass", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class URLClass: public Ui_URLClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_URL_H

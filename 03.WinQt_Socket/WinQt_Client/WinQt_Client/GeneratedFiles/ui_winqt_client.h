/********************************************************************************
** Form generated from reading UI file 'winqt_client.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINQT_CLIENT_H
#define UI_WINQT_CLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinQt_ClientClass
{
public:
    QLineEdit *lineEdit_a;
    QLabel *label_2;
    QLineEdit *lineEdit_b;
    QLabel *label_4;
    QTextEdit *textEdit;
    QLabel *label_3;
    QPushButton *pushButton_calculate;
    QLineEdit *lineEdit_sum;
    QLabel *label;

    void setupUi(QWidget *WinQt_ClientClass)
    {
        if (WinQt_ClientClass->objectName().isEmpty())
            WinQt_ClientClass->setObjectName(QString::fromUtf8("WinQt_ClientClass"));
        WinQt_ClientClass->resize(325, 338);
        lineEdit_a = new QLineEdit(WinQt_ClientClass);
        lineEdit_a->setObjectName(QString::fromUtf8("lineEdit_a"));
        lineEdit_a->setGeometry(QRect(100, 60, 113, 20));
        label_2 = new QLabel(WinQt_ClientClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 90, 21, 16));
        lineEdit_b = new QLineEdit(WinQt_ClientClass);
        lineEdit_b->setObjectName(QString::fromUtf8("lineEdit_b"));
        lineEdit_b->setGeometry(QRect(100, 90, 113, 20));
        label_4 = new QLabel(WinQt_ClientClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 20, 61, 16));
        textEdit = new QTextEdit(WinQt_ClientClass);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(50, 150, 241, 161));
        label_3 = new QLabel(WinQt_ClientClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 120, 31, 16));
        pushButton_calculate = new QPushButton(WinQt_ClientClass);
        pushButton_calculate->setObjectName(QString::fromUtf8("pushButton_calculate"));
        pushButton_calculate->setGeometry(QRect(220, 120, 75, 23));
        lineEdit_sum = new QLineEdit(WinQt_ClientClass);
        lineEdit_sum->setObjectName(QString::fromUtf8("lineEdit_sum"));
        lineEdit_sum->setGeometry(QRect(100, 120, 113, 20));
        label = new QLabel(WinQt_ClientClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 60, 21, 16));

        retranslateUi(WinQt_ClientClass);

        QMetaObject::connectSlotsByName(WinQt_ClientClass);
    } // setupUi

    void retranslateUi(QWidget *WinQt_ClientClass)
    {
        WinQt_ClientClass->setWindowTitle(QApplication::translate("WinQt_ClientClass", "WinQt_Client", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WinQt_ClientClass", "b\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("WinQt_ClientClass", "\346\234\215\345\212\241\345\231\250IP\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("WinQt_ClientClass", "sum\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_calculate->setText(QApplication::translate("WinQt_ClientClass", "\350\256\241\347\256\227", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WinQt_ClientClass", "a\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WinQt_ClientClass: public Ui_WinQt_ClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINQT_CLIENT_H

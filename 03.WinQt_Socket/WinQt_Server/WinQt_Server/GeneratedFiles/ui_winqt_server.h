/********************************************************************************
** Form generated from reading UI file 'winqt_server.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINQT_SERVER_H
#define UI_WINQT_SERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinQt_ServerClass
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QTextEdit *textEdit;

    void setupUi(QWidget *WinQt_ServerClass)
    {
        if (WinQt_ServerClass->objectName().isEmpty())
            WinQt_ServerClass->setObjectName(QString::fromUtf8("WinQt_ServerClass"));
        WinQt_ServerClass->resize(323, 337);
        gridLayout = new QGridLayout(WinQt_ServerClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(WinQt_ServerClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        textEdit = new QTextEdit(WinQt_ServerClass);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 1, 2);


        retranslateUi(WinQt_ServerClass);

        QMetaObject::connectSlotsByName(WinQt_ServerClass);
    } // setupUi

    void retranslateUi(QWidget *WinQt_ServerClass)
    {
        WinQt_ServerClass->setWindowTitle(QApplication::translate("WinQt_ServerClass", "WinQt_Server", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("WinQt_ServerClass", "\345\274\200\345\247\213\347\233\221\345\220\254", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WinQt_ServerClass: public Ui_WinQt_ServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINQT_SERVER_H

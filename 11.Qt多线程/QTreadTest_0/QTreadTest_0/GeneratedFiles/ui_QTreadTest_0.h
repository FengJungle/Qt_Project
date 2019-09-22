/********************************************************************************
** Form generated from reading UI file 'QTreadTest_0.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTREADTEST_0_H
#define UI_QTREADTEST_0_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTreadTest_0Class
{
public:
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;

    void setupUi(QWidget *QTreadTest_0Class)
    {
        if (QTreadTest_0Class->objectName().isEmpty())
            QTreadTest_0Class->setObjectName(QString::fromUtf8("QTreadTest_0Class"));
        QTreadTest_0Class->resize(315, 210);
        pushButton = new QPushButton(QTreadTest_0Class);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 60, 75, 23));
        textEdit = new QTextEdit(QTreadTest_0Class);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 10, 191, 191));
        pushButton_2 = new QPushButton(QTreadTest_0Class);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 30, 75, 23));

        retranslateUi(QTreadTest_0Class);

        QMetaObject::connectSlotsByName(QTreadTest_0Class);
    } // setupUi

    void retranslateUi(QWidget *QTreadTest_0Class)
    {
        QTreadTest_0Class->setWindowTitle(QApplication::translate("QTreadTest_0Class", "QTreadTest_0", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QTreadTest_0Class", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("QTreadTest_0Class", "\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QTreadTest_0Class: public Ui_QTreadTest_0Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTREADTEST_0_H

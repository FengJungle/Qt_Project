/********************************************************************************
** Form generated from reading UI file 'qtclient.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCLIENT_H
#define UI_QTCLIENT_H

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

class Ui_QtClientClass
{
public:
    QPushButton *pushButton_connect;
    QPushButton *pushButton_disconnect;
    QPushButton *pushButton_send;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPushButton *pushButton_openFile;
    QLineEdit *lineEdit_filename;
    QPushButton *pushButton_sendFile;
    QProgressBar *progressBar;

    void setupUi(QWidget *QtClientClass)
    {
        if (QtClientClass->objectName().isEmpty())
            QtClientClass->setObjectName(QString::fromUtf8("QtClientClass"));
        QtClientClass->resize(600, 400);
        pushButton_connect = new QPushButton(QtClientClass);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(370, 30, 75, 23));
        pushButton_disconnect = new QPushButton(QtClientClass);
        pushButton_disconnect->setObjectName(QString::fromUtf8("pushButton_disconnect"));
        pushButton_disconnect->setGeometry(QRect(460, 30, 75, 23));
        pushButton_send = new QPushButton(QtClientClass);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setGeometry(QRect(360, 260, 75, 23));
        lineEdit = new QLineEdit(QtClientClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 250, 331, 31));
        textEdit = new QTextEdit(QtClientClass);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 20, 331, 221));
        pushButton_openFile = new QPushButton(QtClientClass);
        pushButton_openFile->setObjectName(QString::fromUtf8("pushButton_openFile"));
        pushButton_openFile->setGeometry(QRect(370, 100, 75, 23));
        lineEdit_filename = new QLineEdit(QtClientClass);
        lineEdit_filename->setObjectName(QString::fromUtf8("lineEdit_filename"));
        lineEdit_filename->setGeometry(QRect(370, 70, 181, 20));
        pushButton_sendFile = new QPushButton(QtClientClass);
        pushButton_sendFile->setObjectName(QString::fromUtf8("pushButton_sendFile"));
        pushButton_sendFile->setGeometry(QRect(480, 100, 75, 23));
        progressBar = new QProgressBar(QtClientClass);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(370, 140, 211, 23));
        progressBar->setValue(0);

        retranslateUi(QtClientClass);

        QMetaObject::connectSlotsByName(QtClientClass);
    } // setupUi

    void retranslateUi(QWidget *QtClientClass)
    {
        QtClientClass->setWindowTitle(QApplication::translate("QtClientClass", "QtClient", 0, QApplication::UnicodeUTF8));
        pushButton_connect->setText(QApplication::translate("QtClientClass", "Connect", 0, QApplication::UnicodeUTF8));
        pushButton_disconnect->setText(QApplication::translate("QtClientClass", "Disconnect", 0, QApplication::UnicodeUTF8));
        pushButton_send->setText(QApplication::translate("QtClientClass", "Send", 0, QApplication::UnicodeUTF8));
        pushButton_openFile->setText(QApplication::translate("QtClientClass", "Open File", 0, QApplication::UnicodeUTF8));
        pushButton_sendFile->setText(QApplication::translate("QtClientClass", "Send File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QtClientClass: public Ui_QtClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCLIENT_H

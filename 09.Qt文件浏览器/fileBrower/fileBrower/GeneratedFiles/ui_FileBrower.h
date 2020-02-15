/********************************************************************************
** Form generated from reading UI file 'FileBrower.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEBROWER_H
#define UI_FILEBROWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileBrowerClass
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QListWidget *listWidget;

    void setupUi(QWidget *FileBrowerClass)
    {
        if (FileBrowerClass->objectName().isEmpty())
            FileBrowerClass->setObjectName(QString::fromUtf8("FileBrowerClass"));
        FileBrowerClass->resize(291, 263);
        gridLayout = new QGridLayout(FileBrowerClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(FileBrowerClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        listWidget = new QListWidget(FileBrowerClass);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 1, 0, 1, 1);


        retranslateUi(FileBrowerClass);

        QMetaObject::connectSlotsByName(FileBrowerClass);
    } // setupUi

    void retranslateUi(QWidget *FileBrowerClass)
    {
        FileBrowerClass->setWindowTitle(QApplication::translate("FileBrowerClass", "FileBrower", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FileBrowerClass: public Ui_FileBrowerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEBROWER_H

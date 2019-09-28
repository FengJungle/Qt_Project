/********************************************************************************
** Form generated from reading UI file 'qkeyboard.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QKEYBOARD_H
#define UI_QKEYBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QKeyBoardClass
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit_press;
    QTextEdit *textEdit_release;

    void setupUi(QWidget *QKeyBoardClass)
    {
        if (QKeyBoardClass->objectName().isEmpty())
            QKeyBoardClass->setObjectName(QString::fromUtf8("QKeyBoardClass"));
        QKeyBoardClass->resize(563, 355);
        gridLayout = new QGridLayout(QKeyBoardClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit_press = new QTextEdit(QKeyBoardClass);
        textEdit_press->setObjectName(QString::fromUtf8("textEdit_press"));
        textEdit_press->setFocusPolicy(Qt::NoFocus);
        textEdit_press->setReadOnly(true);

        gridLayout->addWidget(textEdit_press, 0, 0, 1, 1);

        textEdit_release = new QTextEdit(QKeyBoardClass);
        textEdit_release->setObjectName(QString::fromUtf8("textEdit_release"));
        textEdit_release->setFocusPolicy(Qt::NoFocus);
        textEdit_release->setReadOnly(true);

        gridLayout->addWidget(textEdit_release, 0, 1, 1, 1);


        retranslateUi(QKeyBoardClass);

        QMetaObject::connectSlotsByName(QKeyBoardClass);
    } // setupUi

    void retranslateUi(QWidget *QKeyBoardClass)
    {
        QKeyBoardClass->setWindowTitle(QApplication::translate("QKeyBoardClass", "QKeyBoard", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QKeyBoardClass: public Ui_QKeyBoardClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QKEYBOARD_H

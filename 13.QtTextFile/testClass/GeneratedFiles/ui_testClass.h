/********************************************************************************
** Form generated from reading UI file 'testClass.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTCLASS_H
#define UI_TESTCLASS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testClassClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QPushButton *pushButton_saveFile;
    QPushButton *pushButton_openFile;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *testClassClass)
    {
        if (testClassClass->objectName().isEmpty())
            testClassClass->setObjectName(QString::fromUtf8("testClassClass"));
        testClassClass->resize(295, 263);
        centralWidget = new QWidget(testClassClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 2);

        pushButton_saveFile = new QPushButton(centralWidget);
        pushButton_saveFile->setObjectName(QString::fromUtf8("pushButton_saveFile"));

        gridLayout->addWidget(pushButton_saveFile, 1, 0, 1, 1);

        pushButton_openFile = new QPushButton(centralWidget);
        pushButton_openFile->setObjectName(QString::fromUtf8("pushButton_openFile"));

        gridLayout->addWidget(pushButton_openFile, 1, 1, 1, 1);

        testClassClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(testClassClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 295, 23));
        testClassClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(testClassClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        testClassClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(testClassClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        testClassClass->setStatusBar(statusBar);

        retranslateUi(testClassClass);

        QMetaObject::connectSlotsByName(testClassClass);
    } // setupUi

    void retranslateUi(QMainWindow *testClassClass)
    {
        testClassClass->setWindowTitle(QApplication::translate("testClassClass", "testClass", 0, QApplication::UnicodeUTF8));
        pushButton_saveFile->setText(QApplication::translate("testClassClass", "\345\206\231\345\205\245\346\226\207\346\234\254\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        pushButton_openFile->setText(QApplication::translate("testClassClass", "\346\211\223\345\274\200\346\226\207\346\234\254\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class testClassClass: public Ui_testClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTCLASS_H

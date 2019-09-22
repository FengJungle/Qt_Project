/********************************************************************************
** Form generated from reading UI file 'happychat.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAPPYCHAT_H
#define UI_HAPPYCHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HappyChatClass
{
public:
    QTextBrowser *messageBrowser;
    QFontComboBox *fontComboBox;
    QComboBox *sizeComboBox;
    QPushButton *pushButton_bold;
    QPushButton *pushButton_italic;
    QPushButton *pushButton_save;
    QPushButton *pushButton_clear;
    QTextEdit *textEdit_message;
    QPushButton *pushButtonSend;
    QPushButton *pushButton_quit;
    QTableWidget *tableWidget;
    QLabel *label;

    void setupUi(QWidget *HappyChatClass)
    {
        if (HappyChatClass->objectName().isEmpty())
            HappyChatClass->setObjectName(QString::fromUtf8("HappyChatClass"));
        HappyChatClass->resize(735, 391);
        messageBrowser = new QTextBrowser(HappyChatClass);
        messageBrowser->setObjectName(QString::fromUtf8("messageBrowser"));
        messageBrowser->setGeometry(QRect(20, 10, 391, 261));
        fontComboBox = new QFontComboBox(HappyChatClass);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(20, 280, 161, 22));
        sizeComboBox = new QComboBox(HappyChatClass);
        sizeComboBox->setObjectName(QString::fromUtf8("sizeComboBox"));
        sizeComboBox->setGeometry(QRect(190, 280, 41, 22));
        pushButton_bold = new QPushButton(HappyChatClass);
        pushButton_bold->setObjectName(QString::fromUtf8("pushButton_bold"));
        pushButton_bold->setGeometry(QRect(230, 280, 31, 23));
        pushButton_bold->setCheckable(true);
        pushButton_italic = new QPushButton(HappyChatClass);
        pushButton_italic->setObjectName(QString::fromUtf8("pushButton_italic"));
        pushButton_italic->setGeometry(QRect(260, 280, 31, 23));
        pushButton_save = new QPushButton(HappyChatClass);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(290, 280, 71, 23));
        pushButton_clear = new QPushButton(HappyChatClass);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(360, 280, 51, 23));
        textEdit_message = new QTextEdit(HappyChatClass);
        textEdit_message->setObjectName(QString::fromUtf8("textEdit_message"));
        textEdit_message->setGeometry(QRect(20, 310, 331, 71));
        pushButtonSend = new QPushButton(HappyChatClass);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));
        pushButtonSend->setGeometry(QRect(360, 350, 51, 31));
        pushButton_quit = new QPushButton(HappyChatClass);
        pushButton_quit->setObjectName(QString::fromUtf8("pushButton_quit"));
        pushButton_quit->setGeometry(QRect(360, 310, 51, 31));
        tableWidget = new QTableWidget(HappyChatClass);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(420, 10, 311, 351));
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        label = new QLabel(HappyChatClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(420, 370, 311, 20));

        retranslateUi(HappyChatClass);

        sizeComboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(HappyChatClass);
    } // setupUi

    void retranslateUi(QWidget *HappyChatClass)
    {
        HappyChatClass->setWindowTitle(QApplication::translate("HappyChatClass", "HappyChat", 0, QApplication::UnicodeUTF8));
        sizeComboBox->clear();
        sizeComboBox->insertItems(0, QStringList()
         << QApplication::translate("HappyChatClass", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HappyChatClass", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HappyChatClass", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HappyChatClass", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HappyChatClass", "13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HappyChatClass", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HappyChatClass", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HappyChatClass", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HappyChatClass", "17", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        sizeComboBox->setToolTip(QApplication::translate("HappyChatClass", "\345\255\227\345\217\267", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButton_bold->setToolTip(QApplication::translate("HappyChatClass", "\345\212\240\347\262\227", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton_bold->setText(QApplication::translate("HappyChatClass", "B", 0, QApplication::UnicodeUTF8));
        pushButton_italic->setText(QApplication::translate("HappyChatClass", "I", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("HappyChatClass", "\344\277\235\345\255\230\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        pushButton_clear->setText(QApplication::translate("HappyChatClass", "\346\270\205\351\231\244", 0, QApplication::UnicodeUTF8));
        pushButtonSend->setText(QApplication::translate("HappyChatClass", "Send", 0, QApplication::UnicodeUTF8));
        pushButton_quit->setText(QApplication::translate("HappyChatClass", "Quit", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("HappyChatClass", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("HappyChatClass", "\344\270\273\346\234\272\345\220\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("HappyChatClass", "IP\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HappyChatClass", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HappyChatClass: public Ui_HappyChatClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAPPYCHAT_H

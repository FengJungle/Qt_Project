#ifndef QKEYBOARD_H
#define QKEYBOARD_H

#include <QtGui/QWidget>
#include "ui_qkeyboard.h"

#include <QKeyEvent>

#include <QtDebug>

class QKeyBoard : public QWidget
{
	Q_OBJECT

public:
	QKeyBoard(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QKeyBoard();

	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);

private:
	Ui::QKeyBoardClass ui;
};

#endif // QKEYBOARD_H

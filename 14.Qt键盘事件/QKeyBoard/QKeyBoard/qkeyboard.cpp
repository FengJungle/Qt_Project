#include "qkeyboard.h"

QKeyBoard::QKeyBoard(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);
	
}

QKeyBoard::~QKeyBoard()
{

}

void QKeyBoard::keyPressEvent(QKeyEvent *e){
	switch(e->key()){
		case Qt::Key_Escape:
			this->ui.textEdit->append("Key_Escape");
			break;
		case Qt::Key_Tab:
			this->ui.textEdit->append("Key_Tab");
			break;
		case Qt::Key_Enter:
			this->ui.textEdit->append("Key_Enter");
			break;
		case Qt::Key_Delete:
			this->ui.textEdit->append("Key_Delete");
			break;
		case Qt::Key_Space:
			this->ui.textEdit->append("Key_Space");
			break;
		case Qt::Key_Left:
			this->ui.textEdit->append("Key_Left");
			break;
		case Qt::Key_Up:
			this->ui.textEdit->append("Key_Up");
			break;
		case Qt::Key_Right:
			this->ui.textEdit->append("Key_Right");
			break;
		case Qt::Key_Down:
			this->ui.textEdit->append("Key_Down");
			break;
		/*default:
			this->ui.textEdit->append("KeyEvent");*/
	}
}

#include "qsendtextedit.h"

QSendTextEdit::QSendTextEdit(QWidget *parent) :
    QPlainTextEdit(parent)
{
}

void QSendTextEdit::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->type() == QEvent::MouseButtonDblClick)
    {
   //     appendPlainText("double click");
        emit mouseDoubleClick();
    }

}

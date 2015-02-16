#ifndef QSENDTEXTEDIT_H
#define QSENDTEXTEDIT_H

#include <QPlainTextEdit>

class QSendTextEdit : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit QSendTextEdit(QWidget *parent = 0);
    
signals:
    void mouseDoubleClick(void);
public slots:

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *e);
    
};

#endif // QSENDTEXTEDIT_H

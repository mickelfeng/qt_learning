#ifndef EXITMESSAGEBOX_H
#define EXITMESSAGEBOX_H

#include <QMessageBox>

class ExitMessageBox : public QMessageBox
{
    Q_OBJECT
public:
    explicit ExitMessageBox(QWidget *parent = 0);

signals:

public slots:

};

#endif // EXITMESSAGEBOX_H

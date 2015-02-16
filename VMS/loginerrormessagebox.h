/******************************************
 *错误消息对话框
 *****************************************/
#ifndef LOGINERRORMESSAGEBOX_H
#define LOGINERRORMESSAGEBOX_H

#include <QMessageBox>
#include <QCloseEvent>

class LoginErrorMessageBox : public QMessageBox
{
    Q_OBJECT
public:
    explicit LoginErrorMessageBox(QWidget *parent = 0);

    enum errorFlag{NoUser = 0, PasswordErr, UserBlank, NoFind};

    void ErrorMessageBox(errorFlag flag);

    ~LoginErrorMessageBox();
protected:
    void closeEvent(QCloseEvent *event);

signals:

public slots:

};

#endif // LOGINERRORMESSAGEBOX_H

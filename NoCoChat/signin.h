#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>
#include <QHostAddress>
#include "handle.h"
#include <QMessageBox>
#include <QTextCodec>
#include <QString>

namespace Ui {
class Signin;
}

class Signin : public QDialog
{
    Q_OBJECT

public:
    explicit Signin(QWidget *parent = 0);
    ~Signin();

    QString userid ;    // 用户帐号
    QString userName; //用户昵称
    QString pwd ;   // 用户密码

//    获取用户id
    QString getUserId();
//    获取端口
    int getPort();
//    设置端口
    void setPort(int p);
//    返回用户名
    QString getUserName();
//    设置handle
    void setHandle(Handle *h);

private slots:
    void on_b_signin_clicked();

    void on_b_login_clicked();

private:
    Ui::Signin *ui;
    Handle *handle;
    int port;
};

#endif // SIGNIN_H

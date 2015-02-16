#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QString>
#include "handle.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

    void userInfo() ;

private slots:
    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::Login *ui;

    Handle handle ; // 处理用户注册信息对象
    QString userid ;    // 帐号（ID）
    QString username ;  // 用户名（昵称）
    QString userpwd ;   // 密码
};

#endif // LOGIN_H

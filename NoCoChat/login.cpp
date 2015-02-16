#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);


    userInfo();
}

Login::~Login()
{
    delete ui;
}

// 获取用户注册信息
void Login::userInfo()
{
    ui->pwd->setEchoMode(QLineEdit::Password);      // 改变密码输入框的显示格式
    ui->pwd_1->setEchoMode(QLineEdit::Password);
}

void Login::on_ok_clicked()
{
    // 判断两次输入的密码是否相同
    userid = ui->user_id->text() ;  // 获取用户帐号（ID）
    username = ui->name->text() ;   // 获取用户名（昵称）
    userpwd = ui->pwd->text() ;     // 获取用户第一次输入的密码
    if (ui->pwd_1->text() == userpwd)
    {
        // 两次输入的密码相同
        // 鼗用户的注册信息提交于服务器，并用服务器响应的返回值是否注册成功
        if (handle.registered(userid,username,userpwd))
        {
            QMessageBox::about(this, "消息", "恭喜您，注册成功！") ;
            this->close() ;
        }else{
            QMessageBox::about(this, "消息", "对不起，该帐号已存在！") ;
            ui->user_id->setText("");
            ui->name->setText("");
            ui->pwd->setText("");
            ui->pwd_1->setText("");
        }
    }else{
        QMessageBox::about(this, "消息", "两次密码输入不一致") ;
        ui->pwd->setText("");
        ui->pwd_1->setText("");
    }
}

// 点出取消按钮，退出本窗口
void Login::on_cancel_clicked()
{
    this->close();
}

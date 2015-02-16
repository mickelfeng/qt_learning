#include "loginerrormessagebox.h"

LoginErrorMessageBox::LoginErrorMessageBox(QWidget *parent) :
    QMessageBox(parent)
{

}


void LoginErrorMessageBox::ErrorMessageBox(errorFlag flag)
{
    switch(flag)
    {
    case NoUser:     //用户不存在
        if(QMessageBox::Ok == QMessageBox::warning(this, "错误", "用户不存在", QMessageBox::Ok, QMessageBox::Ok)) close();
        break;
    case PasswordErr:     //密码错误
        if(QMessageBox::Ok == QMessageBox::warning(this, "错误", "密码错误", QMessageBox::Ok, QMessageBox::Ok)) close();
        break;
    case UserBlank:
        if(QMessageBox::Ok == QMessageBox::warning(this, "错误", "用户名不能为空", QMessageBox::Ok, QMessageBox::Ok)) close();
        break;
    case NoFind:
        QMessageBox::critical(this, "错误", "数据库打开失败");
    default:
        break;

    }
}

void LoginErrorMessageBox::closeEvent(QCloseEvent *event)
{
    event->ignore();
}

LoginErrorMessageBox::~LoginErrorMessageBox()
{

}

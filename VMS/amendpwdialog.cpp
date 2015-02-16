#include "amendpwdialog.h"
#include "ui_amendpwdialog.h"

AmendPWDialog::AmendPWDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AmendPWDialog)
{
    ui->setupUi(this);    
}

AmendPWDialog::~AmendPWDialog()
{
    delete ui;
}

void AmendPWDialog::on_amendOKButton_clicked()
{
    QString user = ui->userLineEdit->text();
    QString passWord = ui->pwLineEdit->text();
    QString newPassWord = ui->newPWlineEdit->text();
    QString newPassWord2 = ui->newPwlineEdit2->text();
    QSqlQuery query;
    query.exec("SELECT user, password FROM account "
               "where user == '" + user + "'");
    query.first();

    if(user.isEmpty()|passWord.isEmpty()|newPassWord.isEmpty()|newPassWord2.isEmpty())
    {
        QMessageBox::critical(this, "错误", "内容不能为空", QMessageBox::Ok);
    }
    else if(0 != newPassWord.compare(newPassWord2))
    {
        QMessageBox::critical(this, "错误", "新密码两次输入不一致", QMessageBox::Ok);
    }
    else if(query.value(0).toString().isEmpty())
    {
        QMessageBox::critical(this, "错误", "用户不存在", QMessageBox::Ok);
    }
    else if(0 != query.value(1).toString().compare(passWord))
    {
        QMessageBox::critical(this, "错误", "密码错误", QMessageBox::Ok);
    }
    else
    {
        bool flag = query.exec(QString("UPDATE account SET password = '%1' WHERE user = '%2'").arg(newPassWord).arg(user));
        if(flag)
        {
            QMessageBox::information(this,"修改成功", "密码修改成功", QMessageBox::Ok);
            close();
        }
        else
        {
            QMessageBox::critical(this, "错误", "注册失败", QMessageBox::Ok);
        }
    }
}

void AmendPWDialog::on_amendCancleButton_clicked()
{
    close();
}

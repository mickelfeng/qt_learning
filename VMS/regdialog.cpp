#include "regdialog.h"
#include "ui_regdialog.h"

RegDialog::RegDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegDialog)
{
    ui->setupUi(this);
}

RegDialog::~RegDialog()
{
    delete ui;
}

void RegDialog::on_regButton_clicked()
{
    QString user = ui->userLineEdit->text();
    QString password = ui->pwLineEdit->text();
    QSqlQuery query;
    query.exec(QString("SELECT user FROM account WHERE user = '%1'").arg(user));
    query.first();
    if(user.isEmpty()|password.isEmpty())
    {
        QMessageBox::critical(this, "错误", "内容不能为空", QMessageBox::Ok);
    }
    else if(0 == query.value(0).toString().compare(user))
    {
        QMessageBox::critical(this, "错误", "用户名已存在", QMessageBox::Ok);
    }
    else
    {
        bool flag = query.exec(QString("INSERT INTO account VALUES('%1', '%2')").arg(user).arg(password));
        if(flag)
        {
            QMessageBox::information(this,"注册成功", "用户注册成功", QMessageBox::Ok);
            close();
        }
        else
        {
            QMessageBox::critical(this, "错误", "注册失败", QMessageBox::Ok);
        }
    }
}

void RegDialog::on_cancleButton_clicked()
{
    close();
}

#include "signin.h"
#include "ui_signin.h"
#include "login.h"


Signin::Signin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signin)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    ui->setupUi(this);

}

Signin::~Signin()
{
    delete ui;
}

void Signin::on_b_signin_clicked()
{
    /*
        //验证模块——简易认证
        QString user_name="jancojie";
        QString user_pwd="84251033";
        if(ui->username->text()==user_name&&ui->password->text()==user_pwd)
   */
    /*
        验证模块——服务器验证
     */
    userid = ui->user_id->text() ;
    pwd = ui->password->text() ;
    QString result=handle->signIn(userid, pwd, port);
    if(result=="1")
    {
       QMessageBox::warning(this,"提示","密码或用户名错误！");

    }else if(result=="2"){
        QMessageBox::warning(this,"提示","用户已占线");
    }
    else if(result=="3"){
            QMessageBox::warning(this,"提示","未知错误");
    }
    else
    {
        QMessageBox::about(this,"提示","登录成功！");
        userName=result;
        accept();
        close();
    }
}
void Signin::setHandle(Handle *h)
{
    handle=h;
}
void Signin::on_b_login_clicked()
{
    Login *login = new Login(this) ;
    login->setModal(true);
    login->exec();
}

QString Signin::getUserId()
{
    return userid;
}
int Signin::getPort()
{
    return port;
}
void Signin::setPort(int p)
{
    port=p;
}
QString Signin::getUserName()
{
    return userName;
}

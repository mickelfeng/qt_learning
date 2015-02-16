#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);     //取消对话框中的关闭按钮，问号按钮,只显示title
    loginstatus = false;
    loginInit();
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete loginErrMsg;
    delete exitMsg;
    delete ui;
}

void LoginDialog::loginInit()       //登录初始化
{
    QFileInfo dbfile("vegetable.db");
    if(!dbfile.exists())
    {
        db = new DataBase;
        if(!db->openDataBase("vegetable.db", "QSQLITE"))
        {
            QMessageBox::critical(this, "错误", "数据库打开失败！！！", QMessageBox::Ok);
            exit(0);
        }
        else
        {
            db->createTable();
            db->closeDataBase();
        }
    }
}

void LoginDialog::on_exitButton_clicked()       //退出按钮的槽函数实现
{
    exitMsg = new ExitMessageBox;
}

void LoginDialog::on_loginButton_clicked()      //登录信息比对
{
    QSqlDatabase vegetableDb = QSqlDatabase::addDatabase("QSQLITE");
    vegetableDb.setDatabaseName("vegetable.db");
    QString user = ui->userLineEdit->text();
//    QMessageBox::information(this,"test",user,QMessageBox::Ok);   //测试用
    QString password = ui->pwLineEdit->text();
    if(!vegetableDb.open())
    {
        QMessageBox::critical(this, "错误", "数据库打开失败！！！", QMessageBox::Ok);
        exit(0);
    }
    QSqlQuery query;

    query.exec("SELECT user, password FROM account "
               "where user == '" + user + "'");
    query.first();
    loginErrMsg = new LoginErrorMessageBox;

    if (0 == user.compare(""))
    {
        loginErrMsg->ErrorMessageBox(LoginErrorMessageBox::UserBlank);        //用户名为空
    }
    else
    {
        if(0 == user.compare(query.value(0).toString()))
        {
            if(0 == password.compare(query.value(1).toString()))
            {
                loginstatus = true;
                currentUser = query.value(0).toString();
                vegetableDb.close();
                close();


            }
            else
            {
                loginstatus = false;
                loginErrMsg->ErrorMessageBox(LoginErrorMessageBox::PasswordErr);        //密码错误
            }
        }
        else
        {
            loginstatus = false;
            loginErrMsg->ErrorMessageBox(LoginErrorMessageBox::NoUser);        //用户不存在
        }
    }
}

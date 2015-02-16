#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFileInfo>
//#include <QSqlDatabase>
//#include <QSqlQuery>
#include <QtSql>
#include <QCloseEvent>
#include "loginerrormessagebox.h"
#include "exitmessagebox.h"
#include "database.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    bool loginstatus;                       //登录状态
    QString currentUser;

    ~LoginDialog();

//protected:
//        void closeEvent(QCloseEvent *event);


private slots:
        void on_exitButton_clicked();

        void on_loginButton_clicked();

private:

    Ui::LoginDialog *ui;
    void loginInit();
    LoginErrorMessageBox *loginErrMsg;      //登录错误提示对话框
    ExitMessageBox *exitMsg;
    DataBase *db;

};

#endif // LOGINDIALOG_H

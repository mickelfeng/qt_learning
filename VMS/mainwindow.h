#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QTimer>
#include <QTableView>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QSqlQuery>
#include "logindialog.h"
#include "combodelegate.h"
#include "purchasemsgdialog.h"
#include "aboutdialog.h"
#include "amendpwdialog.h"
#include "regdialog.h"
#include "database.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
        void closeEvent(QCloseEvent *event);

private:

    void createAction();
    void currentTimeShowTimer(); //创建定时器，用来控制当前时间状态栏显示

    //purchase
    void purchaseInterface();
    void setPurchaseModelHeader();
    //data
    void farmerInterFace();       //注册farmer资料
    void loadFarmerModel(QTableView *tv);
    void setFarmerModelHeader();
    void getInputFarmer();
    void clearInputFarmer();
    bool fidexists(QString id);

    DataBase *db;

    Ui::MainWindow *ui;
    LoginDialog *login;             //登录界面
    QAction *purchaseAction;        //收购Action
    QAction *farmerAction;          //农户Action
    QLabel *msgStatusLable;         //statusBar信息label
    QLabel *currentTimeLable;       //statusBar当前时间label
    QTimer *timer;                  //一个定时器 1000ms触发一次

    QSqlDatabase vegetableDb;       //数据库对象
    QSqlTableModel *farmerModel;    //...
    QSqlTableModel *purchaseModel;
    ComboDelegate combodegate;
    AboutDialog *about;
    AmendPWDialog *amendPW;
    RegDialog *reg;

    QString fname;
    QString fid;
    QString fsex;
    QString ftele;
    QString faddress;
    QString selectSql;


   enum farmerStatusEnum{farmerNo, farmerAdd, farmerSelect, farmerAmend, farmerDelete};   //状态
   farmerStatusEnum farmerStatus;

private slots:
    void purchaseAction_activated();
    void farmerAction_activated();
    void currentTimeShow();

    void on_farmerAddButton_clicked();
    void on_farmerOkButton_clicked();
    void on_farmerCommitButton_clicked();
    void on_farmerSelectButton_clicked();
    void on_purchaseAddButton_clicked();
    void on_farmerAmendButton_clicked();
    void on_farmerRefreshButton_clicked();
    void on_farmerCancelButton_clicked();
    void on_farmerDeleteButton_clicked();
    void on_purchaseRefreshButton_clicked();
    void on_purchaseCommitButton_clicked();
    void on_purchaseCancelButton_clicked();
    void on_purchaseTableView_doubleClicked(const QModelIndex &index);
    void on_farmerDataAction_triggered();
    void on_purchaseDataAction_triggered();
    void on_exitaction_triggered();
    void on_aboutAction_triggered();
    void on_regAction_triggered();
    void on_amendAction_triggered();
    void on_currrentUserAction_triggered();
};

#endif // MAINWINDOW_H

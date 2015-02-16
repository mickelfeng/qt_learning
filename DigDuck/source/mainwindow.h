#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTextCodec>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QGridLayout>
#include <QStandardItemModel>
#include <QtNetwork>
#include "portscan.h"  //端口扫描类
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValueIterator>


#include <QRegExp>
class QHostInfo;
class QNetworkAccessManager;
class QNetworkReply;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QStringList returnIpInfo();
    QStringList hostInfo();
    void getInterfaceInfo();

protected:
signals:

private slots:

    void on_action_portScan_triggered();


    void on_action_about_triggered();

    void on_pushButton_portBegin_clicked();

    void on_pushButton_portEnd_clicked();
    //端口扫描槽函数
    void tooMuchSlot();
    void notConformSlot();
    void addressPortSlot(QStringList);
    void portOpenSlot(QStringList);
    void isipSlot();
    void usedTime();
    void portScanEnd();
    //主机地址
    void on_action_host_triggered();
    void on_pushButton_interface_clicked();
    void slotReadyRead();
    void slotReadyRead_2 ();




    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    portScan *portscan;
    QLabel *la;
    QTimer *timer;
    int usedtime;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QNetworkAccessManager *manager2;
    QNetworkReply *reply2;



};






#endif // MAINWINDOW_H

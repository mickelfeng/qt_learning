#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QMessageBox>
#include <QCryptographicHash>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

private slots:
    void setPort(int port);
    void startTcpServer();
    void closeTcpServer();
    void newConnect();
    void readMessages();

private:
    void initConnect();
    void sendMessages(QString msg);
    QString GetLocalIPAddress();
    bool verify(QString msg);
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVariant>
#include <QDebug>
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
    QTcpSocket *tcpSocket;
    //md5加密，防止数据包在传输过程中被别人捕获。
    QCryptographicHash *md5;

private slots:
    void connectServer();
    void readMessages();
    void clearMSG();

private:
       void sendMessages();
       void LocalVerify();
};

#endif // MAINWINDOW_H

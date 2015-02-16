#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->lineEdit_Username->setFocus();
    this->setTabOrder(this->ui->lineEdit_Username,this->ui->lineEdit_Passwd);
    this->setTabOrder(this->ui->pushButton_Login,this->ui->pushButton_Clear);
    this->md5 = new QCryptographicHash(QCryptographicHash::Md5);
    connect(this->ui->pushButton_Login,SIGNAL(clicked()),this,SLOT(connectServer()));
    connect(this->ui->pushButton_Clear,SIGNAL(clicked()),this,SLOT(clearMSG()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::connectServer 连接远程服务器
 */
void MainWindow::connectServer()
{
    this->tcpSocket = new QTcpSocket(this);
    this->tcpSocket->abort();
    this->tcpSocket->connectToHost(QHostAddress::LocalHost,8888);
    connect(this->tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessages()));
    this->LocalVerify();
}

/**
 * @brief MainWindow::LocalVerify 本地验证
 */
void MainWindow::LocalVerify()
{
    QString tmp;
    foreach (tmp,this->ui->lineEdit_Passwd->text()) {
        if(tmp=="")
        {
            QMessageBox::information(NULL, "信息提示", "账号密码不能为空",
                                     QMessageBox::Yes,
                                     QMessageBox::Yes);
            this->clearMSG();
            return;
        }
    }
    if(this->ui->lineEdit_Username->text() == "")
    {
        QMessageBox::information(NULL, "信息提示", "账号密码不能为空",
                                 QMessageBox::Yes,
                                 QMessageBox::Yes);
        this->clearMSG();
        return;
    }
    else
        this->sendMessages();
}

/**
 * @brief MainWindow::clearMSG 清除登录信息
 */
void MainWindow::clearMSG()
{
    this->ui->lineEdit_Username->setText("");
    this->ui->lineEdit_Passwd->setText("");
}

/**
 * @brief MainWindow::sendMessages 向服务器段发送数据包进行认证操作
 */
void MainWindow::sendMessages()
{
    QString msg = this->ui->lineEdit_Username->text() + "#" + this->ui->lineEdit_Passwd->text();
    //对登录邮箱和登录密码进行md5加密
    md5->reset();
    md5->addData(msg.toUtf8());
    msg = "";
    msg.append(md5->result().toHex());

    //像服务器段发送数据
    this->tcpSocket->write(msg.toStdString().c_str(),
                           strlen(msg.toStdString().c_str()));
}

/**
 * @brief MainWindow::readMessages 获取远程服务器段的回复信息，判断是否验证成功。
 */
void MainWindow::readMessages()
{
    QByteArray qba = this->tcpSocket->readAll();
    QString msg = QVariant(qba).toString();
    //this->setWindowTitle(QVariant(qba).toString());

    if(msg == "true") {
        QMessageBox::information(NULL, "信息提示", "您已经成功登录.",
                                 QMessageBox::Yes | QMessageBox::No,
                                 QMessageBox::Yes);
    } else {
        QMessageBox::information(NULL, "信息提示",
                                 "登录失败！您的登录邮箱或者密码不正确.",
                                 QMessageBox::Yes | QMessageBox::No,
                                 QMessageBox::Yes);
        this->clearMSG();
    }
}

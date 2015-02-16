#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->tcpServer = NULL;
    this->tcpSocket = NULL;
    this->ui->label_IP->setText(this->GetLocalIPAddress());
    this->initConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
    if(this->tcpSocket != NULL) {
        this->tcpSocket->close();
        delete this->tcpSocket;
    }
    if(this->tcpServer != NULL) {
        this->tcpServer->close();
        delete this->tcpServer;
    }
}

/**
 * @brief MainWindow::initConnect
 * @caption 初始化QObject::connect()函数
 */
void MainWindow::initConnect()
{
    connect(this->ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(setPort(int)));
    connect(this->ui->pushButton_Start,SIGNAL(clicked()),this,SLOT(startTcpServer()));
    connect(this->ui->pushButton_Close,SIGNAL(clicked()),this,SLOT(closeTcpServer()));
}

/**
 * @brief MainWindow::setPort
 * @param port 端口号
 */
void MainWindow::setPort(int port)
{
    this->ui->label_Port->setText(QString::number(port));
}

/**
 * @brief MainWindow::startTcpServer 开启服务器
 */
void MainWindow::startTcpServer()
{
    this->tcpServer = new QTcpServer(this);
    this->tcpServer->listen(QHostAddress::Any,this->ui->spinBox->value());
    connect(this->tcpServer,SIGNAL(newConnection()),this,SLOT(newConnect()));
    this->ui->label_SS->setText("Running...");
}

/**
 * @brief MainWindow::closeTcpServer 关闭服务器
 */
void MainWindow::closeTcpServer()
{
    if(this->tcpSocket != NULL) {
        this->tcpSocket->close();
    }
    if(this->tcpServer != NULL) {
        this->tcpServer->close();
    }

    this->ui->label_SS->setText("Stop.");
}

/**
 * @brief MainWindow::newConnect 新的Socket连接
 */
void MainWindow::newConnect()
{
    this->tcpSocket = this->tcpServer->nextPendingConnection();
    connect(this->tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessages()));
}

/**
 * @brief MainWindow::verify 执行登录验证的操作
 * @param msg 欲验证的加密报文
 * @return 验证成功，返回true；否则，返回false。
 */
bool MainWindow::verify(QString msg)
{
    //数据库连接
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mytest.db");
    if(!db.open()){
        QMessageBox::information(this, "信息提示", "数据库连接失败.",
                                 QMessageBox::Yes | QMessageBox::No,
                                 QMessageBox::Yes);
        db.close();
        exit(EXIT_FAILURE);
    }
    QSqlQuery query;//获取数据库信息
    query.exec("select * from account");

    //服务器端的数据同样采取加密操作，比较的是加密后的密文是否相同
    QCryptographicHash md5(QCryptographicHash::Md5);
    //遍历数据库信息，查询判断是否有该用户
    while(query.next()) {
        QString tmp = query.value(0).toString() + "#" + query.value(1).toString();
        md5.addData(tmp.toUtf8());
        tmp = "";
        tmp.append(md5.result().toHex());
        if(tmp == msg) {
            return true;
        }
    }
    db.close();
    return false;
}

/**
 * @brief MainWindow::readMessages 读取发送来的数据
 */
void MainWindow::readMessages()
{
    QByteArray qba = this->tcpSocket->readAll();
    QString msg = QVariant(qba).toString();
    //this->setWindowTitle(msg);
    if(this->verify(msg)) {
        msg = "true";
    } else {
        msg = "false";
    }
    this->sendMessages(msg);
}

/**
 * @brief MainWindow::sendMessages 发送回复消息，以说明登录验证是否成功。
 *      如果回复"true"，表示验证成功；否则，回复为"false",表示验证失败。
 */
void MainWindow::sendMessages(QString msg)
{
    this->tcpSocket->write(msg.toStdString().c_str(),
                           strlen(msg.toStdString().c_str()));
}

/**
 * @brief QT获取本机IP地址
 */
QString MainWindow::GetLocalIPAddress()
{
    QString vAddress;
#ifdef _WIN32
    QHostInfo vHostInfo = QHostInfo::fromName(QHostInfo::localHostName());
    QList<QHostAddress> vAddressList = vHostInfo.addresses();
#else
    QList<QHostAddress> vAddressList = QNetworkInterface::allAddresses();
#endif
    for(int i = 0; i < vAddressList.size(); i++) {
        if(!vAddressList.at(i).isNull() &&
                vAddressList.at(i) != QHostAddress::LocalHost &&
                vAddressList.at(i).protocol() ==  QAbstractSocket::IPv4Protocol)
        {
            vAddress = vAddressList.at(i).toString();
            break;
        }
    }

    return vAddress;
}






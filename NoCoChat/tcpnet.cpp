#include "tcpnet.h"

TcpNet::TcpNet()
{
    tcpClient=new QTcpSocket();
    eventloop=new QEventLoop();
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(readMessage()));
}
/**
 * @brief TCP连接
 * @param ip 服务器ip地址
 * @param port 服务器端口
 * @return true or false
 */
bool TcpNet::tcpconnect(QString ip, int port)
{
    QHostAddress address;
    address.setAddress(ip);
    tcpClient->connectToHost(address,port);
    qDebug()<<ip<<port;
    return tcpClient->waitForConnected(5000);
}
/**
 * @brief 发送数据
 */
void TcpNet::send(QString common)
{
   command(common);
   this->tcpClient->write(this->send_info);
}
/**
 * @brief 接受数据
 * @return 接收到的数据
 */
QString TcpNet::read()
{

  //将定时器超时信号与槽(功能函数)联系起来
  QTimer::singleShot(2000, eventloop, SLOT(quit()));
  eventloop->exec();
  return read_info;
}
/**
 * @brief 读取数据
 */
void TcpNet::readMessage()
{
    this->read_info=this->tcpClient->readAll();
    this->tcpClient->close();
    eventloop->exit();
}

/**
 * @brief 把接受到的命令转为字节
 * @param 命令
 */
void TcpNet::command(QString common)
{
    this->send_info=common.toAscii();
}

/**
 * @brief 关闭连接
 */
void TcpNet::close()
{
    tcpClient->close();
}
/**
 * @brief 获取本地ip地址
 * @return 返回ip地址
 */
QString TcpNet::getLocalAddress()
{
//     通过本机名获取本机网络信息
     QHostInfo info = QHostInfo::fromName(QHostInfo::localHostName());
//     通过遍历info对象找地与address对象相关的对象
     foreach(QHostAddress address,info.addresses())
     {
//         当遍历查找到ipv4的ip地址时返回该本地ip地址
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
        {
                return address.toString();
        }
     }
     return "notAddress";
}

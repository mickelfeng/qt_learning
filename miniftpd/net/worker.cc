#include <net/worker.h>
#include <ftpcmd.h>
#include <boost/bind.hpp>
#include <net/buffer.h>
#include <net/tcpconnection.h>

using namespace miniftp;

namespace Conn
{

static void messageCallback(const TcpConnectionPtr &conn, Buffer *buf)
{
 //   printf("OnMessage() : received %zd bytes from connection [ %s ]\n" , buf->readableBytes(), conn->name().c_str());

    std::string message = buf->retrieveAsString();

  //  printf("Message is [ %s ]\n", message.c_str()); 

    std::string cmd = trim(message);
    //空字符串将会退出
    if(cmd == "")   return; 
    if(cmd.find('\r') != std::string::npos) {
        cmd = cmd.erase(cmd.find('\r'));
    }
    FtpCmd::ExecCmd(cmd, conn);
}

static void onConnection(const TcpConnectionPtr &conn)
{
    if(conn->connected()) {
    //    printf("onConnected() : new connection [ %s ] from %s\n",  conn->name().c_str(), conn->peerAddress().toHostPort().c_str());
        FtpCmd::SendMsg("220", "Welcome to MiniFtp World !!!\r\n", conn);
    }  
}

}

Worker::Worker(EventLoop *loop, int fd, const InetAddress& peerAddr)
    :   m_loop(loop)
{
    m_conn.reset(new TcpConnection(loop, peerAddr.toHostPort(), fd, peerAddr));
    /* 达到本步骤时，连接已经建立，直接调用函数应答 */
    m_conn->setMessageCallback(Conn::messageCallback);
    m_conn->setConnectionCallback(Conn::onConnection);
    m_conn->connectEstablished();
}



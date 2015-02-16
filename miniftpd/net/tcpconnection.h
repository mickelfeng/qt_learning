#ifndef _TCPCONNECTION_H_
#define _TCPCONNECTION_H_

#include <net/buffer.h>
#include <net/inetaddress.h>
#include <lib/event.h>
#include <lib/eventloop.h>
#include <net/socket.h>
#include <net/callbacks.h>
#include <userinfo.h>

#include <boost/any.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>

namespace miniftp
{

class TcpConnection :   boost::noncopyable, public boost::enable_shared_from_this<TcpConnection>
{
public:
    TcpConnection(EventLoop *loop,
            const std::string &name,
            int sockfd,
            const InetAddress& peerAddr);
    ~TcpConnection();

    EventLoop *getLoop() const 
    {
        return m_loop;
    }

    const std::string & name() const 
    {
        return m_name;
    }

    const InetAddress& peerAddress() const 
    {
        return m_peerAddr;
    }

    bool connected() const 
    {
        return m_state == kConnected;
    }

    void send(const std::string& message);

    void shutdown();

    void setTcpNoDelay(bool on);

    void setConnectionCallback(const ConnectionCallback& cb)
    {
        m_connectionCallback = cb;
    }

    void setMessageCallback(const MessageCallback &cb)
    {
        m_messageCallback = cb;
    }

    void setWriteCompleteCallback(const WriteCompleteCallback& cb)
    {
        m_writeCompleteCallback = cb;
    }

    void setCloseCallback(const CloseCallback &cb)
    {
        m_closeCallback = cb;
    }

    void connectEstablished();

    void connectDestroyed();

    UserInfo &getUserInfo()
    {
        return m_userinfo;
    }

    boost::shared_ptr<Socket> getSocket() const
    {
        return m_socket;
    }

private:
    enum StateE { kConnecting, kConnected, kDisconnected, kDisconnecting};

    void setState(StateE s)
    {
        m_state = s;
    }

    void handleRead();
    void handleWrite();
    void handleClose();
    void handleError();

    void sendInLoop(const std::string & message);
    void shutdownInLoop();

    EventLoop *     m_loop;
    std::string     m_name;
    StateE          m_state;

    boost::shared_ptr<Socket>   m_socket;
    boost::scoped_ptr<Event>    m_event;
    InetAddress                 m_peerAddr;
    ConnectionCallback          m_connectionCallback;
    MessageCallback             m_messageCallback;
    WriteCompleteCallback       m_writeCompleteCallback;
    CloseCallback               m_closeCallback;

    Buffer                      m_inputBuffer;
    Buffer                      m_outputBuffer;

    //  本段属于FTP服务器新增内容，包含了一条连接拥有的用户信息，他将会保存到用户结构体之中
    UserInfo                    m_userinfo;
};

}

#endif

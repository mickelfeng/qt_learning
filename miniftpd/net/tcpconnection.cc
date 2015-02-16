#include <net/tcpconnection.h>
#include <net/socket.h>
#include <net/socketsops.h>
#include <net/inetaddress.h>
#include <lib/event.h>
#include <lib/eventloop.h>
#include <utils.h>

#include <boost/bind.hpp>
#include <boost/implicit_cast.hpp>

#include <errno.h>
#include <stdio.h>
#include <string>

using namespace miniftp;

TcpConnection::TcpConnection(EventLoop *loop,
        const std::string& nameArg,
        int sockfd,
        const InetAddress& peerAddr)
    :   m_loop(loop),
        m_name(nameArg),
        m_state(kConnecting),
        m_socket(new Socket(sockfd)),
        m_event(new Event(sockfd)),
        m_peerAddr(peerAddr)
{
   // fprintf(stdout, "TcpConnection::ctor[ %s ] at %x, fd = %d\n", m_name.c_str(), this, sockfd);
    m_event->setReadCB(boost::bind(&TcpConnection::handleRead, this));
    m_event->setWriteCB(boost::bind(&TcpConnection::handleWrite, this));
    m_event->setCloseCB(boost::bind(&TcpConnection::handleClose, this));
    m_event->setErrorCB(boost::bind(&TcpConnection::handleError, this));
   
    m_event->setEventType(ENABLEREAD);
    m_loop->updateEvent(get_pointer(m_event));
}

TcpConnection::~TcpConnection()
{
   // fprintf(stdout, "TcpConnection::ctor[ %s ] at %x QUIT, fd = %d\n", m_name.c_str(), this, m_event->fd());
}

void TcpConnection::send(const std::string & message) 
{
    if(m_state == kConnected) {
        sendInLoop(message);
    }
}

void TcpConnection::sendInLoop(const std::string & message)
{
    ssize_t nwrote = 0;
    if(! m_event->isWriting() && m_outputBuffer.readableBytes() == 0) {
        nwrote = ::write(m_event->fd(), message.data(), message.size());
        if(nwrote >= 0) {
            if(boost::implicit_cast<size_t>(nwrote) < message.size()) {
                INFO("I Am going to Write more Data");
            } else if ( m_writeCompleteCallback) {
                m_loop->runInLoop(boost::bind(m_writeCompleteCallback, shared_from_this()));
            }
        } else {
            nwrote = 0;
            if( errno != EWOULDBLOCK ) {
                INFO("TcpConnection::SendInLoop Error!!!");
            }
        }
    }

    assert(nwrote >= 0);
    if(boost::implicit_cast<size_t>(nwrote) < message.size()) {
        m_outputBuffer.append(message.data() + nwrote, message.size() - nwrote);
        if( ! m_event->isWriting()) {
            m_event->setEventType(ENABLEWRITE);
            m_loop->updateEvent(get_pointer(m_event));
        }
    }
}

void TcpConnection::setTcpNoDelay(bool on)
{
    m_socket->setTcpNoDelay(on);
}

void TcpConnection::shutdown()
{
    if(m_state == kConnected) {
        setState(kDisconnecting);
        m_loop->runInLoop(boost::bind(&TcpConnection::shutdownInLoop, this));
    }
}

void TcpConnection::shutdownInLoop()
{
    if(! m_event->isWriting()) {
        m_socket->shutdownWrite();
    }
}

void TcpConnection::connectEstablished()
{
    assert(m_state == kConnecting);
    setState(kConnected);
    m_connectionCallback(shared_from_this());
}

void TcpConnection::connectDestroyed()
{
    assert(m_state == kConnected || m_state == kDisconnecting);

    setState(kDisconnected);
    m_event->setEventType(DISABLEALL);
    //m_connectionCallback(shared_from_this());
    m_loop->removeEvent(get_pointer(m_event));

    //属于本条连接的时间循环退出
    m_loop->quit();
}

void TcpConnection::handleRead()
{
    int savedErrno = 0;
    ssize_t n = m_inputBuffer.readFd(m_event->fd(), &savedErrno);
    if( n > 0 ) {
        m_messageCallback(shared_from_this(), &m_inputBuffer);
    } else if ( n == 0 ) {
        handleClose();
    } else {
        errno = savedErrno;
        INFO("Read Failure !!!");
        handleError();
    }
}

void TcpConnection::handleWrite()
{
    if(m_event->isWriting()) {
        ssize_t n = ::write(m_event->fd(), m_outputBuffer.peek(),
                            m_outputBuffer.readableBytes());
        if( n > 0) {
            m_outputBuffer.retrieve(n);
            if(m_outputBuffer.readableBytes() == 0) {
                m_event->setEventType(DISABLEWRITE);
                m_loop->updateEvent(get_pointer(m_event));
                if(m_writeCompleteCallback) {
                    m_loop->runInLoop(boost::bind(m_writeCompleteCallback, shared_from_this()));
                }

                if(m_state == kDisconnecting) {
                    shutdownInLoop();
                }
            } else {
                INFO(" I am going to write more data !");
            }
        } else {
            INFO("TcpConnection::handlerWrite Error");
        }
    } else {
        INFO("Connection is down, No More Writing");
    }
}

void TcpConnection::handleClose()
{
    assert(m_state == kConnected || m_state == kDisconnecting);

    m_event->setEventType(DISABLEALL);
    m_loop->updateEvent(get_pointer(m_event));
    m_closeCallback(shared_from_this());
}

void TcpConnection::handleError()
{
    int err = sockets::getSocketError(m_event->fd());
    fprintf(stderr, "TcpConnection::handleError [ %s ] - SO_ERROR =%d  %s\n",m_name.c_str(), err, strerror(err));

    //连接出错，直接退出程序
    ::exit(0);
}

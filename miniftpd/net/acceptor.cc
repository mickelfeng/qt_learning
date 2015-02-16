#include <net/acceptor.h>
#include <net/inetaddress.h>
#include <net/socketsops.h>
#include <lib/eventloop.h>
#include <boost/bind.hpp>

using namespace miniftp;

Acceptor::Acceptor(EventLoop *loop, const InetAddress& listenAddr)
    :   m_loop(loop),
        m_acceptSocket(sockets::createNonblockingOrDie()),
        m_acceptEvent(m_acceptSocket.fd()),
        m_listenning(false)
{
    m_acceptSocket.setReuseAddr(true);
    m_acceptSocket.bindAddress(listenAddr);
    m_acceptEvent.setReadCB(
            boost::bind(&Acceptor::handleRead, this));
    m_acceptEvent.setEventType(ENABLEREAD);
    m_loop->updateEvent(&m_acceptEvent);
}

void Acceptor::listen()
{
    m_listenning = true;
    m_acceptSocket.listen();
}

Socket & Acceptor::getSocket()
{
    return m_acceptSocket;
}

void Acceptor::handleRead()
{
    InetAddress peerAddr(0);

    int connfd = m_acceptSocket.accept(&peerAddr);
    if(connfd >= 0) {
        if(m_newConnectionCallback) {
            m_newConnectionCallback(connfd, peerAddr);
        } else {
            sockets::close(connfd);
        }
    }
}

#ifndef _ACCEPTOR_H_
#define _ACCEPTOR_H_

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>

#include <lib/event.h>
#include <net/socket.h>
#include <net/inetaddress.h>
#include <lib/eventloop.h>

namespace miniftp 
{

class Acceptor : boost::noncopyable
{
public:
    typedef boost::function<void (int sockfd, const InetAddress&)> NewConnectionCallback;
    Acceptor(EventLoop *loop, const InetAddress& listenAddr);

    void setNewConnectionCallback(const NewConnectionCallback& cb)
    {
        m_newConnectionCallback = cb;
    }

    bool listenning() const 
    {
        return m_listenning;
    }

    Socket &getSocket();

    void listen();

private:
    void handleRead();

    EventLoop * m_loop;

    Socket      m_acceptSocket;

    Event       m_acceptEvent;

    NewConnectionCallback   m_newConnectionCallback;

    bool        m_listenning;

};

}

#endif

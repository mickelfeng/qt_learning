#ifndef _TCPSERVER_H_
#define _TCPSERVER_H_

#include <net/callbacks.h>
#include <net/tcpconnection.h>
#include <net/acceptor.h>
#include <net/inetaddress.h>
#include <lib/eventloop.h>

#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <net/workerprocess.h>
#include <map>

namespace miniftp
{

class FtpServer : boost::noncopyable
{
public:
    FtpServer(EventLoop *loop, const InetAddress & listenAddr) ;
    ~FtpServer();

    void start();

private:
    void newConnection(int sockfd, const InetAddress& peerAddr);

    EventLoop*          m_loop;
    boost::scoped_ptr<Acceptor> m_acceptor;
    bool                m_started;
};

};

#endif

#ifndef _WORKER_H_
#define _WORKER_H_

#include <boost/noncopyable.hpp>
#include <lib/eventloop.h>
#include <net/inetaddress.h>
#include <net/tcpconnection.h>
#include <net/callbacks.h>

namespace miniftp 
{

class Worker : boost::noncopyable
{
public:
    Worker(EventLoop *loop, int fd, const InetAddress &peerAddr);
    
    ~Worker() {}
private:
    /* 事件循环 */
    EventLoop * m_loop;
    
    TcpConnectionPtr m_conn;
};

}

#endif

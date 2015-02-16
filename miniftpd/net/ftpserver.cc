#include <net/ftpserver.h>

#include <net/socketsops.h>
#include <boost/bind.hpp>
#include <stdio.h>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <log.h>

using namespace miniftp;

FtpServer::FtpServer(EventLoop* loop, const InetAddress & listenAddr)
    :   m_loop (loop),
        m_acceptor(new Acceptor(loop, listenAddr)),
        m_started(false)
{
    m_acceptor->setNewConnectionCallback(
            boost::bind(&FtpServer::newConnection, this, _1, _2));
}

FtpServer::~FtpServer()
{}

void FtpServer::start()
{
    if(! m_started) {
        m_started = true;
    }

    if(! m_acceptor->listenning()) {
        Loger::NewLoger()->write("Ftp Server Start.....");
        m_acceptor->listen();
    }
} 

void FtpServer::newConnection(int sockfd, const InetAddress& peerAddr)
{
    std::string connName = peerAddr.toHostPort();
 //   fprintf(stdout, "TcpServer new connection [ %s ] 111111\n", peerAddr.toHostPort().c_str());
    
    new WorkerProcess(sockfd, peerAddr);
}

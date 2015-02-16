#ifndef _SOCKET_H_
#define _SOCKET_H_

#include <boost/noncopyable.hpp>

#include <net/inetaddress.h>

namespace miniftp
{

class Socket : boost::noncopyable
{
public:
    explicit Socket(int sockfd)
        :   m_sockfd(sockfd)
    {}

    ~Socket();

    int fd() const
    {
        return m_sockfd;
    }

    void bindAddress(const InetAddress& localaddr);

    void listen();

    int accept(InetAddress* peeraddr);

    void setReuseAddr(bool on);

    void shutdownWrite();

    void setTcpNoDelay(bool on);

private:
    const int m_sockfd;
};

};

#endif

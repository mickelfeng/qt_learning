#ifndef _INETADDRES_H_
#define _INETADDRES_H_

#include <boost/noncopyable.hpp>
#include <string>
#include <netinet/in.h>
#include <net/socketsops.h>

namespace miniftp
{

class InetAddress
{
public:
    explicit InetAddress(uint16_t port);

    InetAddress(const std::string& ip, uint16_t port);

    InetAddress(const struct sockaddr_in& addr)
        :   m_addr(addr)
    {}

    std::string toHostPort() const;

    const struct sockaddr_in& getSockAddrInet() const 
    {
        return m_addr;
    }

    void setSockAddrInet(const struct sockaddr_in& addr)
    {
        m_addr = addr;
    }

private:
    struct sockaddr_in m_addr;
};


};

#endif

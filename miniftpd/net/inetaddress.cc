#include <net/inetaddress.h>

#include <strings.h>

using namespace miniftp;

static const in_addr_t kInaddrAny = INADDR_ANY;

InetAddress::InetAddress(uint16_t port)
{
    bzero(&m_addr, sizeof m_addr);
    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = sockets::hostToNetwork16(kInaddrAny);
    m_addr.sin_port = sockets::hostToNetwork16(port);
}

InetAddress::InetAddress(const std::string &ip, uint16_t port)
{
    bzero(&m_addr, sizeof m_addr);
    sockets::fromHostPort(ip.c_str(), port, &m_addr);
}

std::string InetAddress::toHostPort() const 
{
    char buf[32] = {0};
    sockets::toHostPort(buf, sizeof buf, m_addr);
    return std::string(buf);
}

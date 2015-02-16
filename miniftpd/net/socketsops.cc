#include <net/socketsops.h>
#include <utils.h>

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>
#include <ifaddrs.h>

#include <boost/implicit_cast.hpp>

using namespace miniftp;

namespace 
{

typedef struct sockaddr SA;

const SA* sockaddr_cast(const struct sockaddr_in *addr)
{
    return static_cast<const SA*>(boost::implicit_cast<const void*>(addr));
}

SA* sockaddr_cast(struct sockaddr_in *addr)
{
    return static_cast<SA*>(boost::implicit_cast<void *>(addr));
}

void setNonBlockAndCloseOnExec(int sockfd)
{
    // non-block
    int ret = ::fcntl(sockfd, F_SETFL, ::fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK);    

    // close-on-exec
    ret = ::fcntl(sockfd, F_SETFD, ::fcntl(sockfd, F_GETFL, 0) | FD_CLOEXEC);
}
};

int sockets::createNonblockingOrDie()
{
    int sockfd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sockfd < 0) {
        INFO("SOCKFD Create Failure !!!");
    }
    return sockfd;
}

int sockets::connect(int sockfd, const struct sockaddr_in& addr)
{
    return ::connect(sockfd, sockaddr_cast(&addr), sizeof addr);
}

void sockets::bindOrDie(int sockfd, const struct sockaddr_in& addr)
{
    int ret = ::bind(sockfd, sockaddr_cast(&addr), sizeof addr);
    if(ret < 0 ) {
        INFO("Bind Failure !");
    }
}

void sockets::listenOrDie(int sockfd)
{
    int ret = ::listen(sockfd, SOMAXCONN);
    if(ret < 0) {
        INFO("Listen Failure!!");
    }
}

int sockets::accept(int sockfd, struct sockaddr_in *addr)
{
    socklen_t addrlen = sizeof(struct sockaddr_in);
    int connfd = ::accept(sockfd, sockaddr_cast(addr), &addrlen);
    setNonBlockAndCloseOnExec(connfd);

    if(connfd < 0) {
        int savedErrno = errno;
        INFO("Accept Failure!!");
    }

    return connfd;
}

void sockets::close(int sockfd)
{
    if(::close(sockfd) < 0) {
        INFO("Close Failure !");
    }
}

void sockets::toHostPort(char *buf, size_t size, const struct sockaddr_in &addr)
{
    char host[INET_ADDRSTRLEN] = "INVALID";
    ::inet_ntop(AF_INET, &addr.sin_addr, host, sizeof host);
    uint16_t port = sockets::networkToHost16(addr.sin_port);
    snprintf(buf, size, "%s:%u", host, port);
}

void sockets::fromHostPort(const char* ip, uint16_t port, struct sockaddr_in *addr)
{
    addr->sin_family = AF_INET;
    addr->sin_port = hostToNetwork16(port);
    if(::inet_pton(AF_INET, ip, &addr->sin_addr) <= 0) { 
        INFO("Inet_Pton Failure !!!");
    }
}

struct sockaddr_in sockets::getLocalAddr(int sockfd)
{
    struct sockaddr_in localaddr;
    bzero(&localaddr, sizeof localaddr);
    socklen_t addrlen = sizeof localaddr;
    if(::getsockname(sockfd, sockaddr_cast(&localaddr), &addrlen) < 0) {
        INFO("GetLocalAddr Failure !!!");
    }
    
    //2.获取本机地址
    struct ifaddrs *ifaddr;
    in_addr_t ip = -1;

    if(getifaddrs(&ifaddr) < 0) {
        perror("获取地址信息失败");
        return localaddr;
    }
    //查找本地IP地址
    do{
        in_addr_t tp = ((struct sockaddr_in *)ifaddr->ifa_addr)->sin_addr.s_addr;
        //存在一种IP获取为0的可能，排除掉，至少可以获取到回环网卡的地址
        if(tp != 0)     ip = tp;
    }while((ifaddr = ifaddr->ifa_next));
    //查询到没有开启活动的网卡，一般显示为127.0.0.1，返回失败
    if(ip == 0x7F000001){
        perror("没有查询到活动的网卡");
    }
    
    localaddr.sin_addr.s_addr = ip;
    return localaddr;
}

struct sockaddr_in sockets::getPeerAddr(int sockfd)
{
    struct sockaddr_in peeraddr;
    bzero(&peeraddr, sizeof peeraddr);
    socklen_t addrlen = sizeof peeraddr;
    if(::getpeername(sockfd, sockaddr_cast(&peeraddr), &addrlen)) {
        INFO("GetPeerAddr Failure!!!");
    }
    return peeraddr;
}

int sockets::getSocketError(int sockfd)
{
    int optval;
    socklen_t optlen = sizeof optval;

    if(::getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &optval, &optlen) < 0) {
        return errno;
    } else {
        return optval;
    }
}

void sockets::shutdownWrite(int sockfd)
{
    if(::shutdown(sockfd, SHUT_WR) < 0) {
        INFO("ShutDownWrite Failure!!!") ;
    }
}

bool sockets::isSelfConnect(int sockfd)
{
    struct sockaddr_in localaddr = getLocalAddr(sockfd);
    struct sockaddr_in peeraddr = getPeerAddr(sockfd);
    return localaddr.sin_port == peeraddr.sin_port &&
        localaddr.sin_addr.s_addr == peeraddr.sin_addr.s_addr;
}


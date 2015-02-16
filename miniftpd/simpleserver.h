#ifndef _SIMPLESERVER_H_
#define _SIMPLESERVER_H_

#include <errno.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <net/if_arp.h>
#include <net/if.h>
#include <readconfig.h>

namespace miniftp
{

namespace SimpleServer 
{

int BuildSimpleServer(unsigned short sin_port)
{
    //1. 创建套节字
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd == -1) {
        fprintf(stderr, "Open Socket error !\n");
        return -1;
    }
    //2. 设置套节字为普通类型套节字
    int opt = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const char*)&opt, sizeof(opt));
    
    //3. 初始化套节字地址
    struct sockaddr_in servAddr;
    bzero(&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(sin_port);

    //4. 绑定
    int res = bind(listenfd, (struct sockaddr*)&servAddr, sizeof(servAddr));
    if(res == -1) {
        fprintf(stderr, "Bind Ip and Port Error!\n");
        return -1;
    }

    //5. 监听
    if(listen(listenfd, 10) == -1) {
        fprintf(stderr, "Listen fail!\n");
        return -1;
    }

    return listenfd;
}

int BuildSimpleClient(char *ip, unsigned short sin_port)
{
    //1.创建套接字
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        fprintf(stderr, "Open Socket Error!\n");
        return -1;
    }

    //2.设置套接字为普通类型套接字
    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char*)&opt, sizeof(opt));

    //3.被动连接, 将当地的端口号绑定到20
    struct sockaddr_in currAddr;
    bzero(&currAddr, sizeof(currAddr));
    currAddr.sin_family = AF_INET;
    std::string value;
    Config::NewConfig()->Read("ActivePort", value);
    currAddr.sin_port = htons((unsigned short)atoi(value.c_str()));
    currAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int eUID = geteuid();
    int eGID = getegid();
    seteuid(0);
    setegid(0);
    bind(sockfd, (struct sockaddr*)&currAddr, sizeof(currAddr));
    seteuid(eUID);
    setegid(eGID);

    //4.初始化套接字地址
    struct sockaddr_in servAddr;
    bzero(&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    if(inet_aton(ip, &servAddr.sin_addr) == 0) {
        fprintf(stderr, "Connect Server's address not valid!\n");
        return -1;
    }
    servAddr.sin_port = htons(sin_port);

    //5.开始链接服务器
    int res = connect(sockfd, (struct sockaddr*)&servAddr, sizeof(servAddr));
    if(res == -1) {
        switch(errno) {
            case EBADF: //传递过来的socket参数的文件描述符无效
                fprintf(stderr, "Error, Socket params is not valid.\n");
                break;
            case EALREADY://该套接字上已经有一个正在运行的连接
                fprintf(stderr, "Error, Currectly have a socket connecting already!\n");
                break;
            case ETIMEDOUT://连接超时
                fprintf(stderr, "Error, Connected Timeout!\n");
                break;
            case ECONNREFUSED://连接被服务器拒绝
                fprintf(stderr, "Refused to connect to server!\n");
                break;
            default:
                fprintf(stderr, "Connected server failed!\n");
                break;
        }
        return -1;
    }
    return sockfd;
}

}

}

#endif

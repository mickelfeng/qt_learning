#ifndef _FTPCMD_H_
#define _FTPCMD_H_

#include <netinet/in.h>
#include <boost/noncopyable.hpp>
#include <string>
#include <net/tcpconnection.h>
#include <log.h>

namespace miniftp
{

#define CHECK_LOGIN     1   //检查登录
#define CHECK_NOLOGIN   2   //不检查登录
#define NEED_PARAM      4   //需要参数
#define NO_PARAM        8   //不需要参数
#define NO_CHECK        16  //不检查

typedef enum {NONE, PASV, PORT} ConnType;
typedef int (*CmdFunc) (std::string param, const TcpConnectionPtr &conn);

/* FTP 命令结构体定义 */
typedef struct {
    std::string      cmd;
    CmdFunc     cmd_handler;
    char        check;
} FTPCMD;

extern FTPCMD cmd_list[];

namespace FtpCmd {

void SendMsg(std::string ID, std::string msg, const TcpConnectionPtr &conn);

int ExecCmd(std::string cmd_param, const TcpConnectionPtr& conn);

std::string GetHomePath();

int SendCurrentDir(int transfd, bool, std::string &);

int SendShortDir(int transfd, std::string & );

int GetFile(int fd_in, int fd_out);

void GetAddress(std::string address, char ip[], unsigned short &port);

unsigned long long SendFile(int fd_in, int fd_out, unsigned long long offset);

}	// Endof namespace FtpCmd

}	// Endof namespace miniftp
#endif


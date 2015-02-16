#include <ftpcmd.h>
#include <log.h>
#include <shadow.h>
#include <readconfig.h>
#include <sys/types.h>
#include <pwd.h>
#include <crypt.h>

#include <sys/stat.h>
#include <dirent.h>
#include <sys/time.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>

#include <simpleserver.h>

#include <boost/algorithm/string.hpp>

namespace miniftp {

int Read_TimeOut(int fd, int sec) 
{
    fd_set rset;
    struct timeval tv;
    FD_ZERO(&rset);
    FD_SET(fd,&rset);
    tv.tv_sec=sec;
    tv.tv_usec=0;
    return(select(fd+1,&rset,NULL,NULL,&tv));
}

/* 创建连接 */
int BuildConnect(const TcpConnectionPtr &conn)
{
    UserInfo &userinfo = conn->getUserInfo();
    if(userinfo.getConnType() == UserInfo::PASV) {
        if(Read_TimeOut(userinfo.getListenfd(), 120) == 0) {
            exit(0);
        }
        int transfd = accept(userinfo.getListenfd(), NULL, NULL);
        close(userinfo.getListenfd());
        userinfo.setListenfd(-1);
        
        return transfd;
    } else if(userinfo.getConnType() == UserInfo::PORT) {
        char ip[24] = {0};
        unsigned short port;
        FtpCmd::GetAddress(userinfo.getPortAddr(), ip, port);
        int transfd = SimpleServer::BuildSimpleClient(ip, port);
        return transfd;
    }
}

int do_user(std::string username, const TcpConnectionPtr &conn)
{
    if(username == "anonymous")   username = "ftp";
    conn->getUserInfo().setUsername(username);
    FtpCmd::SendMsg("331"," User name okay, need password.\r\n", conn);

    return 1;
}

int do_pass(std::string param, const TcpConnectionPtr &conn)
{
    struct passwd *passwdInfo;
    //已经连接上的用户信息
    UserInfo &userinfo = conn->getUserInfo();

    std::string AllowAmous = "";
    Config::NewConfig()->Read("AllowAnonymous", AllowAmous);
    /* 如果不允许匿名登陆，或者当前用户不是ftp或者anonymous用户，则需要验证密码，验证失败直接返回   */
    if(AllowAmous != "yes" || ((userinfo.getUsername() != "ftp") && (userinfo.getUsername() != "anonymous"))) {
        //切换到终极权限
        seteuid(0);
        setegid(0);
        struct spwd *spwd = getspnam(userinfo.getUsername().c_str());
        if(spwd) {
            //获取密码前缀
            char salt[50] = {0};
            strncpy(salt, spwd->sp_pwdp, 19);
            //获取密文
            char *passwd = (char *)crypt(param.c_str(), salt);
            //比较密文时候正确
            if(strcmp(passwd, spwd->sp_pwdp) != 0) {
                userinfo.setUsername("");
                FtpCmd::SendMsg("530", "Not Logged In.\r\n", conn);
                exit(0);
                return 0;
            }
        } else {
            userinfo.setUsername("");
            FtpCmd::SendMsg("530", "Not Logged In.\r\n", conn);
            return 0;
        }
    }

    //初始化登陆的用户信息
    userinfo.setIsLogined(true);
    userinfo.setCurrWorkdir(FtpCmd::GetHomePath());
    
    passwdInfo = getpwnam(userinfo.getUsername().c_str());
    setegid(passwdInfo->pw_gid);
    seteuid(passwdInfo->pw_uid);

    FtpCmd::SendMsg("230", "User Logged in, proceed.\r\n", conn);

    //写登陆日志
    std::string loginfo = userinfo.getUsername() + "  Login In.";
    Loger::NewLoger()->write(loginfo);
}

/* 更改当前工作目录 */
int do_cwd(std::string param, const TcpConnectionPtr &conn)
{
    UserInfo &userinfo = conn->getUserInfo();
    std::string workdir = userinfo.getCurrWorkdir();
    //切换目录
    if(param.c_str()[0] == '/') {
        while(param.c_str()[1] == '.' && param.c_str()[2] == '.') {
            param = param.substr(3);
        }
        workdir = FtpCmd::GetHomePath() + param;
    } else {
        workdir += "/" +  param;
    }
    
    //作一次超出根目录的检测
    int res = chdir(workdir.c_str());
    if(res == -1) {
        FtpCmd::SendMsg("550","Failed to change directory.\r\n", conn);
        return -1;
    }
    char buf[1024] ={0};
    getcwd(buf, 1024);
    if(std::string(buf).find(FtpCmd::GetHomePath()) == std::string::npos) {
        //超出根目录
        workdir = FtpCmd::GetHomePath();
        int res = chdir(workdir.c_str());
        if(res == -1) {
            FtpCmd::SendMsg("550","Failed to change directory.\r\n", conn);
            return 0;
        } 
    }
    userinfo.setCurrWorkdir(workdir);

    FtpCmd::SendMsg("250","Directory successfully changed.\r\n", conn);
    return 1;
}

/* 将当前目录向上一级 */
int do_cdup(std::string param, const TcpConnectionPtr &conn)
{
    UserInfo &userinfo = conn->getUserInfo();
    std::string workdir = userinfo.getCurrWorkdir();
    if(workdir == FtpCmd::GetHomePath()) {
        return 0;
    }
    workdir += "/..";
    
    int res = chdir(workdir.c_str());
    if(res == -1) {
        FtpCmd::SendMsg("550"," Failed to change directory.\r\n", conn);
        return 0;
    }

    //这是当前工作目录
    char dir[1024];
    getcwd(dir, 1024);
    userinfo.setCurrWorkdir(dir);

    FtpCmd::SendMsg("250","Directory successfully changed.\r\n", conn);
}

/* 获取系统类型 */
int do_syst(std::string param, const TcpConnectionPtr &conn)
{
    FtpCmd::SendMsg("215","UNIX Type: L8\r\n", conn);
    return 1;
}

/* 或读取当前工作目录 */
int do_pwd(std::string param, const TcpConnectionPtr &conn)
{
    FtpCmd::SendMsg("257", ("\"" + conn->getUserInfo().getCurrWorkdir().substr(FtpCmd::GetHomePath().size()) + "/\"\r\n").c_str(), conn);
    return 1;
}

/* 获取文件类型 */
int do_type(std::string param, const TcpConnectionPtr &conn)
{
    FtpCmd::SendMsg("200","Type set to A\r\n", conn);
    return 1;
}

/* 文件列表明细 */
int do_list(std::string param, const TcpConnectionPtr &conn)
{
    UserInfo &userinfo = conn->getUserInfo();
    if(userinfo.getConnType() == UserInfo::NONE) {
        FtpCmd::SendMsg("425", "Use PORT or PASV first.\r\n", conn);
        return 0;
    }

    FtpCmd::SendMsg("150","Here comes the directory listing.\r\n", conn);
    int transfd = BuildConnect(conn);

    bool hide = true;
    if(param == "-a" || param == "-aL") 
        hide = false;
    FtpCmd::SendCurrentDir(transfd, hide, userinfo.getCurrWorkdir());

    close(transfd);
    FtpCmd::SendMsg("226","Directory send OK.\r\n", conn);
    userinfo.setConnType(UserInfo::NONE);
}

/* 删除目录 */
int do_rmd(std::string param, const TcpConnectionPtr &conn)
{
    std::string dirname = trim(param);
    if(dirname.c_str()[0] == '/') {
        dirname = FtpCmd::GetHomePath() + dirname;
    } else {
        dirname = conn->getUserInfo().getCurrWorkdir() + "/" + dirname;
    }
    
    int res = ::rmdir(dirname.c_str());
    if(res < 0) {
        switch(errno) {
            case EACCES:
                FtpCmd::SendMsg("550", "Remove Directory Operation Failure, Access Denied.\r\n", conn);
                break;
            case EBUSY:
                FtpCmd::SendMsg("550", "Remove Directory Operation Failure, Directory Busy.\r\n", conn);
                break;
            case ENOTEMPTY:
                FtpCmd::SendMsg("550", "Remove Directory Operation Failure, Directory Not Empty.\r\n", conn);
                break;
            default:
                FtpCmd::SendMsg("550", "Remove Directory Operation Failure.\r\n", conn);
                break;
        }
    } else {
        FtpCmd::SendMsg("250", "Remove Directory Operation Successed.\r\n", conn);
    }

    return 0;
}

/* 获取文件短列表 */
int do_nlist(std::string param, const TcpConnectionPtr &conn)
{
    UserInfo &userinfo = conn->getUserInfo();
    FtpCmd::SendMsg("150","Here comes the directory listing.\r\n", conn);
    int transfd = BuildConnect(conn);
    FtpCmd::SendShortDir(transfd, userinfo.getCurrWorkdir());
    ::close(transfd);
    FtpCmd::SendMsg("226","Directory send OK.\r\n", conn);
    return 1;
}

/* 新建目录 */
int do_mkd(std::string param, const TcpConnectionPtr &conn)
{
    std::string dirname = trim(param);
    if(dirname.c_str()[0] == '/') {
        dirname = FtpCmd::GetHomePath() + dirname;
    } else {
        dirname = conn->getUserInfo().getCurrWorkdir() + "/" + dirname;
    }

    int res = ::mkdir(dirname.c_str(), 0755);
    if(res < 0) {
        FtpCmd::SendMsg("550", "Create Dir Failed.\r\n", conn);
    } else {
        FtpCmd::SendMsg("257", "\"" + dirname.substr(FtpCmd::GetHomePath().size()) + "\" Created Success.\r\n", conn); 
    }
    return 1;
}

/* 删除目录链接 */
int do_del(std::string param, const TcpConnectionPtr &conn)
{
    std::string dirname = trim(param);
    if(dirname.c_str()[0] == '/') {
            dirname = FtpCmd::GetHomePath() + dirname;
    } else {
            dirname = conn->getUserInfo().getCurrWorkdir() + "/" + dirname;
    }

    int res = ::unlink(dirname.c_str());
    if(res < 0) {
        switch(errno) {
            case EACCES:
                FtpCmd::SendMsg("550", "Delete Failure. Access Denied.\r\n", conn);
                break;
            case EBUSY:
                FtpCmd::SendMsg("550", "Delete Failure, This file is Busy.\r\n", conn);
                break;
            case EISDIR:
                FtpCmd::SendMsg("550", "Delete Failure, Is a Directory.\r\n", conn);
                break;
            default:
                FtpCmd::SendMsg("550", "Delete Failure.\r\n", conn);
                break;
        }
    } else {
        FtpCmd::SendMsg("250", "Delete Success.\r\n", conn);
    }

    return 1;
}

/* 重新初始化 */
int do_reinit(std::string param, const TcpConnectionPtr &conn)
{
    UserInfo &userinfo = conn->getUserInfo();
    userinfo.setIsLogined(false);
    userinfo.setUsername("");
    userinfo.setRset(0);
    userinfo.setConnType(UserInfo::NONE);
    userinfo.setCurrWorkdir("");
    userinfo.setOldPath("");
    userinfo.setListenfd(-1);
    userinfo.setFilename("");

    FtpCmd::SendMsg("220", "Service ready for new user.\r\n", conn);
}

/* 获取帮助 */
int do_help(std::string param, const TcpConnectionPtr &conn)
{
    int i=0;
    int columnCount=8;
    char msg[2048]={0};         
    strcpy(msg,"214-The following commands are recognized (* => unimplemented).\n");
    while(cmd_list[i].cmd != "")
    {
        strcat(msg,cmd_list[i++].cmd.c_str());
        if (i%columnCount==0)
        {
            strcat(msg,"\n");
        } else { 
            strcat(msg,"   ");
        }
    }
    strcat(msg,"\n214 Please Direct comments to My Email liuyun01@kylinos.com.cn\r\n");
    FtpCmd::SendMsg(msg,"", conn);
    return 0;
}

/* 退出 */
int do_quit(std::string param, const TcpConnectionPtr &conn)
{
    conn->getUserInfo().setIsLogined(false);

    std::string loginfo = conn->getUserInfo().getUsername() + " Logout in.";
    Loger::NewLoger()->write(loginfo);

    //连接断开回调函数
    conn->connectDestroyed();
    exit(0);
    return 0;
}

/* 重新开始位置 */
int do_reset(std::string param, const TcpConnectionPtr &conn)
{
    conn->getUserInfo().setRset(atol(param.c_str()));
    FtpCmd::SendMsg("350", "REST success. \r\n", conn);
    
    return 0;
}

/* 被动连接 */
int do_pasv(std::string param, const TcpConnectionPtr &conn)
{
    conn->getUserInfo().setConnType(UserInfo::PASV);

    //发送当前创建的TCP服务器地址
    int listenfd = SimpleServer::BuildSimpleServer(0);
    conn->getUserInfo().setListenfd(listenfd);
    struct sockaddr_in address = sockets::getLocalAddr(listenfd);

    in_port_t port = sockets::hostToNetwork16(address.sin_port);
    in_addr_t addr = sockets::hostToNetwork32(address.sin_addr.s_addr);

    char ipvsport[64] = {0};
    sprintf(ipvsport, "(%d,%d,%d,%d,%d,%d)\r\n",
                    (addr >> 24) & 0xff,
                    (addr >> 16) & 0xff,
                    (addr >>  8) & 0xff,
                    (addr      ) & 0xff,                                                                  
                    (port >>  8) & 0xff,
                    (port      ) & 0xff);

    FtpCmd::SendMsg("227 Entering Passive Mode ", ipvsport, conn);
}

/* 主动连接 */
int do_port(std::string param, const TcpConnectionPtr &conn)
{
    UserInfo &userinfo = conn->getUserInfo();
    userinfo.setConnType(UserInfo::PORT);
    userinfo.setPortAddr(param);

    FtpCmd::SendMsg("200","PORT command successful.\r\n", conn);
}

/* 重命名 */
int do_rnfr(std::string param, const TcpConnectionPtr &conn)
{
    std::string name = trim(param);
    if(name.c_str()[0] == '/') {
                name = FtpCmd::GetHomePath() + name;
    } else { 
                name = conn->getUserInfo().getCurrWorkdir() + "/" + name;
    } 
    conn->getUserInfo().setOldPath(name);
    FtpCmd::SendMsg("350", "Ready for RNTO.\r\n", conn);

    return 0;
}

/* 重命名 */
int do_rnto(std::string param, const TcpConnectionPtr &conn)
{
    std::string name = trim(param);
    if(name.c_str()[0] == '/') {
        name = FtpCmd::GetHomePath() + name;
    } else {    
        name = conn->getUserInfo().getCurrWorkdir() + "/" + name;
    }           

    int res = ::rename(conn->getUserInfo().getOldPath().c_str(), name.c_str());
    if(res < 0) {
        FtpCmd::SendMsg("550", "Rename Failed.\r\n", conn);
    } else {
        FtpCmd::SendMsg("250", "Rename Success.\r\n", conn);
    }

    return 0;
}

/* 获取大小 */
int do_size(std::string param, const TcpConnectionPtr &conn)
{
    UserInfo &userinfo = conn->getUserInfo();
    std::string filename = userinfo.getCurrWorkdir() + param;

    struct stat buf;
    if((stat(filename.c_str(), &buf) != 0) || (S_ISDIR(buf.st_mode))) {
        FtpCmd::SendMsg("550", "Could not get file size.\r\n", conn);
        return -1;
    }
    char str[1024] = {0};
    sprintf(str, "%d\r\n", buf.st_size);
    FtpCmd::SendMsg("213", str, conn);
    return 1;
}

/* 等待 */
int do_noop(std::string param, const TcpConnectionPtr &conn)
{
    FtpCmd::SendMsg("200","NOOP ok.\r\n", conn);
    return 1;
}

/* 上传 */
int do_stor(std::string param, const TcpConnectionPtr &conn)
{
    FtpCmd::SendMsg("150", "Ok, Let's Send file.\r\n", conn);
    //获取发送通道
    int transfd = BuildConnect(conn);
    conn->getUserInfo().setStorfd(transfd);
    
    //打开文件
    std::string filename = "";
    if(param.c_str()[0] == '/') {
        while(param.c_str()[1] == '.' && param.c_str()[2] == '.') {
			param = param.substr(3);
		}
        filename = FtpCmd::GetHomePath() + param;
    } else {
        filename = conn->getUserInfo().getCurrWorkdir() + "/" + param;
    }
    conn->getUserInfo().setFilename(filename);
    int fd = creat(filename.c_str(), 0644 | O_NONBLOCK);
    if(fd < 0) {
        FtpCmd::SendMsg("550", "Bad, Stor file failed, Access denied.\r\n", conn);
    }
    
    int res = FtpCmd::GetFile(transfd, fd);
    if(res < 0) {
        FtpCmd::SendMsg("550", "Bad, Stor file failed, Access denied.\r\n", conn);
    } else {
        FtpCmd::SendMsg("226", "Ok, Stor file Succeed.\r\n", conn);
    } 

    close(transfd);
    close(fd);
    conn->getUserInfo().setConnType(UserInfo::NONE);
    return 0;
}

/* 下传 */
int do_down(std::string param, const TcpConnectionPtr &conn)
{
    //打开文件
    std::string filename = "";
    if(param.c_str()[0] == '/') {
        while(param.c_str()[1] == '.' && param.c_str()[2] == '.') {
            param = param.substr(3);
        }
        filename = FtpCmd::GetHomePath() + param;
    } else {
        filename = conn->getUserInfo().getCurrWorkdir() + "/" + param;
    }
    int fd = open(filename.c_str(), O_RDONLY | O_LARGEFILE | O_NONBLOCK);
    if(fd < 0) {
        FtpCmd::SendMsg("550", "File Send Fail, Access denied.\r\n", conn);
        fprintf(stderr, "Open File %s fail.\n", filename.c_str());
    }
    struct stat buf;
    stat(filename.c_str(), &buf); 
    std::string msg = "Opening BINARY mode data connection for " + param + "\r\n";
    FtpCmd::SendMsg("150", msg, conn);
    
    //获取发送通道
    int transfd = BuildConnect(conn);
    conn->getUserInfo().setDownfd(transfd);
    
    unsigned long long offset = conn->getUserInfo().getRset();
    unsigned long long res = FtpCmd::SendFile(fd, transfd, offset);
    if(( res + offset ) == buf.st_size) {
        FtpCmd::SendMsg("226", "File Send Ok.\r\n", conn);
    } else {
        FtpCmd::SendMsg("550", "File Send Fail.\r\n", conn);
    }
    
    conn->getUserInfo().setConnType(UserInfo::NONE);
    conn->getUserInfo().setRset(0);

    close(transfd);
    close(fd);
    return 0;
}

/* 追加模式 */
int do_append(std::string param, const TcpConnectionPtr &conn)
{
    FtpCmd::SendMsg("150","Append success \r\n", conn);

    //获取发送通道
    int transfd = BuildConnect(conn);
    conn->getUserInfo().setStorfd(transfd);
    FtpCmd::SendMsg("150", "Ok, Let's Send file.\r\n", conn);
    
    //打开文件
    std::string filename = "";
    if(param.c_str()[0] == '/') {
        while(param.c_str()[1] == '.' && param.c_str()[2] == '.') {
            param = param.substr(3);
        }
        filename = FtpCmd::GetHomePath() + param;
    } else {
        filename = conn->getUserInfo().getCurrWorkdir() + "/" + param;
    }
    int fd = ::open(filename.c_str(), O_APPEND | O_WRONLY);
    if(fd < 0) {
        FtpCmd::SendMsg("550", "Bad, Stor file failed, Access denied.\r\n", conn);
    }
    
    int res = FtpCmd::GetFile(transfd, fd);
    if(res < 0) {
        FtpCmd::SendMsg("550", "Bad, Stor file failed, Access denied.\r\n", conn);
    } else {
        FtpCmd::SendMsg("226", "Ok, Stor file Succeed.\r\n", conn);
    }
    close(transfd);
    close(fd);
    conn->getUserInfo().setConnType(UserInfo::NONE);
    return 0;
}

/* 终止传输 */
int do_abort(std::string param, const TcpConnectionPtr &conn)
{
    UserInfo &userinfo = conn->getUserInfo();
    int storfd = userinfo.getStorfd();
    int downfd = userinfo.getDownfd();
    shutdown(storfd, SHUT_RDWR);
    shutdown(downfd, SHUT_RDWR);
}

/* 获取服务器状态信息 */
int do_stat(std::string param, const TcpConnectionPtr &conn)
{
    FtpCmd::SendMsg("214", "Server is running.\r\n", conn);
}

int do_site(std::string param, const TcpConnectionPtr &conn)
{
    std::vector<std::string> strs;
    boost::split(strs, param, boost::is_any_of(" "));
    if(strs[0] == "CHMOD") {
        ::chmod(conn->getUserInfo().getFilename().c_str(), strtol(strs[1].c_str(), NULL, 8));
        FtpCmd::SendMsg("200", "Access Chmod Ok.\r\n", conn);   return 0;
    }
    FtpCmd::SendMsg("200", "Site Ok.\r\n", conn);
}

FTPCMD cmd_list[] = {
    {"USER",    do_user,    CHECK_NOLOGIN | NEED_PARAM  },
    {"PASS",    do_pass,    CHECK_NOLOGIN               },
    {"CWD",     do_cwd,     CHECK_LOGIN | NEED_PARAM    },
    {"XCWD",    do_cwd,     CHECK_LOGIN | NEED_PARAM    },
    {"CDUP",    do_cdup,    CHECK_LOGIN | NO_PARAM      },
    {"XCUP",    do_cdup,    CHECK_LOGIN | NO_PARAM      },
    {"SYST",    do_syst,    CHECK_LOGIN                 },
    {"PWD",     do_pwd,     CHECK_LOGIN | NO_PARAM      },
    {"XPWD",    do_pwd,     CHECK_LOGIN | NO_PARAM      },
    {"TYPE",    do_type,    CHECK_LOGIN | NEED_PARAM    },
    {"PORT",    do_port,    CHECK_LOGIN | NEED_PARAM    },
    {"LIST",    do_list,    CHECK_LOGIN                 },
    {"NLST",    do_nlist,   CHECK_LOGIN                 },
    {"RMD",     do_rmd,     CHECK_LOGIN | NEED_PARAM    },
    {"XRMD",    do_rmd,     CHECK_LOGIN | NEED_PARAM    },
    {"MKD",     do_mkd,     CHECK_LOGIN | NEED_PARAM    },
    {"XMKD",    do_mkd,     CHECK_LOGIN | NEED_PARAM    },
    {"DELE",    do_del,     CHECK_LOGIN | NEED_PARAM    },
    {"REIN",    do_reinit,  CHECK_LOGIN                 },
    {"HELP",    do_help,    CHECK_LOGIN                 },
    {"QUIT",    do_quit,    NO_CHECK                    },
    {"REST",    do_reset,   CHECK_LOGIN | NEED_PARAM    },
    {"PASV",    do_pasv,    CHECK_LOGIN | NO_PARAM      },
    {"RNFR",    do_rnfr,    CHECK_LOGIN | NEED_PARAM    },
    {"RNTO",    do_rnto,    CHECK_LOGIN | NEED_PARAM    },
    {"SIZE",    do_size,    CHECK_LOGIN | NEED_PARAM    },
    {"NOOP",    do_noop,    NO_CHECK                    },
    {"STOR",    do_stor,    CHECK_LOGIN | NEED_PARAM    },
    {"RETR",    do_down,    CHECK_LOGIN | NEED_PARAM    },
    {"APPE",    do_append,  CHECK_LOGIN | NEED_PARAM    },
    {"ABOR",    do_abort,   CHECK_LOGIN | NO_PARAM      },
    {"ACCT",    NULL                                    },
    {"SMNT",    NULL                                    },
    {"STRU",    NULL                                    },
    {"MODE",    NULL                                    },
    {"STOU",    NULL                                    },
    {"ALLO",    NULL                                    },
    {"MDTM",    NULL,       CHECK_LOGIN | NEED_PARAM    },
    {"SITE",    do_site,    CHECK_LOGIN | NEED_PARAM    },
    {"STAT",    do_stat,    CHECK_LOGIN | NO_PARAM      },
    {"",        NULL}
};

namespace FtpCmd
{

void SendMsg(std::string ID, std::string msg, const TcpConnectionPtr &conn)
{
    conn->send(ID + " " + msg);
}

int CheckCmd(FTPCMD *ftpCmd, std::string param, const TcpConnectionPtr& conn)
{
    //1.是否不检查命令
    if ( (ftpCmd->check>>4) & 0x01)   //NO_CHECK
    {
        return 1;
    }
    
    //2.不需要参数
    if( (ftpCmd->check>>3) &0x01)   //NO_PARAM 
    {
        if (param != "")
        {
            SendMsg("550","Needless parameter.\r\n", conn);
            return 0;
        }
    }
    
    //3.需要参数
    if ( (ftpCmd->check>>2)&0x01 )
    {
        if (param == "") 
        {
            SendMsg("550","Need parameter.\r\n", conn);
            return 0;
        }   
    }       
                                                    
    //4.检查当前没登录
    if ( (ftpCmd->check>>1)& 0x01)
    {
        if (conn->getUserInfo().getIsLogined() != false)
        {
            SendMsg("550","logged in.\r\n", conn);
            return 0;
        }   
    }      
                                                                                                                                              
    //5.检查当前必须已经登录
    if (ftpCmd->check & 0x01)
    {
        if (conn->getUserInfo().getIsLogined() == false)
        {
            SendMsg("550","Not logged in.\r\n", conn);                                                                             
            return 0;
        }
    }

    return 1;
}

/* 执行命令的接口函数 */
int ExecCmd(std::string cmd, std::string param, const TcpConnectionPtr& conn)
{
    bool isFind = false;
    int i = 0;
    //1.遍历数组，寻找对应的回调函数
    while(cmd_list[i].cmd != std::string("")) {
        if(cmd == cmd_list[i].cmd) {
            isFind = true;
            
            //2.执行内部的命令
            if( (cmd_list[i].cmd_handler) && (CheckCmd(&cmd_list[i], param, conn)) ) {
                cmd_list[i].cmd_handler(param, conn);
            } else if (! cmd_list[i].cmd_handler) {
                SendMsg("502", "Command Not Implemented, Superfluous a this site.\r\n", conn);
            }
            break;
        } 
        ++ i;
    }

    if( ! isFind ) {
        SendMsg("500", "Command Not Understood.\r\n", conn);
    }

    return 0;
}

int ExecCmd(std::string cmd_param, const TcpConnectionPtr& conn)
{
    std::string cmd = "";
    std::string param = "";
    
    size_t mid = cmd_param.find_first_of(' ');
    if(mid == std::string::npos) {
        cmd = cmd_param;
    } else {
        size_t end = cmd_param.find_last_not_of(' ');
        cmd = cmd_param.substr(0, mid);
        param = cmd_param.substr(mid + 1, std::string::npos);
    }

    return ExecCmd(cmd, param, conn);
}

/* 通过用户名获取当前用户主目录 */
std::string GetHomePath()
{
    std::string homePath;
    Config::NewConfig()->Read("HomePath", homePath);
    if(homePath == "") {
        homePath = "/var/ftp/";
    }
    return homePath;
}

void GetAddress(std::string address, char ip[], unsigned short &port)
{
    memcpy(ip, address.c_str(), address.size());
    char *pos = NULL;
    in_port_t hight8;
    in_port_t low8;

    pos = strrchr(ip, ',');
    *pos++ = '\0';
    low8 = (in_port_t)atoi(pos);
    pos = strrchr(ip, ',');
    *pos++ = '\0';
    hight8 = (in_port_t)atoi(pos);

    port = (hight8 << 8) | low8;

    while((pos = strchr(ip, ',')) != NULL) {
        *pos = '.';
    }
}

int SendShortDir(int transfd, std::string &pathname)
{
    DIR *dp = opendir(pathname.c_str());
    struct dirent *link = NULL;
    std::string files = "";
    while((link = readdir(dp)) != NULL) {
        char buf[1024] = {0};
        sprintf(buf, "%s%s", link->d_name, "\r\n");
        files += buf;
    }
    ::write(transfd, files.c_str(), files.size());
    closedir(dp);
}

int SendCurrentDir(int transfd, bool hide, std::string &pathname)
{
    //1. 打开当前目录
    DIR *dp = opendir(pathname.c_str());
    if(dp == NULL) {
        return -1;
    }
    //2. 读取当前目录的所有文件
    struct dirent *link = NULL;
    std::string files = "";
    while((link = readdir(dp)) != NULL) {
        struct stat sbuf;
        if(lstat((pathname + "/" + link->d_name).c_str(), &sbuf) == -1) {
            continue;
        }

        if( hide && (link->d_name[0] == '.')) {
            continue;
        }

        mode_t mode = sbuf.st_mode;
        char perms[] = "----------";
        perms[0] = '?';
        switch ( mode & S_IFMT ) {
            case S_IFREG:
                perms[0] = '-';
                break;
            case S_IFDIR:
                perms[0] = 'd';
                break;
            case S_IFLNK:
                perms[0] = 'l';
                break;
            case S_IFIFO:
                perms[0] = 'p';
                break;
            case S_IFSOCK:
                perms[0] = 's';
                break;
            case S_IFCHR:
                perms[0] = 'c';
                break;
            case S_IFBLK:
                perms[0] = 'b';
                break;
        }

        if(mode & S_IRUSR ) perms[1] = 'r';
        if(mode & S_IWUSR ) perms[2] = 'w';
        if(mode & S_IXUSR ) perms[3] = 'x';
        if(mode & S_IRGRP ) perms[4] = 'r';
        if(mode & S_IWGRP ) perms[5] = 'w';
        if(mode & S_IXGRP ) perms[6] = 'x';
        if(mode & S_IROTH ) perms[7] = 'r';
        if(mode & S_IWOTH ) perms[8] = 'w';
        if(mode & S_IXOTH ) perms[9] = 'x';
        perms[10] = '\0';

        //获取目录修改日期
        int off = 0;
        char buf[1024] = {0};
        off += sprintf(buf + off, "%s ", perms);
        off += sprintf(buf + off, " %3d %-8d %-8d ", sbuf.st_nlink, sbuf.st_uid, sbuf.st_gid);
        off += sprintf(buf + off, "%8lu ", (unsigned long)sbuf.st_size);

        const char *p_date_format = "%b %e %H:%M";
        char datebuf[13] = {0};
        struct tm *p_tm;
        struct timeval tv;
        long local_time;
        gettimeofday(&tv, NULL);
        local_time = tv.tv_sec;

        p_tm = localtime(&sbuf.st_mtime);

        if(sbuf.st_mtime > local_time || (local_time - sbuf.st_mtime) > 60*60*24*182) {
            p_date_format = "%b %e  %Y";
        }
        strftime(datebuf, sizeof(datebuf), p_date_format, p_tm);

        off += sprintf(buf + off, "%s ", datebuf);

        if(S_ISLNK(sbuf.st_mode)) {
            char tmp[1024] = {0};
            readlink(link->d_name, tmp, sizeof(tmp));
            off += sprintf(buf + off, "%s -> %s", link->d_name, tmp);
        } else {
            off += sprintf(buf + off, "%s", link->d_name);
        }

        off += sprintf(buf + off, "%s", "\r\n");
        
        files += buf;
    }
    ::write(transfd, files.c_str(), files.size());
    closedir(dp);
    return 0;
}

void WaitTime(unsigned long long usec)
{
   //等待
    struct timeval time;
    time.tv_sec = 0;
    time.tv_usec = usec ;
    select(FD_SETSIZE,NULL,NULL,NULL,&time);
}

unsigned long long SendFile(int fd_in, int fd_out, unsigned long long offset)
{
    char buf[1024] = {0};
    std::string value;
    Config::NewConfig()->Read("DownSpeeds", value);
    unsigned long long speed = atol(value.c_str());

    struct timeval tvbefore;
    struct timeval tvafter;

    gettimeofday(&tvbefore, NULL);

    unsigned long long total = 0;
    unsigned long long ret = 0;

    lseek(fd_in, offset, SEEK_SET);

    int n = 0;
    while (( n = ::read(fd_in, buf, sizeof(buf))) > 0 ) {
        ::write(fd_out, buf, n);
        bzero(buf, sizeof(buf));
        
        total += n;
        ret += n;
        if(total >= speed * 1024 * 1024) {
            gettimeofday(&tvafter, NULL);
            unsigned long long usec = 1000000 - 1000000 * (tvafter.tv_sec - tvbefore.tv_sec) - (tvafter.tv_usec - tvbefore.tv_usec);
            WaitTime(usec);
            //重新统计
            total = 0;
            gettimeofday(&tvbefore, NULL);
        }
    }

    return ret;
}

int GetFile(int fd_in, int fd_out)
{
    char buf[1024] = {0};
    int n = 0;
    struct timeval tvbefore;
    struct timeval tvafter;
    std::string value;
    Config::NewConfig()->Read("UpSpeeds", value);
    unsigned long long speed = atol(value.c_str());
    gettimeofday(&tvbefore, NULL);

    unsigned long long total = 0;

    while((n = ::read(fd_in, buf, sizeof(buf))) > 0) {
        ::write(fd_out, buf, n);
        bzero(buf, sizeof(buf));
        
        total += n;
        if(total >= speed * 1024 * 1024) {
            gettimeofday(&tvafter, NULL);
            unsigned long long usec = 1000000 - 1000000 * (tvafter.tv_sec - tvbefore.tv_sec) - (tvafter.tv_usec - tvbefore.tv_usec);
            WaitTime(usec);
            //重新统计
            total = 0;
            gettimeofday(&tvbefore, NULL);
        }
    }

    if(n == 0) {
        return 1;
    } else {
        return -1;
    }
}

}	// endof namespace FtpCmd
	
}	// endof namespace miniftp


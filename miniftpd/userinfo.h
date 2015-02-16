#ifndef _USERINFO_H_
#define _USERINFO_H_

#include <string>

namespace miniftp 
{

class UserInfo
{
public:
    typedef enum {NONE, PASV, PORT} ConnType;   

    bool getIsLogined() const
    {
        return m_isLogined;
    }

    void setIsLogined(bool on)
    {
        m_isLogined = on;
    }

    const std::string& getUsername() const
    {   
        return m_username;
    }

    void setUsername(std::string uname)
    {
        m_username = uname;
    }

    unsigned long long &getRset()
    {
        return m_rset;
    }

    void setRset(unsigned long long rset)
    {
        m_rset = rset;
    }

    ConnType &getConnType()
    {
        return m_conntype;
    }
    
    void setConnType(ConnType conntype) 
    {
        m_conntype = conntype;
    }

    std::string& getCurrWorkdir()
    {
        return m_currWorkdir;
    }

    void setCurrWorkdir(std::string dir)
    {
        m_currWorkdir = dir;
    }

    std::string getOldPath() const
    {
        return m_oldPath;
    }

    void setOldPath(std::string oldPath) 
    {
        m_oldPath = oldPath;
    }

    int getListenfd() const
    {
        return m_listenfd;
    }

    void setListenfd(int fd)
    {
        m_listenfd = fd;
    }
    int getStorfd() const 
    {
        return m_storfd;
    }

    void setStorfd(int fd)
    {
        m_storfd = fd;
    }

    int getDownfd() const 
    {
        return m_downfd;
    }

    void setDownfd(int fd)
    {
        m_downfd = fd;
    }

    std::string getFilename() const
    {
        return m_filename;
    }

    void setFilename(std::string filename) 
    {
        m_filename = filename;
    }

    std::string getPortAddr() const 
    {
        return m_addr;
    }

    void setPortAddr(std::string &addr)
    {
        m_addr = addr;
    }   
private:
    /* 是否已经登录 */
    bool            m_isLogined; 
    /* 用户名 */
    std::string     m_username;
    /* 偏移量 */
    unsigned long long  m_rset;
    /* 链接方式 */
    ConnType        m_conntype;
    /* 主动连接接收到的IP地址及端口 */
    std::string     m_addr;
    /* 当前的工作目录 */
    std::string     m_currWorkdir;
    /* 上一次的路径 */
    std::string     m_oldPath;
    /* 正在监听的端口 */
    int             m_listenfd;
    /* 正在上传数据的端口 */
    int             m_storfd;
    /* 正在下载数据的端口 */
    int             m_downfd;
    /* 正在上传的文件名称  */
    std::string     m_filename;
};

}
#endif

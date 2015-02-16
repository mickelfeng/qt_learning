#ifndef	_READ_CONFIG_H_
#define	_READ_CONFIG_H_

#include <map>
#include <string>
#include <fstream>

#include <boost/shared_ptr.hpp>

namespace miniftp {

static std::string trim(const std::string& str)
{
    std::string::size_type start = str.find_first_not_of(' ');
    if(start == std::string::npos) return str;

    std::string::size_type end = str.find_last_not_of(' ');
    if(end != std::string::npos) 
        return str.substr(start, end - start + 1);

    return str.substr(start);
}

class Config 
{
private:
    /* 配置文件键值集合 */
    std::map<std::string, std::string> m_ftpconfig;
    /*构造函数*/
    Config()
    {
        const char *filename = "/etc/miniftpd/miniftpd.conf";
        
        /*保存当前用户权限*/
        int eUID = geteuid();
        int eGID = getegid();
    
        /*设置0权限*/
        seteuid(0);
        setegid(0);
    
        /*读取文件流*/
        std::ifstream ifs(filename);
        std::string line = "";
        while(!ifs.eof()) {
            getline(ifs, line);
            /*修复字符串*/
            line = trim(line);
            /*空行与注释行跳过*/
            if(line.empty() || line.at(0) == '#')   continue;
            /*语法错误行跳过*/
            std::string::size_type pos = std::string::npos;
            if((pos = line.find('=')) == std::string::npos) continue;

            std::string key = trim(line.substr(0, pos));
            std::string value = trim(line.substr(pos + 1, line.size() - pos - 1));
    
            if(! key.empty())   this->m_ftpconfig[key] = value;
        }

        ifs.close();

        /*恢复用户权限*/
        setegid(eGID);
        seteuid(eUID);
    }
    
    static boost::shared_ptr<Config> ftp_config;

public:
    /* 单例类 */
    static Config* NewConfig()
    {
        if(ftp_config.get() == NULL) {
            ftp_config.reset(new Config);
        }
        return ftp_config.get();
    }

    /* 获取某一个Key的值 */
    bool Read(const std::string& key, std::string &value)
    {
        value = m_ftpconfig[key];
        if(value.size() > 0) 
            /*键值有记录*/
            return true;
        else 
            /*键值无记录*/
            return false;
    }
};

};

#endif /* Endof _READ_CONFIG_H_ */




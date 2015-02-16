#ifndef _LOG_H_
#define _LOG_H_

#include <boost/shared_ptr.hpp>

#include <string>
#include <fstream>

#include <readconfig.h>
#include <utils.h>

namespace miniftp {

class Loger {
public:
    /* 单例类 */
    static Loger * NewLoger() 
    {
        if(NULL == _instance.get()) {
            _instance.reset(new Loger);
        }
        return _instance.get();
    }
    
    /* 日志接口 */
    bool write(std::string loginfo)
    {
        return_if_fail(! loginfo.empty());
        
        Config *conf = Config::NewConfig();
        std::string logPath = "";
        return_if_fail(conf->Read("LogfilePath", logPath));

        int eUID = geteuid();
        int eGID = getegid();
        setegid(0);
        seteuid(0);

        std::ofstream ofs;
        time_t t = time(0);
        char tmp[64] = {0};
        strftime(tmp, sizeof(tmp), "[%Y.%m.%d %X %A]", localtime(&t));
        ofs.open((logPath + std::string("/miniftp.log")).c_str(), std::fstream::app);
        
        if(! ofs.is_open()) {
            INFO("LogFile Path is error or has't permission");
        }

        ofs << tmp << "\t";
        ofs.write(loginfo.c_str(), loginfo.size());
        ofs << "\n";

        ofs.flush();
        ofs.close();

        seteuid(eUID);
        setegid(eGID);
    }

private:
    Loger() {}
    
    static boost::shared_ptr<Loger> _instance;
};

};
#endif

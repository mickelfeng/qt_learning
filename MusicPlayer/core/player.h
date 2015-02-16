/**
 *
 *  功能描述：播放模块，播放、暂停、停止功能
 *  作者    ：LiuYun
 *  邮箱    ：wolf_coming@sina.cn
 *  
 */

#ifndef __PLAYER__H__
#define __PLAYER__H__

#include "mp_errno.h"
#include "types.h"
#include "threads.h"
#include "cmd.h"

#include <boost/noncopyable.hpp>

namespace mp {

class Player : public boost::noncopyable
{
private:
    /*播放文件名*/
    char m_filename[200];
    /*播放状态*/
    Status m_status;
    /*播放线程*/
    Threads m_thread;
    
public:
    /*默认构造函数*/
    Player();
    /*带文件名的构造函数*/
    Player(const char *filename);
    /*播放*/
    u32 play();
    /*随进度播放*/
    u32 play(u8 &progress);
    /*随文件播放*/
    u32 play(const char* filename);
    /*随文件进度播放*/
    u32 play(const char* filename, u8 &progress);
    /*停止播放*/
    u32 stop();
    /*暂停播放*/
    u32 suspend();
    /*恢复播放*/
    u32 recover();
    /*设置文件名*/
    void set_filename(const char *filename);
    /*设置播放状态*/
    void set_status(Status st = STOPED);
    /*获取状态*/
    Status get_status();
    /*获取进度*/
    u8 get_progress();
};

};
#endif  

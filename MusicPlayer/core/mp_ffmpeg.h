/**
 *
 *  功能描述：ffmpeg库封装库
 *  作者    ：LiuYun
 *  邮箱    ：wolf_coming@sina.cn
 *  
 */

#ifndef __MP_FFMPEG_H__
#define __MP_FFMPEG_H__

#include <strings.h>
#include "types.h"

namespace mp {

class FFmpeg
{
private:
    char m_filename[200];

public:
    /*默认的构造函数*/
    FFmpeg() { bzero(m_filename, sizeof(m_filename)); }
    /*设置文件名*/
    void set_filename(const char filename[]);
    /*打开文件*/
    u32 open();
    /*关闭文件*/
    u32 close();
    /*播放文件*/
    u32 play();
    /*暂停播放*/
    u32 suspend();
    /*恢复播放*/
    u32 recover();
    /*停止播放*/
    u32 stop();
};

};

#endif  

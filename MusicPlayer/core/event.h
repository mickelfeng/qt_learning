/**
 *
 *  功能描述：事件基本单元，包含事件监听的文件描述符与回调函数
 *  作者    ：LiuYun
 *  邮箱    ：wolf_coming@sina.cn
 *
 */

#ifndef __EVENT_H__
#define __EVENT_H__

#include "types.h"

namespace mp{

typedef u32 (* Event_cb )(int fd);

struct Event
{
    /*事件文件描述符*/
    int fd;
    /*回调函数*/
    Event_cb m_event_cb;
};

};
#endif

/**
 *
 *  功能描述：Epoll 函数的封装，管理事件集合
 *  作者    ：LiuYun
 *  邮箱    ：wolf_coming@sina.cn
 *
 */

#ifndef __MP_EPOLL_H__
#define __MP_EPOLL_H__

#include "event.h"
#include "types.h"
#include "mp_errno.h"

#include <vector>
#include <fcntl.h>
#include <unistd.h>
#include <sys/epoll.h>

#include <boost/noncopyable.hpp>

namespace mp
{
    
class Epoller : public boost::noncopyable
{
public:
    typedef std::vector<struct Event *> EventList;
    /*默认构造函数*/
    Epoller();
    /*默认析构函数*/
    ~Epoller();
    /*轮询函数*/
    void poll();
    /*增加事件*/
    void add_event(Event *event);
    /*删除事件*/
    u32 remove_event(Event *event);

private:
    /*查找fd所需要的callback*/
    Event_cb search_cb(int fd);
    /*同时最大监听事件数*/
    static const int MAX_EVENT_SIZE = 200;
    /*事件列表*/
    EventList m_events;
    /*文件描述符*/
    int m_event_fd;
    /*监听Epoll事件*/
    struct epoll_event m_epoll_event[MAX_EVENT_SIZE];
};

};

#endif

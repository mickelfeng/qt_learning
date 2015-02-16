/**
 *
 *  功能描述：事件循环类，提供对事件的抽象
 *  作者    ：LiuYun
 *  邮箱    ：wolf_coming@sina.cn
 *
 */

#ifndef __EVENTLOOP_H__
#define __EVENTLOOP_H__

#include "event.h"
#include "mp_epoll.h"

#include <boost/noncopyable.hpp>

namespace mp {

class EventLoop : public boost::noncopyable
{
public:
    /*增加监听事件*/
    void add_event(Event *event);
    /*删除监听事件*/
    void remove_event(Event *event);
    /*事件循环*/
    void loop();

private:
    /*轮询器*/
    Epoller m_epoller;
    
};

};

#endif

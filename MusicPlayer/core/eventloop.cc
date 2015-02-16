/**
 *
 *  功能描述：事件循环类，提供对事件的抽象
 *  作者    ：LiuYun
 *  邮箱    ：wolf_coming@sina.cn
 *
 */

#include "eventloop.h"

using namespace mp;

void EventLoop::add_event(Event *event)
{
    m_epoller.add_event(event);
}

void EventLoop::remove_event(Event *event)
{
    m_epoller.remove_event(event);
}

void EventLoop::loop()
{
    for(;;) {
        m_epoller.poll();
    }
}

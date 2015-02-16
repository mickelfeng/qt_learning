#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>

namespace miniftp
{

enum EventType {ENABLEREAD = 0x8001, ENABLEWRITE, DISABLEWRITE, DISABLEALL};

class Event : boost::noncopyable
{
public:
    typedef boost::function<void()> EventCallBack;

    Event(int fd);

    ~Event();

    void setReadCB(const EventCallBack &cb)
    {
        m_readCallBack = cb;
    }

    void setWriteCB(const EventCallBack &cb)
    {
        m_writeCallBack = cb;
    }

    void setErrorCB(const EventCallBack &cb)
    {
        m_errorCallBack = cb;
    }

    void setCloseCB(const EventCallBack &cb)
    {
        m_closeCallBack = cb;
    }

    int events(void)
    {
        return m_events;
    }

    int fd()
    {
        return m_fd;
    }

    void setRevents(int revents)
    {
        m_revents = revents;
    }

    void handleEvent();

    void setEventType(EventType tp)
    {
        switch(tp) {
            case ENABLEREAD:
                m_events |= kReadEvent;
                break;
            case ENABLEWRITE:
                m_events |= kWriteEvent;
                break;
            case DISABLEWRITE:
                m_events &= ~kWriteEvent;
                break;
            case DISABLEALL:
                m_events = kNoneEvent;
                break;
            default:
                break;
        }
    }

    bool isWriting()
    {
        return m_events & kWriteEvent;
    }

private:
    static const int kNoneEvent;
    static const int kReadEvent;
    static const int kWriteEvent;

    /* 读数据回调函数 */
    EventCallBack m_readCallBack;
    /* 写书据回调函数 */
    EventCallBack m_writeCallBack;
    /* 出错回调函数 */
    EventCallBack m_errorCallBack;

    EventCallBack m_closeCallBack;
    /* 事件 */
    int m_events;
    /* 事件返回值 */
    int m_revents;
    /* 一个事件包含的文件描述符 */
    int m_fd;
};

};

#endif

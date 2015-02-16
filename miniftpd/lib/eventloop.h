#ifndef _EVENTLOOP_H_
#define _EVENTLOOP_H_

#include <boost/noncopyable.hpp>
#include <boost/function.hpp>
#include <boost/scoped_ptr.hpp>

#include <vector>

#include <lib/epoll.h>
#include <lib/event.h>
#include <lib/mutex.h>

namespace miniftp
{

class EventLoop : boost::noncopyable
{
public:
    typedef boost::function<void()> Functor;
    typedef std::vector<Event *> EventList;

    EventLoop();

    ~EventLoop();

    /* 循环 */
    void loop();

    /* 更新事件 */
    void updateEvent(Event *ev);

    /* 删除事件 */
    void removeEvent(Event *ev);

    /* 退出事件循环 */
    void quit();

    void runInLoop(const Functor &);

    
private:
    static const int kPollTimeMs = 4000;

    /* 循环的标志 */
    bool m_quit;
    
    /* 循环器 */
    boost::scoped_ptr<EPollor>  m_pollor;

    /* 事件循环列表 */
    EventList m_activeEvents;

    std::vector<Functor> m_pendingFunctors;

    /*事件触发后调用的函数*/
    void doPendingFunctors();

    MutexLock   m_mutex;
};

};

#endif

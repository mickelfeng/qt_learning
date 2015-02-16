#ifndef _EPOLL_H_
#define _EPOLL_H_

#include <lib/event.h>

#include <boost/noncopyable.hpp>

#include <sys/epoll.h>
#include <vector>
#include <map>

namespace miniftp {

class EPollor 
{
public:
    typedef std::vector<Event *> EventList;
    
    EPollor();

    ~EPollor();

    void poll(int timoutMs, EventList *activeEvents);

    void updateEvent(Event *ev);

    void removeEvent(Event *ev);

private:
    static const int kInitEventListSize = 16;

    void fillActiveEvents(int numEvents, EventList *activeEvents)   const;

    void update(int operation, Event *ev);

    typedef std::vector<struct epoll_event> EpollEventList;
    typedef std::map<int, Event *> EventMap;

    int m_epollfd;

    EpollEventList m_epollevents;
    EventMap m_eventmap;
};


};

#endif

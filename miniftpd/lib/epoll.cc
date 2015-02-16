#include <lib/epoll.h>
#include <log.h>
#include <boost/implicit_cast.hpp>
#include <errno.h>

using namespace miniftp;

EPollor::EPollor()
    :   m_epollfd(::epoll_create(EPOLL_CLOEXEC)),
        m_epollevents(kInitEventListSize)
{
    if(m_epollfd < 0) {
        INFO("EPoll_Create Failure!");
    }
}

EPollor::~EPollor()
{
    ::close(m_epollfd);
}

void EPollor::poll(int timeoutMs, EventList* activeEvents)
{
    int numEvents = ::epoll_wait(m_epollfd, &*m_epollevents.begin(), 
            static_cast<int>(m_epollevents.size()), timeoutMs);
    if(numEvents > 0) {
     //   fprintf(stdout, "%d Events happended\n", numEvents);
        fillActiveEvents(numEvents, activeEvents);
        if(boost::implicit_cast<size_t>(numEvents) == m_epollevents.size()) {
            m_epollevents.resize(m_epollevents.size() * 2);
        }
    } else if (numEvents == 0) {
      //  fprintf(stdout, "Nothing Happened\n");
    } else {
        switch(errno) {
            case EBADF:
                fprintf(stderr, "epollfd Is not a Valid File Descriptor.\n");
                break;
            case EFAULT:
                fprintf(stderr, "The memory area pointed to by events is not accessible with write permissions.\n");
                break;
            case EINTR:
                break;
            case EINVAL:
                fprintf(stderr, "epfd is not an epoll file descriptor, or maxevents is less than or equal to zero.\n");
                break;
        }
    }
}

void EPollor::fillActiveEvents(int numEvents, EventList *activeEvents) const 
{
    assert(boost::implicit_cast<size_t>(numEvents) <= m_epollevents.size());
    for(int i = 0; i < numEvents; ++i) {
        Event *ev = static_cast<Event *>(m_epollevents[i].data.ptr);
        ev->setRevents(m_epollevents[i].events);
        activeEvents->push_back(ev);
    }
}

void EPollor::updateEvent(Event *ev)
{
    /*文件描述符*/
    int fd = ev->fd();
    m_eventmap[fd] = ev;

    update(EPOLL_CTL_ADD, ev);
}

void EPollor::removeEvent(Event *ev)
{
    int fd = ev->fd();
    assert(m_eventmap.find(fd) != m_eventmap.end());
    assert(m_eventmap[fd] == ev);
    assert(m_eventmap.erase(fd) == 1);

    update(EPOLL_CTL_DEL, ev);
}

void EPollor::update(int operation, Event *ev)
{
    struct epoll_event event;
    bzero(&event, sizeof event);
    event.events = ev->events();
    event.events |= EPOLLET;
    event.data.ptr = ev;

    int ret = ::epoll_ctl(m_epollfd, operation, ev->fd(), &event);
    if(ret < 0 && errno != EEXIST) {
        INFO("EPoll modify Failure !");
    }
}


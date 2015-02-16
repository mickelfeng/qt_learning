#include <lib/event.h>

#include <sys/epoll.h>

using namespace miniftp;

const int miniftp::Event::kNoneEvent = 0;
const int miniftp::Event::kReadEvent = EPOLLIN | EPOLLPRI;
const int miniftp::Event::kWriteEvent = EPOLLOUT;

Event::Event(int fd)
    :   m_fd(fd), m_events(kNoneEvent)
{}

Event::~Event()
{}

void Event::handleEvent()
{
    if(m_revents & (EPOLLERR)) {
        if(m_errorCallBack) m_errorCallBack();
    }

    if(m_revents & (EPOLLIN | EPOLLPRI)) {
        if(m_readCallBack)  m_readCallBack();
    }

    if(m_revents & (EPOLLOUT)) {
        if(m_writeCallBack) m_writeCallBack();
    }
}

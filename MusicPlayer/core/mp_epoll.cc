/**
 *
 *  功能描述：Epoll 函数的封装，管理事件集合
 *  作者    ：LiuYun
 *  邮箱    ：wolf_coming@sina.cn
 *
 */

#include "mp_epoll.h"

using namespace mp;

Epoller::Epoller()
{
    m_event_fd = epoll_create(10);
    if(m_event_fd < 0) {
        handle_error("Epoll_Create Failure.\n");
    }
}

Epoller::~Epoller()
{
    close(m_event_fd);
}

void Epoller::poll()
{
    int ret = epoll_wait(m_event_fd, m_epoll_event, MAX_EVENT_SIZE, -1);
    if(ret < 0) {
        handle_error("Epoll Wait Failure.\n");
    }
    for(int i = 0; i < ret; i++) {
        int fd = m_epoll_event[i].data.fd;
        if(m_epoll_event[i].events & EPOLLIN) {
            Event_cb callback = search_cb(fd);
            u32 rc = callback(fd);
            if(rc == EEVENT) {
                handle_error("Event Callback Failure.\n");
            }
        } else {
            fprintf(stderr, "Something else happened.\n");
            continue;
        }
    }
}

void Epoller::add_event(Event *event)
{
    m_events.push_back(event);

    /*加入事件监听队列*/
    struct epoll_event ev;
    ev.data.fd = event->fd;
    ev.events = EPOLLIN | EPOLLET;
    epoll_ctl(m_event_fd, EPOLL_CTL_ADD, event->fd, &ev);

    /*非阻塞模式*/
    fcntl(event->fd, F_SETFL, fcntl(event->fd, F_GETFL) | O_NONBLOCK);
}

u32 Epoller::remove_event(Event *event)
{
    int rc = ENOFOUND;
    for(EventList::iterator it = m_events.begin(); it != m_events.end(); it ++) {
        if((*it) == event) {
            m_events.erase(it);
            rc = 0;
        }
    }
    return rc;
}

Event_cb Epoller::search_cb(int fd)
{
    for(EventList::iterator it = m_events.begin(); it != m_events.end(); it ++) {
        if((*it)->fd == fd) {
            return (*it)->m_event_cb;
        }
    }
    return NULL;
}

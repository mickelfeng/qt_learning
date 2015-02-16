#include <lib/eventloop.h>

#include <stdio.h>

using namespace miniftp;

EventLoop::EventLoop()
    : m_quit(false), m_pollor(new EPollor)
{
}

EventLoop::~EventLoop()
{}

void EventLoop::loop()
{
    m_quit = false;

    while(! m_quit) {
        m_activeEvents.clear();
        m_pollor->poll(kPollTimeMs, &m_activeEvents);
        for(EventList::iterator it = m_activeEvents.begin(); 
                it != m_activeEvents.end(); it ++) {
            (*it)->handleEvent();
        }
        
        doPendingFunctors();
    }
    
//    fprintf(stdout, "EventLoop %x stop looping\n", this);
}

void EventLoop::quit()
{
    m_quit = true;
}

void EventLoop::updateEvent(Event *ev)
{
    m_pollor->updateEvent(ev);
}

void EventLoop::removeEvent(Event *ev)
{
    m_pollor->removeEvent(ev);
}

void EventLoop::runInLoop(const Functor &cb)
{
    MutexLockGuard lock(m_mutex);
    m_pendingFunctors.push_back(cb);
}

void EventLoop::doPendingFunctors()
{
    std::vector<Functor> functors;

    {
        MutexLockGuard lock(m_mutex);
        functors.swap(m_pendingFunctors);
    }

    for(int i = 0; i < functors.size(); i ++) {
        functors[i]();
    }
}

#include <lib/process.h>
#include <log.h>

#include <signal.h>
#include <boost/bind.hpp>

using namespace miniftp;

Process::Process(const ProcessFunc& func)
    :   m_started(false),
        m_func(func)
{}

Process::~Process()
{}

void Process::start()
{
    assert(! m_started);
    m_started = true;

    signal(SIGCHLD, SIG_IGN);
    if(fork() == 0) {
        m_func();
        exit(0);
    }
}

#include <net/workerprocess.h>
#include <boost/bind.hpp>
#include <lib/eventloop.h>
#include <net/worker.h>

using namespace miniftp;

WorkerProcess::WorkerProcess(int fd, const InetAddress& peerAddr)
    :   m_process(boost::bind(&WorkerProcess::processFunc, this)),
        m_fd(fd),
        m_peerAddr(peerAddr)
{
    m_process.start();
}

void WorkerProcess::processFunc()
{
    EventLoop loop;
    Worker worker(&loop, m_fd, m_peerAddr);
    loop.loop();
}

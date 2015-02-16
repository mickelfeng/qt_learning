#ifndef _WORKER_PROCESS_H_
#define _WORKER_PROCESS_H_

#include <boost/noncopyable.hpp>
#include <net/inetaddress.h>
#include <lib/process.h>

namespace miniftp
{

class WorkerProcess : boost::noncopyable
{
public:
    WorkerProcess(int fd, const InetAddress& peerAddr);

private:
    Process     m_process;
    const InetAddress   m_peerAddr;
    int         m_fd;

    void processFunc(void);
};

}

#endif

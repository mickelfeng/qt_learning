/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_

#include <thread.h>
#include <locker.h>
#include <list>
#include <vector>
#include <worker.h>
#include <condition.h>

namespace threads_zlib
{

class ThreadPool 
{
public:
    ThreadPool(int thread_num = 2);

    ~ThreadPool();
    
    /**
     *  @func   Add Request into work queue 
     */
    void append(WorkerPtr request);

private:
    void worker();

private:
    int     m_threadnum;

    /**
     *  @value  work queue 
     */ 
    std::list<WorkerPtr>  m_workqueue;

    /**
     *  Locker for full WorkQueue 
     */
    MutexLock   m_mutex;

    Condition   m_cond;

    /**
     *  @value  stop threads 
     */
    bool    m_stop;

    /**
     *  @value  threads
     */
    std::vector<ThreadPtr>  m_threads;
};

}

#endif

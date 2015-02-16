/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#include <thread_pool.h>

#ifdef  HAVE_CPP11
    #include <memory>
#else
    #include <boost/bind.hpp>
#endif

#ifdef  DEBUG
    #include <stdio.h>
#endif

using namespace threads_zlib;

ThreadPool::ThreadPool(int thread_num)
    :   m_threadnum(thread_num),
        m_stop(false)
{
    for(int i = 0; i < thread_num ; ++ i ) {
#ifdef  HAVE_CPP11
        m_threads.push_back(ThreadPtr(new Thread(std::bind(&ThreadPool::worker, this), "Worker Thread")));      /* new thread and run */
#else 
        m_threads.push_back(ThreadPtr(new Thread(boost::bind(&ThreadPool::worker, this), "Worker Thread")));      /* new thread and run */
#endif
    }
}

ThreadPool::~ThreadPool()
{
    m_stop = true;
}

void ThreadPool::worker()
{
    WorkerPtr request;
    while(! m_stop) { 
        {
            MutexLockGuard lock(m_mutex);
            if(m_workqueue.empty()) {
                m_cond.wait();
            }
            request = m_workqueue.front();
            m_workqueue.pop_front();
        }
#ifdef DEBUG
        printf("获取到一个任务，处理一个任务\n");
#endif
        request->process();        /* run request function */
    }
}

void ThreadPool::append(WorkerPtr request) 
{
    m_workqueue.push_back(request);
    m_cond.notify();
}

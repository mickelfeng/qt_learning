/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#include <thread.h>

using namespace threads_zlib;

Thread::Thread(const ThreadFunc& func, const std::string &threadname)
    :   m_func(func),
        m_threadname(threadname)
{
    pthread_create(&m_tid, NULL, thread_callback, this);
}

void Thread::join()
{
    pthread_join(m_tid, NULL);
}

void *Thread::thread_callback(void *arg)
{
    Thread * thread = (Thread *) arg;
    thread->runFunc();
    return NULL;
}

void Thread::runFunc()
{
    if(m_func != NULL)  m_func();
}

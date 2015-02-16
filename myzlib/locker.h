/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#ifndef _LOCKER_H_
#define _LOCKER_H_

#include <pthread.h>

namespace threads_zlib
{

class MutexLock
{
public:
    MutexLock()
    {
        pthread_mutex_init( &m_mutex, NULL);
    }
    
    ~MutexLock()
    {
        pthread_mutex_destroy(&m_mutex);
    }

    bool lock()
    {
        return pthread_mutex_lock(&m_mutex) == 0;
    }

    bool unlock()
    {
        return pthread_mutex_unlock(&m_mutex) == 0;
    }

    pthread_mutex_t * getPthreadMutex()
    {
        return &m_mutex;
    }

private:
    pthread_mutex_t m_mutex;

};

class MutexLockGuard
{
public:
    explicit MutexLockGuard(MutexLock &mutexlock)
        :   m_mutexlock(mutexlock)
    {
        m_mutexlock.lock();
    }

    ~MutexLockGuard()
    {
        m_mutexlock.unlock();
    }

private:
    MutexLock &m_mutexlock;
};

}

#endif

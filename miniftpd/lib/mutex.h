#ifndef _MUTEX_H_
#define _MUTEX_H_ 

#include <boost/noncopyable.hpp>
#include <pthread.h>
#include <assert.h>

namespace miniftp {

class MutexLock : boost::noncopyable
{
public:
    MutexLock()
    {
        int ret = pthread_mutex_init(&m_mutex, NULL);
        assert(ret == 0);
    }   

    ~MutexLock()
    {
        int ret = pthread_mutex_destroy(&m_mutex);
        assert(ret == 0);
    }

    void lock()
    {
        pthread_mutex_lock(&m_mutex);
    }

    void unlock()
    {
        pthread_mutex_unlock(&m_mutex);
    }

    pthread_mutex_t *getPthreadMutex()
    {
        return &m_mutex;
    }

private:
    pthread_mutex_t m_mutex;
};

class MutexLockGuard    :   boost::noncopyable
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

#define MutexLockGuard(x)   error   "Missing guard object name"

};

#endif

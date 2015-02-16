/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#ifndef _CONDITION_H_
#define _CONDITION_H_

namespace threads_zlib
{

class Condition
{
public:
    explicit Condition()
    {
        pthread_cond_init(&m_cond, NULL);
    }

    ~Condition()
    {
        pthread_cond_destroy(&m_cond);
    }

    void wait()
    {
        pthread_cond_wait(&m_cond, m_mutex.getPthreadMutex());
    }

    void notify()
    {
        pthread_cond_signal(&m_cond);
    }

    void notifyAll()
    {
        pthread_cond_broadcast(&m_cond);
    }

private:
    MutexLock m_mutex;

    pthread_cond_t m_cond;
};

}

#endif
